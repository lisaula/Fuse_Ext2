#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "device.h"

#define BASE_OFFSET 1024  /* location of the super-block in the first group */

#define BLOCK_OFFSET(block) (BASE_OFFSET + (block-1)*block_size)

static const char *device_path;
static FILE *f;

int readSB(const char *path){
	printf("path %s and %s\n",device_path,path );
	int fd = open(path, O_RDONLY);
	char but[1024];

	read(fd, but, 1024);
	read(fd, &es, sizeof(struct ext2_super_block));
	//printf("size of int %d size of int short %d\n",sizeof(int),sizeof(short int) );
	//printf("size of long %d and size of short %d\n",sizeof(long), sizeof(short) );
	//printf("Size of super %d\n", sizeof(struct s_superblock));
	//printf("Magic %d\n", es.s_magic);
	printf("inodes count %u\n", es.s_inodes_count);
	printf("s_blocks_count %u\n", es.s_blocks_count);
	printf("s_r_blocks_count %u\n", es.s_r_blocks_count);
	printf("s_free_block_count %u\n", es.s_free_blocks_count);
	printf("s_free_inodes_count %u\n", es.s_free_inodes_count);
	printf("s_first_data_block %u\n", es.s_first_data_block);
	printf("s_log_block_size %u\n", es.s_log_block_size);
	printf("s_log_frag_size %d\n", es.s_log_frag_size);
	printf("s_blocks_per_group %u\n", es.s_blocks_per_group);
	printf("s_flags_per_group %u\n", es.s_frags_per_group);
	printf("s_inodes_per_group %u\n", es.s_inodes_per_group);
	printf("s_mtime %u\n", es.s_mtime);
	printf("s_wtime %u\n", es.s_wtime);
	printf("s_mnt_count %u\n", es.s_mnt_count);
	printf("s_max_mnt_count %u\n", es.s_max_mnt_count);
	printf("s_magic %u\n", es.s_magic);
	printf("s_state %u\n", es.s_state);
	printf("s_errors %u\n", es.s_errors);
	printf("s_minor_rev_level %u\n", es.s_pad);
	printf("s_lastcheck %u\n", es.s_lastcheck);
	printf("s_checkinterval %u\n", es.s_checkinterval);

	printf("Size of superblock %d\n",sizeof(struct s_superblock));
	printf("Size of superblock2 %d\n",sizeof(struct ext2_super_block));
	size_of_block = 1024 << es.s_log_block_size;
	printf("Size of block %d\n", size_of_block);
	if(es.s_log_frag_size >= 0){
		size_of_fragment = 1024 << es.s_log_frag_size;
	}else{
		size_of_fragment = 1024 >> -es.s_log_frag_size;
	}
	printf("Size of fragment %d\n", size_of_fragment);

	read(fd,&gd,sizeof(struct ext2_group_desc));
	printf("bg_block_bitmap %u\n", gd.bg_block_bitmap);
	printf("bg_inode_bitmap %u\n", gd.bg_inode_bitmap);
	printf("bg_inode_table %u\n", gd.bg_inode_table);
	printf("bg_free_blocks_count %u\n", gd.bg_free_blocks_count);
	printf("bg_free_inodes_count %u\n", gd.bg_free_inodes_count);
	printf("bg_used_dirs_count %u\n", gd.bg_used_dirs_count);
	unsigned int group_count = 1 +(es.s_blocks_count -1)/es.s_blocks_per_group;
	printf("Calculating block groups count %d\n", group_count);
	/* number of inodes per block */
unsigned int inodes_per_block = size_of_block / sizeof(struct ext2_inode);
	printf("Calculating number of inodes per block %d\n",inodes_per_block );
	/* size in blocks of the inode table */
	unsigned int itable_blocks = es.s_inodes_per_group / inodes_per_block;
printf("Calculating number of blocks used by the itable %d\n",itable_blocks );

	int offset = gd.bg_block_bitmap*size_of_block;
	lseek(fd, offset, SEEK_SET);
	char *blocks_bitmap = (char*)malloc(size_of_block);
	read(fd, blocks_bitmap, size_of_block);

	close(fd);
	//int offset = gd.bg_block_bitmap*size_of_block
	//fseek(fd,offset, SEEK_SET)
	//char blocks_bitmap[]
	return es.s_magic == 61267 || es.s_magic ==61265 ? 0 : -1;
}

int device_open(const char *path) {
    device_path = path;
    f = fopen(path, "r+");

    int status = readSB(path);

    return (f != NULL && status == 0);
}

void device_close(){
    fflush(f);
    fclose(f);
}

void device_flush(){
    fflush(f);
}
