#ifndef _db_h
#define _db_h

// db文件用于记录已经安装的URL从而用来检查一些程序是否已经安装以便跳过

#define DB_FILE "/usr/local/.devpkg/db"
#define DB_DIR "/usr/local/.devpkg"

int DB_init();
int DB_list();
int DB_update(const char *url);
int DB_find(const char *url);

#endif
