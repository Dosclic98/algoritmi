CFLAGS=-std=c99 -Wall -I./include
ALL_MAIN_SRCS=$(patsubst src/main/%.c, bin/%, $(wildcard src/main/*.c))
ALL_SRCS=$(wildcard src/*.c)
ALL_OBJS=$(patsubst src/%.c, build/%.o, $(ALL_SRCS))

# compila tutti i file intermedi, e collega tutti i file
# sorgente all'interno di ./src/main/
make_exec: $(ALL_MAIN_SRCS)

# indica che i file intermedi non debbano essere eliminati
.PRECIOUS: build/%.o

# collega tutti i file intermedi (necessari) all'interno
# della cartella ./build/, e salva il file binario eseguibile
# nella cartella ./bin/ con lo stesso nome del file che contiene
# la funzione int main(int, char**) all'interno di ./src/main/
bin/%: $(ALL_OBJS) src/main/%.c
	mkdir -p src build bin
	gcc $(CFLAGS) $^ -o $@

# compila un file sorgente che si trova nella cartella ./src/;
# il file intermedio compilato viene salvato in ./build/
build/%.o: src/%.c
	mkdir -p src build bin
	gcc $(CFLAGS) $< -c -o $@
