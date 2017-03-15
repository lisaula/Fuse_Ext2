#ifndef _DEVICE_H_
#define _DEVICE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "structures.h"

static struct ext2_super_block es;
static struct ext2_group_desc gd;
static int size_of_block;
static int size_of_fragment;

int device_open(const char *path);
void device_close();
void device_flush();

#ifdef __cplusplus
}
#endif

#endif
