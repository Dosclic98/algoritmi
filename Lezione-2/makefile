CFLAGS=-std=c99 -Wall -I./include
ALL_MAIN_SRCS=$(patsubst src/main/%.c, bin/%, $(wildcard src/main/*.c))
ALL_SRCS=$(wildcard src/*.c)
ALL_OBJS=$(patsubst src/%.c, build/%.o, $(ALL_SRCS))

make_exec: $(ALL_MAIN_SRCS)

.PRECIOUS: build/%.o

bin/%: $(ALL_OBJS) src/main/%.c
	mkdir -p src build bin
	gcc $(CFLAGS) $^ -o $@

build/%.o: src/%.c
	mkdir -p src build bin
	gcc $(CFLAGS) $< -c -o $@
