// Copyright 2017 Kakao Corp. <http://www.kakaocorp.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <queue>

#include "hnsw_node.h"


namespace n2 {

class FurtherFirst {
public:
    FurtherFirst(HnswNode* node, float distance)
    : node_(node), distance_(distance) {}
    inline float GetDistance() const { return distance_; }
    inline HnswNode* GetNode() const { return node_; }
    bool operator< (const FurtherFirst& n) const {
        return (distance_ < n.GetDistance());
    }
private:
    HnswNode* node_;
    float distance_;
};

class CloserFirst {
public:
    CloserFirst(HnswNode* node, float distance)
    : node_(node), distance_(distance) {}
    inline float GetDistance() const { return distance_; }
    inline HnswNode* GetNode() const { return node_; }
    bool operator< (const CloserFirst& n) const {
        return (distance_ > n.GetDistance());
    }
private:
    HnswNode* node_;
    float distance_;
};

class FurtherFirstNew {
public:
    FurtherFirstNew(int id, float distance)
    : id_(id), distance_(distance) {}
    inline float GetDistance() const { return distance_; }
    inline int GetId() const { return id_; }
    bool operator< (const FurtherFirstNew& n) const {
        return (distance_ < n.GetDistance());
    }
public:
    int id_;
    float distance_;
};

class CloserFirstNew {
public:
    CloserFirstNew(int id, float distance)
    : id_(id), distance_(distance) {}
    inline float GetDistance() const { return distance_; }
    inline int GetId() const { return id_; }
    bool operator< (const CloserFirstNew& n) const {
        return (distance_ > n.GetDistance());
    }
public:
    int id_;
    float distance_;
};

} // namespace n2
