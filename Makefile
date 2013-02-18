FLAGS:= -g -Wall
GXX:= g++
all: crypt_perm.so

crypt_perm.so: crypt_perm.o Permutation.o
	$(GXX) -o crypt_perm.so crypt_perm.o Permutation.o -shared

crypt_perm.o: crypt_perm.cpp crypt_perm.h
	$(GXX) $(FLAGS) -c crypt_perm.cpp

Permutation.o: Permutation.cpp Permutation.h
	$(GXX) $(FLAGS) -c Permutation.cpp

clean:
	rm -f crypt_perm.so
