CFLAGS=-O0 -g
ALL=fastbin tcache uaf overflow double-free

all: ${ALL}

fastbin: fastbin.c
	gcc ${CFLAGS} $< -o $@

tcache: tcache.c
	gcc ${CFLAGS} $< -o $@

uaf: uaf.c
	gcc ${CFLAGS} $< -o $@

overflow: overflow.c
	gcc ${CFLAGS} $< -o $@

double-free: double-free.c
	gcc ${CFLAGS} $< -o $@

clean:
	rm -rf ${ALL}
