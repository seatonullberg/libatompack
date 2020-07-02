INCLUDE=-Isrc

all:
	@make shared

clean:
	@rm -rf bin
	@rm -rf lib

document:
	@rm -rf docs
	@doxygen Doxyfile
	@mv docs/html/* docs/
	@rm -rf docs/html

shared:
	@mkdir -p lib
	@gcc $(INCLUDE) -fPIC -shared -O3 -o lib/libatompack.so src/*.c

test:
	@mkdir -p bin
	@gcc $(INCLUDE) -lm -o bin/libatompack-tests src/*.c tests/*.c
	@./bin/libatompack-tests