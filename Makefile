# TODO: make this a makefile that doesn't just recompile everything, i'm too lazy right now
.PHONY: clean

lib: build/libshape.so

build/libshape.so: house.c house.h square.c square.h triangle.c triangle.h ishapearea.h
	mkdir -p build
	cd build && gcc -c -Wall -Werror -fpic ../house.c ../square.c ../triangle.c
	gcc -shared build/*.o -o build/libshape.so 

clean:
	rm -rf ./build/