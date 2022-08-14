#ifndef AES_H
#define AES_H


#include "mv.h"


typedef union aesblock{
	uint8_t  bytes[16];
	uint32_t rows[4];
	uint8_t  grid[4][4];
} aesblock;


typedef enum aesmode{
	AES128 = 1,
    AES192,
    AES256
} aesmode;


typedef struct aesctx{
	int NK, NB, NR;
	aesblock roundkey[1];
} aesctx;


// funzioni per gestire la struttura ctx
aesctx* aes_new_ctx(aesmode);
int    	aes_set_key(aesctx*, struct mv);


void transpose(aesblock*, aesblock*);
void aes_print_block(aesblock*);
void aes_encrypt_block(aesblock*, aesblock*, aesctx *ctx);
void aes_decrypt_block(aesblock*, aesblock*, aesctx *ctx);


#endif
