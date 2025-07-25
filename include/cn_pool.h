
#ifndef __CN_POOL_H
#define __CN_POOL_H

//standard c headers
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

//project specific headers
#include "cn_pool_def.h"

typedef struct cn_mpool_t cn_mpool_t;

void cn_init_pool(cn_mpool_t* mpool);
void* cn_allocate_pool(cn_mpool_t* mpool);
void cn_release_pool(cn_mpool_t* mpool, void* mem_ptr);

#endif