#include "../include/cn_pool.h"
#include "../include/cn_pool_internal.h"

int main(int argc, char** argv){
    cn_mpool_t mpool;
    char* test_name = "Hurray!";

    typedef struct test_struct{
        char name[10];
        int age;

    }test_struct;

    cn_init_pool(&mpool);
    if(!mpool.nblocks[0]) {return 1;}
    test_struct *ts = (test_struct*) cn_allocate_pool(&mpool);
    if(mpool.nblocks[0]) {return 1;}

    strcpy(ts->name, test_name);
    ts->age = 21;
    if(ts->name[0] != 'H' && ts->age !=21){return 1;}

    cn_release_pool(&mpool, ts);
    if(!mpool.nblocks[0]) {return 1;} //check whether the block is released
    if(ts->name[0] != 0 && ts->age == 0){return 1;} //check whether each block is initialized to zero

    //now allocate again but this time try to move a pointer a bit from its position
    ts = (test_struct *) cn_allocate_pool(&mpool);
    if(mpool.nblocks[0]) {return 1;}
    ts->age =20;
    strcpy(ts->name, test_name);

    ++ts;
    if(ts->age != 0){return 1;}
    ts->age = 20;

    cn_release_pool(&mpool, (void* )ts);
    if(!mpool.nblocks[0]){return 1;} //test if the block is released

    //all test passed!
    return 0;
}