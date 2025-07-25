#include "cn_pool.h"
#include "cn_pool_internal.h"

void cn_init_pool(cn_mpool_t* mpool){
    int i;
    for(i=0; i<CN_NUM_BLOCKS; ++i){
        mpool->nblocks[i] = true; //make all blocks accessible
    }
    memset(mpool->rbytes, 0, CN_POOL_SIZE);
}

void* cn_allocate_pool(cn_mpool_t* mpool){
    int i =0;
    size_t bsize = CN_POOL_SIZE/CN_NUM_BLOCKS;

    for(i=0; i<CN_NUM_BLOCKS; ++i){
        if(mpool->nblocks[i]){
            mpool->nblocks[i] = false;
            return &mpool->rbytes[i*bsize];
        }
    }

    return (char *)0;
}

void cn_release_pool(cn_mpool_t* mpool, void* mem_ptr){

}