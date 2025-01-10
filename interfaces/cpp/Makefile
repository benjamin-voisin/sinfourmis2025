
default: fourmis.so

fourmis.so: fourmis.cpp memoire.c
	gcc -o fourmis.so -shared -fPIC fourmis.cpp

check_file:
	@if [ ! -f sinfourmis.h ]; then echo "sinfourmis.h not found"; exit 1; fi

clean:
	rm -f fourmis.so
