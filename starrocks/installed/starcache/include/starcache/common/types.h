// Copyright 2021-present StarRocks, Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <butil/iobuf.h>
#include <butil/status.h>

#include <atomic>
#include <functional>

namespace starcache {

using Status = butil::Status;
using IOBuf = butil::IOBuf;
using CacheId = uint64_t;
using CacheKey = std::string;
using DeleterFunc = std::function<void()>;
using CallBackFunc = std::function<void(int, const std::string&)>;

constexpr size_t KB = 1024;
constexpr size_t MB = KB * 1024;
constexpr size_t GB = MB * 1024;

struct BlockId {
    uint8_t dir_index;
    uint32_t block_index;
    int64_t file_version;
};

struct BlockKey {
    CacheId cache_id;
    uint32_t block_index;
};

struct DirSpace {
    std::string path;
    size_t quota_bytes;
};

class CacheAdaptor;

enum DurabilityType {
    NONE = 0,
    ROCKSDB = 1,
};

struct CacheOptions {
    // Cache Space (Required)
    size_t mem_quota_bytes = 0;
    std::vector<DirSpace> disk_dir_spaces;

    // Custom Parameters (Optional)
    // If not set, the default value will be used.

    // The size of block, which is the basic unit of cache management.
    size_t block_size = 1 * MB;
    // The size of slice, which is the minimum read unit.
    size_t slice_size = 64 * KB;
    // The size of disk block file, which cache a batch of blocks in a disk file.
    size_t block_file_size = 10 * GB;

    // Whether to pre-allocate the the block file to the target size.
    bool pre_allocate_block_file = false;
    // Whether to do checksum to check the data correctness read from disk.
    bool enable_disk_checksum = false;
    // Whether to enable os page cache, if not, the disk data will be processed in direct io mode.
    bool enable_os_page_cache = false;

    // The maximum concurrent write count, to avoid too many writes that affect write latency.
    size_t max_concurrent_writes = 1500000;

    // The probability to promote the disk cache data to memory.
    // If the value is -1, it will be set automatically according some related options, and
    // the maximum and minimum value only be used in this case.
    int32_t promotion_probalility = -1;
    int32_t max_promotion_probility = 10;
    int32_t min_promotion_probility = 1;

    // The probability to touch memory block item.
    // If the value is -1, it will be set automatically according some related options, and
    // the maximum and minimum value only be used in this case.
    uint32_t evict_touch_mem_probalility = -1;
    int32_t max_evict_touch_mem_probalility = 10;
    int32_t min_evict_touch_mem_probalility = 1;

    // The probability to touch disk cache item.
    // If the value is -1, it will be set automatically according some related options, and
    // the maximum and minimum value only be used in this case.
    uint32_t evict_touch_disk_probalility = -1;
    int32_t max_evict_touch_disk_probalility = 10;
    int32_t min_evict_touch_disk_probalility = 1;

    // The max object size that need to be checked by size based admission policy
    size_t admission_max_check_size = 64 * KB;
    // The probability to flush the small block to disk when evict
    double admission_flush_probability = 1.0;
    // The probability to delete the small block directly when evict
    double admission_delete_probability = 1.0;

    // The times of target size that need to be evicted in an memery eviction
    uint32_t mem_evict_times = 2;
    // The times of target size that need to be evicted in a disk eviction
    uint32_t disk_evict_times = 2;
    // The eviction batch size when evict memory for new quota bytes in multiple eviction
    size_t evict_batch_for_mem_quota = 30 * MB;
    // The eviction batch size when evict disk for new quota bytes in multiple eviction
    size_t evict_batch_for_disk_quota = 50 * MB;

    // The threshold under which the memory allocation is allowed, expressed as a percentage
    size_t alloc_mem_threshold = 90;
    // The threshold under which the promotion is allowed, expressed as a percentage
    size_t promotion_mem_threshold = 80;

    // The maximum retry count when allocate segment or block failed
    size_t max_retry_when_allocate = 10;

    // The shard bits of access index hashmap, default is 32 shards.
    uint32_t access_index_shard_bits = 5;
    // The shard bits of sharded lock manager, default is 4096 shards.
    uint32_t sharded_lock_shard_bits = 12;
    // The shard bits of lru container, default is 32 shards.
    uint32_t lru_container_shard_bits = 5;

    // The unit size for direct io alignment.
    // NOTICE: It's best to set this parameter to the size of the cache disk sector.
    // The sector size can be get by `sudo blockdev --getss {device}`, such as `sudo blockdev --getss /dev/vda1`.
    // Although we also can get it by `ioctl`, but it always need root permisson.
    // The default value (4096) can always work normally, but sometimes, especially if the sector size small than 4096,
    // the performance is not the best.
    size_t io_align_unit = 4 * KB;

    // The thread num of sheculer thread pool for each cpu. It is double type and can be less 1.
    double scheduler_thread_ratio_per_cpu = 1.0;
    // Total memory limit for in-flight.
    // Once this is reached, new scheduler job will be rejected until the parcel memory usage gets under the limit.
    // If it is 0, the in-flight for each worker will not exceed one block size.
    uint32_t max_flying_memory_mb = 256;

    // The factor that affect the skip threshold for reading.
    // [Deprecated]
    int32_t adaptor_skip_read_factor = 1;
    // The adaptor which can be used to deny some io request according current status.
    CacheAdaptor* cache_adaptor = nullptr;

    /* durability option start */
    DurabilityType durability_type = DurabilityType::NONE;
    // if cache value size <= cache_value_inline_size_threshold, value will be stored together with meta
    uint32_t cache_value_inline_size_threshold = 1024;
    // turn on for test
    bool verify_checksum_when_start = false;
    // load meta in other threads when initialize
    bool async_meta_load = true;
    /* durability option end */

    // Cache instance name, used to distinguish metric infomation of different cache instances.
    std::string instance_name = "default_cache";
    // Brpc dummy server port, used to monitor the metrics information.
    // If it is zero, we will not start a new brpc dummy server.
    // Usually, if the brpc port has been started in the upper-layer application, we can keep this parameter as 0.
    int32_t brpc_dummy_port = 0;

    // The interval for ttl reaper to check the expired cache item.
    // If set to 0, the ttl reaper will not start.
    uint32_t ttl_check_interval_ms = 0;
    // The cache item count for ttl reaper to remove in each cycle.
    uint32_t ttl_remove_batch = 100;

    // Policy (Optional)
    /*
    EvictPolicy mem_evict_policy;
    EvictPolicy disk_evict_policy;
    AdmissionCtrlPolicy admission_ctrl_policy;
    PromotionPolicy promotion_policy;
    */
};

enum class CacheStatus : uint8_t { NORMAL, UPDATING, ABNORMAL, LOADING };

struct CacheMetrics {
    struct Level1Detail {
        size_t hit_bytes = 0;
        size_t miss_bytes = 0;
        size_t hit_count = 0;
        size_t miss_count = 0;
    };
    struct Level2Detail {
        size_t hit_bytes_last_minite = 0;
        size_t miss_bytes_last_minite = 0;
        size_t hit_count_last_minite = 0;
        size_t miss_count_last_minite = 0;

        size_t buffer_item_count = 0;
        size_t buffer_item_bytes = 0;
        size_t object_item_count = 0;
        size_t object_item_bytes = 0;

        size_t read_mem_bytes = 0;
        size_t read_disk_bytes = 0;

        size_t write_bytes = 0;
        size_t write_success_count = 0;
        size_t write_fail_count = 0;

        size_t remove_bytes = 0;
        size_t remove_success_count = 0;
        size_t remove_fail_count = 0;

        size_t current_reading_count = 0;
        size_t current_writing_count = 0;
        size_t current_removing_count = 0;

        std::unordered_map<int, size_t> prior_item_counts;
        std::unordered_map<int, size_t> prior_item_bytes;
    };

    // Level 0
    CacheStatus status;
    size_t mem_quota_bytes;
    size_t mem_used_bytes;
    size_t disk_quota_bytes;
    size_t disk_used_bytes;
    std::vector<DirSpace> disk_dir_spaces;
    size_t meta_used_bytes = 0;

    // Detail
    std::shared_ptr<Level1Detail> detail_l1;
    std::shared_ptr<Level2Detail> detail_l2;
};

constexpr int8_t kMinCachePriority = 0;
constexpr int8_t kMaxCachePriority = 1;
constexpr uint32_t kMaxEvictProbability = 100;

struct WriteOptions {
    enum class WriteMode {
        // Write according the starcache promotion policy.
        WRITE_BACK,
        // Write to disk directly.
        WRITE_THROUGH
    };
    // If ttl_seconds=0 (default), no ttl restriction will be set. If an old one exists, remove it.
    uint64_t ttl_seconds = 0;
    // Only support 0 and 1 currently.
    int8_t priority = 0;
    // If pinned=true, the starcache guarantees the atomicity of write and pin operations.
    bool pinned = false;
    // If overwrite=true, the cache value will be replaced if it already exists.
    bool overwrite = true;
    // Whether write data in asynchronous mode.
    bool async = false;
    // Whether the data to be write will not be free until the write finish.
    // This option only used in asynchronous mode.
    bool keep_alive = false;
    // The callback function for asynchronous write, once the write is finished, this function will be called.
    // The parameters are error code and error message.
    // This option only used in asynchronous mode.
    CallBackFunc callback = nullptr;

    WriteMode mode = WriteMode::WRITE_BACK;
    // The probability to evict other items if the cache space is full, which can help reducing cache replacement rate
    // and improve cache hit rate sometimes.
    // It is expressed as a percentage. If evict_probability is 10, it means the probability to evict other data is 10%.
    // The default value(100) keeps a strict LRU semantics.
    int32_t evict_probability = kMaxEvictProbability;

    // Output, store the statistics information about this write.
    struct WriteStats {
        size_t write_mem_bytes = 0;
        size_t write_disk_bytes = 0;
    } stats;
};

struct ReadOptions {
    enum class ReadMode {
        // Read according the starcache promotion policy.
        READ_BACK,
        // Skip promoting the data read from disk.
        READ_THROUGH
    };
    ReadMode mode = ReadMode::READ_BACK;

    // If true, the EBUSY will be returned if the disk is too busy.
    bool use_adaptor = false;

    // Output, store the statistics information about this read.
    struct ReadStats {
        size_t read_mem_bytes = 0;
        size_t read_disk_bytes = 0;
    } stats;
};

inline std::ostream& operator<<(std::ostream& os, const BlockKey& block_key) {
    os << block_key.cache_id << "_" << block_key.block_index;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const WriteOptions::WriteMode& mode) {
    switch (mode) {
    case WriteOptions::WriteMode::WRITE_BACK:
        os << "write_back";
        break;
    case WriteOptions::WriteMode::WRITE_THROUGH:
        os << "write_through";
        break;
    }
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const ReadOptions::ReadMode& mode) {
    switch (mode) {
    case ReadOptions::ReadMode::READ_BACK:
        os << "read_back";
        break;
    case ReadOptions::ReadMode::READ_THROUGH:
        os << "read_through";
        break;
    }
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const WriteOptions& options) {
    os << "{ ttl_seconds: " << options.ttl_seconds << ", pinned: " << options.pinned
       << ", overwrite: " << options.overwrite << ", mode: " << options.mode << " }";
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const ReadOptions& options) {
    os << "{ mode: " << options.mode << " }";
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const CacheStatus& status) {
    switch (status) {
    case CacheStatus::NORMAL:
        os << "normal";
        break;
    case CacheStatus::UPDATING:
        os << "updating";
        break;
    case CacheStatus::ABNORMAL:
        os << "abnormal";
        break;
    case CacheStatus::LOADING:
        os << "loading";
        break;
    }
    return os;
}

} // namespace starcache
