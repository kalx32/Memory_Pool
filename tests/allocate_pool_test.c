#include "../include/cn_pool.h"
#include "../include/cn_pool_internal.h"

int main(int argc, char** argv){
    cn_mpool_t mpool1;
    size_t block_size = CN_POOL_SIZE/CN_NUM_BLOCKS;
    char* test_buf[CN_NUM_BLOCKS];
    char* buf1;
    char* buf2;

    //initializing the Memory Pool
    cn_init_pool(&mpool1);
    buf1 = (char*) cn_allocate_pool(&mpool1); //allocate the first block

    if(buf1 == (char *) 0 && mpool1.nblocks[0]){return 1;} //Memory allocated successfully? is the first block removed from the list?
    if(buf1 != (char*)mpool1.rbytes) {return 1;} //the pointer to the released block points to the address of the block?

    //testing the second block
    if(!mpool1.nblocks[1]){return 1;} //the second block available?
    buf2 =(char*) cn_allocate_pool(&mpool1);
    if(buf2 != (char*) &mpool1.rbytes[block_size] &&mpool1.nblocks[1]){return 1;}

    /*
        Two regions are already allocated!
        The pool should remain with only CN_NUM_BLOCKS-2 allocatable regions
        The next test is to check whether the pool can still allocate when there is no region left
    */

    int i;
    for(i=0; i<CN_NUM_BLOCKS;++i){
        test_buf[i] = cn_allocate_pool(&mpool1);
    }
    if(test_buf[CN_NUM_BLOCKS - 1U] != (char*)0 && test_buf[CN_NUM_BLOCKS - 2U]!=(char*)0){return 1;} //No memory left, shouldn't pass this test
    for(i =0; i<CN_NUM_BLOCKS;++i){
        if(mpool1.nblocks[i]){return 1;}
    }

    //checking for other available regions
    if(test_buf[CN_NUM_BLOCKS - 3U] ==(char*) 0){return 1;}

    //All test pass
    return 0;
}