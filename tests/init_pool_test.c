#include "../include/cn_pool.h"
#include "../include/cn_pool_internal.h"

int main(int argc, char** argv){
    cn_mpool_t mpool;
    int icount, i;
    icount = 0;
    
    //Before initializing, test whether any block is marked true
    if(mpool.nblocks[i]) 
    return 1;

    //Try to initialize and test
    cn_init_pool(&mpool);
    for(i=0; i<CN_NUM_BLOCKS; ++i){
        if(mpool.nblocks[i])
            ++icount;
    }

    if(icount == CN_NUM_BLOCKS)
    return 0;

    return 1;
}