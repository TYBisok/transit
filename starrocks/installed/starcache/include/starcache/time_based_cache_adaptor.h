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

namespace starcache {

class CacheAdaptor {
public:
    virtual bool check_read_cache() = 0;
};

class LatencyWindow;

class TimeBasedCacheAdaptor : public CacheAdaptor {
public:
    TimeBasedCacheAdaptor(double skip_read_factor, int64_t min_disk_latency_us);
    ~TimeBasedCacheAdaptor();

    void record_read_cache(size_t bytes, int64_t latency_us);

    void record_read_remote(size_t bytes, int64_t latency_us);

    bool check_read_cache() override;

private:
    LatencyWindow* _read_cache_window = nullptr;
    LatencyWindow* _read_remote_window = nullptr;
    int64_t _skip_read_factor = 0;
    int64_t _min_disk_latency_us = 0;
};

inline TimeBasedCacheAdaptor* create_default_adaptor(double skip_read_factor = 1.0,
                                                     int64_t min_disk_latency_us = 5000) {
    return new TimeBasedCacheAdaptor(skip_read_factor, min_disk_latency_us);
}

} // namespace starcache
