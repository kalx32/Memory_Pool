#ifndef __CN_POOL_INTERNAL_H
#define __CN_POOL_INTERNAL_H

struct cn_mpool_t {
    uint8_t rbytes[CN_POOL_SIZE] __attribute__((aligned(8)));
    bool nblocks[CN_NUM_BLOCKS];
};

#endif