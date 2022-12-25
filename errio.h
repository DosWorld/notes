/*
 */

#if !defined(__ERRIO_H__)
#define __ERRIO_H__

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdio.h>

void *_e_alloc(size_t size, const char *pf, size_t pl);
void *_e_realloc(void *ptr, size_t size, const char *pf, size_t pl);
void _e_free(void *p, const char *pf, size_t pl);

#define m_alloc(size) _e_alloc(size, __FILE__, __LINE__)
#define m_realloc(ptr,size) _e_realloc(ptr, size, __FILE__, __LINE__)
#define m_free(ptr) _e_free(ptr, __FILE__, __LINE__)

// --------------------------------------------------------------------------------

size_t _e_write(void *ptr, size_t size, size_t n, FILE *fp, const char *pf, size_t pl);
size_t _e_read(void *ptr, size_t size, size_t n, FILE *fp, const char *pf, size_t pl);

#define f_write(ptr,size,n,fp) _e_write(ptr, size, n, fp, __FILE__, __LINE__)
#define f_read(ptr,size,n,fp) _e_read(ptr, size, n, fp, __FILE__, __LINE__)

#if defined(__cplusplus)
	}
#endif

#endif
