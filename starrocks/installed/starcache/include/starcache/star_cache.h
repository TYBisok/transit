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

#include "common/types.h"
#include "obj_handle.h"

namespace starcache {

class StarCacheImpl;
class StarCache {
public:
    StarCache();
    ~StarCache();

    // Init the starcache instance with given options
    Status init(const CacheOptions& options);

    // Get the starcache options
    const CacheOptions* options();

    // Set the whole cache object.
    // If the `cache_key` exists:
    // - if overwrite=true, replace the cache data.
    // - if overwrite=false, return EEXIST.
    // If the `ttl_seconds` is 0 (default), no ttl restriction will be set.
    Status set(const CacheKey& cache_key, const IOBuf& buf, WriteOptions* options = nullptr);

    // Set the cache object pointer.
    // The `handle` will return the object if success.
    // As the pointer will become invalid once process restart, so we only cache it in memory
    Status set_object(const CacheKey& cache_key, const void* ptr, size_t size, DeleterFunc deleter,
                      ObjectHandle* handle, WriteOptions* options = nullptr);

    // Get the whole cache object.
    // If no such object, return ENOENT error
    Status get(const CacheKey& cache_key, IOBuf* buf, ReadOptions* options = nullptr);

    // Get the cache object pointer.
    // To manage the pointer lifecycle, we wrap the pointer with a handle structure.
    // As long as the handle object is not destroyed and the user does not explicitly call the release function,
    // the corresponding pointer will not be freed by the cache system.
    Status get_object(const CacheKey& cache_key, ObjectHandle* handle, ReadOptions* options = nullptr);

    // Read the partial cache object with given range.
    // If the range exceeds the object size, only read the range within the object size.
    // Only if all the data in the valid range exists in the cache will it return success, otherwise will return ENOENT.
    Status read(const CacheKey& cache_key, off_t offset, size_t size, IOBuf* buf, ReadOptions* options = nullptr);

    // Read the partial cache object with given range to a raw buffer.
    // If the range exceeds the object size, only read the range within the object size.
    // Only if all the data in the valid range exists in the cache will it return success, otherwise will return ENOENT.
    //
    // NOTICE: This function is just a temporary optimization for a specific scene, it is not universal in use,
    // and will be deleted later.
    Status read(const CacheKey& cache_key, off_t offset, size_t size, char* data, ReadOptions* options = nullptr);

    // Check if cache exists
    bool exist(const CacheKey& cache_key);

    // Remove the cache object.
    // If no such object, return ENOENT error
    Status remove(const CacheKey& cache_key);

    // Pin the cache object in cache.  The cache object will not be evicted by eviction policy.
    // The object still can be removed in the cases:
    // 1. calling remove api
    // 2. the ttl is timeout
    Status pin(const CacheKey& cache_key);

    // UnPin the cache object in cache.
    // If the object is not exist or has been removed, return ENOENT error.
    Status unpin(const CacheKey& cache_key);

    // Update the memory cache quota.
    // If `flush_to_disk=true`, the evicted memory cache items will try to flush to disk.
    // Otherwise, the evicted memory cache item will be delete directly.
    Status update_mem_quota(size_t quota_bytes, bool flush_to_disk);

    // Update the disk cache spaces
    Status update_disk_spaces(const std::vector<DirSpace>& dir_spaces);

    // Get the starcache metrics.
    // The `level` can be 0, 1, 2. The larger this parameter, the more detailed metrics returned.
    CacheMetrics metrics(int level = 0);

    void join();

private:
    StarCacheImpl* _cache_impl = nullptr;
};

} // namespace starcache
