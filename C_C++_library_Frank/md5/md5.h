#ifndef __MD5_H__
#define __MD5_H__

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/* MD5 Class. */
class MD5
{
public:
    MD5();
    virtual ~MD5();
    bool fileMd5(char *pMd5, const char *pFileName);
    bool strMd5 (char *pMd5, const char *str);

private:
    unsigned long int state[4];		/* state (ABCD) */
    unsigned long int count[2];		/* number of bits, modulo 2^64 (lsb first) */
    unsigned char buffer[64];       /* input buffer */
    unsigned char PADDING[64];

private:
    void MD5Init ();
    void MD5Update( unsigned char *input, unsigned int inputLen);
    void MD5Final (unsigned char digest[16]);
    void MD5Transform (unsigned long int state[4], unsigned char block[64]);
    void MD5_memcpy (unsigned char* output, unsigned char* input,unsigned int len);
    void Encode (unsigned char *output, unsigned long int *input,unsigned int len);
    void Decode (unsigned long int *output, unsigned char *input, unsigned int len);
    void MD5_memset (unsigned char* output,int value,unsigned int len);
};
//返回一个字符串的md5值
const char* getStrMd5(char* md5_value, const char* str);

#endif
