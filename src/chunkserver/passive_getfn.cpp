/*
 * Project: curve
 * Created Date: Tuesday June 18th 2019
 * Author: yangyaokai
 * Copyright (c) 2019 netease
 */

#include "src/chunkserver/passive_getfn.h"

#include <memory>
#include <vector>

namespace curve {
namespace chunkserver {

uint32_t getCopysetCountFunc(void* arg) {
    /* CopysetNodeManager* nodeMgr = reinterpret_cast<CopysetNodeManager*>(arg);
    uint32_t copysetCount = 0;
    if (nodeMgr != nullptr) {
        std::vector<std::shared_ptr<CopysetNode>> nodes;
        nodeMgr->GetAllCopysetNodes(&nodes);
        copysetCount = nodes.size();
    }
    return copysetCount;*/
    // fix(yyk) 目前这里会出现死锁，后续需要修复
    return 0;
}

uint32_t getLeaderCountFunc(void* arg) {
   /*   CopysetNodeManager* nodeMgr = reinterpret_cast<CopysetNodeManager*>(arg);
    uint32_t leaderCount = 0;
    if (nodeMgr != nullptr) {
        std::vector<std::shared_ptr<CopysetNode>> nodes;
        nodeMgr->GetAllCopysetNodes(&nodes);
        // 统计leader的数量
        for (auto& node : nodes) {
            if (node->IsLeader()) {
                ++leaderCount;
            }
        }
    }
    */
    return 0;
}

uint32_t getChunkLeftFunc(void* arg) {
    ChunkfilePool* chunkfilePool = reinterpret_cast<ChunkfilePool*>(arg);
    uint32_t chunkLeft = 0;
    if (chunkfilePool != nullptr) {
        ChunkFilePoolState poolState = chunkfilePool->GetState();
        chunkLeft = poolState.preallocatedChunksLeft;
    }
    return chunkLeft;
}

uint32_t getDatastoreChunkCountFunc(void* arg) {
    CSDataStore* dataStore = reinterpret_cast<CSDataStore*>(arg);
    uint32_t chunkCount = 0;
    if (dataStore != nullptr) {
        DataStoreStatus status = dataStore->GetStatus();
        chunkCount = status.chunkFileCount;
    }
    return chunkCount;
}

uint32_t getDatastoreSnapshotCountFunc(void* arg) {
    CSDataStore* dataStore = reinterpret_cast<CSDataStore*>(arg);
    uint32_t snapshotCount = 0;
    if (dataStore != nullptr) {
        DataStoreStatus status = dataStore->GetStatus();
        snapshotCount = status.snapshotCount;
    }
    return snapshotCount;
}

}  // namespace chunkserver
}  // namespace curve