/*
 */

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "errio.h"

void *_e_alloc(size_t size, const char *pf, size_t pl) {
	void *p = malloc(size);
	if ( p == NULL ) {
		fprintf(stderr, "\n%s:%ld asked for %ld bytes, out of memory!\n", pf, pl, size);
		abort();
		}
	return p;
	}

void *_e_realloc(void *ptr, size_t size, const char *pf, size_t pl) {
	void *p = realloc(ptr, size);
	if ( p == NULL ) {
		fprintf(stderr, "\n%s:%ld asked for %ld bytes, out of memory!\n", pf, pl, size);
		abort();
		}
	return p;
	}

void _e_free(void *p, const char *pf, size_t pl) {
	if ( p )
		free(p);
	else {
		fprintf(stderr, "\n%s:%ld free(NULL)\n", pf, pl);
		abort();
		}
	}

// --------------------------------------------------------------------------------

size_t _e_write(void *ptr, size_t size, size_t count, FILE *fp, const char *pf, size_t pl) {
	size_t n = fwrite(ptr, size, count, fp);
	if ( n != count ) {
		int e = errno;
		const char *s = strerror(e);
		fprintf(stderr, "\n%s:%ld write error\n", pf, pl);
		fprintf(stderr, "\terrno: %d, %s\n", e, s);
		abort();
		}
	return n;
	}

size_t _e_read(void *ptr, size_t size, size_t count, FILE *fp, const char *pf, size_t pl) {
	size_t n = fread(ptr, size, count, fp);
	if ( n == 0 ) {
		int e = errno;
		const char *s = strerror(e);
		fprintf(stderr, "\n%s:%ld read error\n", pf, pl);
		fprintf(stderr, "\terrno: %d, %s\n", e, s);
		abort();
		}
	return n;
	}
