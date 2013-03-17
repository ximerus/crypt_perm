/*
 * Copyright (c) Jenia Grubian
 * Licensed under GPLv2
 * Simple cryptography library that uses permutations to encrypt and decrypt byte array
 */

#ifndef CRYPT_PERM_H
#define CRYPT_PERM_H

#include <bitset>
#include <vector>
#include <cstring>
#include "Permutation.h"

typedef unsigned int u_int;

struct Block 
{
	std::bitset<8>* bytes;
	const u_int size;
	Block(int n) : size(n) { bytes = new std::bitset<8>[n]; }
	Block() : size(0) { }
	~Block() { delete[] bytes; }
	std::bitset<8>::reference operator[](u_int i) { return bytes[i/8][i%8]; }
	Block& operator=(const Block& block) { return *this; }
};

/* 
 * Two functions that implement permutation encryption/decryption methods.
 * They take permutation(key of the cipher) and byte array that is needed to be encoded or decoded
 */

const char* encode(const Permutation&, char*);

const char* decode(const Permutation&, char*);

/* Function that aligns byte array depended on number of blocks */ 
void align(char*, u_int);

/* Function that explodes byte array into blocks of bits */
std::vector< Block > bytesToBitsetArray(char*, u_int);

/* note: to convert const char* to char* use strdup() */
#endif /* CRYPT_PERM_H */
