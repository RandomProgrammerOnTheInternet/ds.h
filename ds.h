#ifndef DS_H
#define DS_H
#endif // DS_H

#include <stdlib.h>

// Dynamic Arrays
#define LIST(x) x*
#define INIT_LIST(x, y) x = (typeof(x))malloc(y * sizeof(typeof(*x))); size_t x ## _size = y * sizeof(typeof(*x))
#define LIST_RESIZE(x, y) x = (typeof(x))realloc(x, y * sizeof(typeof(*x))); x ## _size = y * sizeof(typeof(*x))
#define LIST_ADD(x, y) LIST_RESIZE(x, (x ## _size / sizeof(typeof(*x)) + y))
#define LIST_APPEND(x, y) LIST_ADD(x, 1); x[x ## _size / sizeof(typeof(*x)) - 1] = y
#define LIST_FREE(x) if(x != NULL) free(x)
