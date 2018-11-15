CFLAGS=-std=c99 -Wall -I.
ALL_OBJS=$(patsubst %.c, %.o, $(wildcard *.c))

make_exec: gioca test

%: $(ALL_OBJS) main/%.c
	gcc $(CFLAGS) $^ -o $@

%.o: %.c
	gcc $(CFLAGS) $< -c -o $@

