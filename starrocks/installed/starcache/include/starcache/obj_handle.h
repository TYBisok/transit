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

#include <functional>
#include <shared_mutex>

namespace starcache {

struct ObjectItem;

class ObjectHandle {
public:
    ObjectHandle() = default;
    ~ObjectHandle();

    const void* ptr();

    size_t size();

    void release();

private:
    friend class StarCacheImpl;

    void _reset(ObjectItem* obj_item, size_t size);

    ObjectItem* _item = nullptr;
    size_t _size = 0;
    bool _released = false;
};

} // namespace starcache
