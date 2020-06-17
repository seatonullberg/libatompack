.DEFAULT_GOAL := shared

clean:
	@rm -rf ./bin

document:
	@rm -rf docs
	@doxygen Doxyfile
	@mv docs/html/* docs/
	@rm -rf docs/html

shared:
	@mkdir -p ./bin
	@gcc -fPIC -shared -o ./bin/libatompack.so ./src/*.c

test:
	@gcc -lm -o testatompack ./src/*.c
	@./testatompack
	@rm ./testatompack
