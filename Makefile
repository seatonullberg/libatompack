INCLUDE=-Ideps/rmsd -Ideps/utest.h

all:
	@make shared

clean:
	@rm -rf bin

document:
	@rm -rf docs
	@doxygen Doxyfile
	@mv docs/html/* docs/
	@rm -rf docs/html

shared:
	@mkdir -p bin
	@gcc $(INCLUDE) -fPIC -shared -o bin/libatompack.so src/*.c

test:
	@gcc $(INCLUDE) -Isrc -lm -o libatompack-tests src/*.c tests/*.c
	@./libatompack-tests
	@rm libatompack-tests
