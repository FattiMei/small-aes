#ifndef AES_H
#define AES_H


#include <stdbool.h>
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


typedef struct aesctx aesctx;


// funzioni per gestire la struttura ctx
aesctx* aes_new_ctx(aesmode);
bool   	aes_set_key(aesctx*, struct mv);


void aes_print      (aesblock*);
void aes_transpose  (aesblock*, aesblock*);

void aes_encrypt(aesblock*, aesblock*, aesctx *ctx);
void aes_decrypt(aesblock*, aesblock*, aesctx *ctx);


#endif
