#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

// 修改日志宏 使之包含函数名称和file：line

#define log_err(N, M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) in [FUNC]: " N " " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(N, M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) in [FUNC]: " N " " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(N, M, ...) fprintf(stderr, "[INFO] (%s:%d) in [FUNC]: " N " " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, N, M, ...) if(!(A)) { log_err(N, M, ##__VA_ARGS__); errno=0; goto error; }

#define sentinel(N, M, ...) { log_err(N, M, ##__VA_ARGS__); errno=0; goto error; }

#define check_mem(A, N) check((A), N, "Out of memory.")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#endif
