#include "sfs.h"

int sfs_getattr(const char *path, struct stat *statbuf){
	printf("get attr path: %s\n", path);

	int res = 0;

	memset(statbuf, 0, sizeof(struct stat));
	if (strcmp(path, "/") == 0) {
		statbuf->st_mode = S_IFDIR | 0755;
		statbuf->st_nlink = 2;
	} else if (strcmp(path+1, "test") == 0) {
		statbuf->st_mode = S_IFREG | 0444;
		statbuf->st_nlink = 1;
		statbuf->st_size = strlen("content");
	} else if (strcmp(path+1, "test2") == 0) {
		statbuf->st_mode = S_IFREG | 0444;
		statbuf->st_nlink = 1;
		statbuf->st_size = strlen("contenido");
	} else
	res = -ENOENT;

	return res;
}

int sfs_readlink(const char *path, char *link, size_t size){
	printf("readlink\n");
	return -1;
}

int sfs_mknod(const char *path, mode_t mode, dev_t dev){
	printf("mknod\n");
	return -1;
}

int sfs_mkdir(const char *path, mode_t mode){
	printf("mkdir\n");
	return -1;
}

int sfs_unlink(const char *path){
	printf("unlink\n");
	return -1;
}

int sfs_rmdir(const char *path){
	printf("rmdir\n");
	return -1;
}

int sfs_symlink(const char *path, const char *link){
	printf("symlink\n");
	return -1;
}

int sfs_rename(const char *path, const char *newpath){
	printf("rename\n");
	return -1;
}

int sfs_link(const char *path, const char *newpath){
	printf("link\n");
	return -1;
}

int sfs_chmod(const char *path, mode_t mode){
	printf("chmod\n");
	return -1;
}

int sfs_chown(const char *path, uid_t uid, gid_t gid){
	printf("chown\n");
	return -1;
}

int sfs_truncate(const char *path, off_t newSize){
	printf("truncate\n");
	return -1;
}

int sfs_utime(const char *path, struct utimbuf *ubuf){
	printf("utime\n");
	return -1;
}

int sfs_open(const char *path, struct fuse_file_info *fileInfo){
	printf("open\n");
	return 0;
}

int sfs_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fileInfo){
	printf("read\n");

	size_t len;
	(void) fileInfo;

	if(strcmp(path+1, "test") == 0){

		len = strlen("content");
		if (offset < len) {
			if (offset + size > len)
				size = len - offset;
			memcpy(buf, "content" + offset, size);
		} else
		size = 0;
	} else if(strcmp(path+1, "test2") == 0){

		len = strlen("contenido");
		if (offset < len) {
			if (offset + size > len)
				size = len - offset;
			memcpy(buf, "contenido" + offset, size);
		} else
		size = 0;
	}
	return size;
}

int sfs_write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fileInfo){
	printf("write\n");
	return -1;
}

int sfs_statfs(const char *path, struct statvfs *statInfo){
	printf("statfs\n");
	return -1;
}

int sfs_flush(const char *path, struct fuse_file_info *fileInfo){
	printf("flush\n");
	return -1;
}

int sfs_release(const char *path, struct fuse_file_info *fileInfo){
	printf("release\n");
	return -1;
}

int sfs_fsync(const char *path, int datasync, struct fuse_file_info *fi){
	printf("fsync\n");
	return -1;
}

int sfs_opendir(const char *path, struct fuse_file_info *fileInfo){
	printf("opendir\n");
	return -1;
}

int sfs_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fileInfo){
	printf("readdir\n");
	printf("path %s\n",path );
	if (strcmp(path, "/") != 0)
		return -ENOENT;

	filler(buf, ".", NULL, 0);
	filler(buf, "..", NULL, 0);
	filler(buf, "test", NULL, 0);
	filler(buf, "test2", NULL, 0);
	return 0;
}

int sfs_releasedir(const char *path, struct fuse_file_info *fileInfo){
	printf("releasedir\n");
	return -1;
}

int sfs_fsyncdir(const char *path, int datasync, struct fuse_file_info *fileInfo){
	printf("fsyncdir\n");
	return -1;
}

int sfs_getdir(const char *path){
	printf("getdir\n");
	return -1;
}

void sfs_init(struct fuse_conn_info *conn){
	printf("init\n");
}
