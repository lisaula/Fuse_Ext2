#define uint8 short short int
#define uint16 unsigned short int
#define uint32 unsigned int
//Flags option for the inodes
#define EXT2_SECRM_FL 0x0001
#define EXT2_UNRM_FL 0x0002
#define EXT2_COMPR_FL 0x0004
#define EXT2_SYNC_FL 0x0008

//length of the name in a dir_entry
#define EXT2_NAME_LEN 256

//Times are measured in seconds since 00:00:00 GMT, January 1, 1970.
struct ext2_super_block {
  uint32  s_inodes_count;
  uint32  s_blocks_count;
  uint32  s_r_blocks_count;
  uint32  s_free_blocks_count;
  uint32  s_free_inodes_count;
  uint32  s_first_data_block;
  uint32  s_log_block_size;
  int     s_log_frag_size;
  uint32  s_blocks_per_group;
  uint32  s_frags_per_group;
  uint32  s_inodes_per_group;
  uint32  s_mtime;
  uint32  s_wtime;
  uint16 s_mnt_count;
  short int s_max_mnt_count;
  uint16 s_magic;
  uint16 s_state;
  uint16 s_errors;
  uint16 s_pad;
  uint32  s_lastcheck;
  uint32  s_checkinterval;
  uint32  s_reserved[238];
};

struct s_superblock{
	uint32 s_inodes_count;
	uint32 s_blocks_count;
	uint32 s_r_blocks_count;
	uint32 s_free_block_count;
	uint32 s_free_inodes_count;
	uint32 s_first_data_block;
	uint32 s_log_block_size;
	int s_log_frag_size;
	uint32 s_blocks_per_group;
	uint32 s_flags_per_group;
	uint32 s_inodes_per_group;
	uint32 s_mtime;
	uint32 s_wtime;
	uint16 s_mnt_count;
	uint16 s_max_mnt_count;
	uint16 s_magic;
	uint16 s_state;
	uint16 s_errors;
	uint16 s_minor_rev_level; //?
	uint32 s_lastcheck;
	uint32 s_checkinterval;
	uint32 s_creator_os;
	uint32 s_rev_level;
	uint16 s_def_resuid;
	uint16 s_def_resgid;
	uint32 s_firts_inode;
	uint16 s_inode_size;
};

struct ext2_group_desc
{
  uint32  bg_block_bitmap;
  uint32  bg_inode_bitmap;
  uint32  bg_inode_table;
  uint16 bg_free_blocks_count;
  uint16 bg_free_inodes_count;
  uint16 bg_used_dirs_count;
  uint16 bg_pad;
  uint32  bg_reserved[3];
};

#define EXT2_N_BLOCKS 15 //Blocks pointers in EXT2 0.5
struct ext2_inode {
  uint16 i_mode;
  uint16 i_uid;
  uint32  i_size;
  uint32  i_atime;
  uint32  i_ctime;
  uint32  i_mtime;
  uint32  i_dtime;
  uint16 i_gid;
  uint16 i_links_count;
  uint32  i_blocks;
  uint32  i_flags;
  uint32  i_reserved1;
  uint32  i_block[EXT2_N_BLOCKS];
  uint32  i_version;
  uint32  i_file_acl;
  uint32  i_dir_acl;
  uint32  i_faddr;
  unsigned char  i_frag;
  unsigned char  i_fsize;
  uint16 i_pad1;
  uint32  i_reserved2[2];
};

struct ext2_dir_entry {
  uint32  inode;
  uint16 rec_len;
  unsigned char name_len;
  unsigned char file_type;
  char name[EXT2_NAME_LEN];
};
