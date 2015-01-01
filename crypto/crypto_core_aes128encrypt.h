#ifndef crypto_core_aes128encrypt_H
#define crypto_core_aes128encrypt_H

#define crypto_core_aes128encrypt_tinynacl_OUTPUTBYTES 16
#define crypto_core_aes128encrypt_tinynacl_INPUTBYTES 16
#define crypto_core_aes128encrypt_tinynacl_KEYBYTES 16
#define crypto_core_aes128encrypt_tinynacl_CONSTBYTES 0
extern int crypto_core_aes128encrypt_tinynacl(unsigned char *,const unsigned char *,const unsigned char *,const unsigned char *);

#define crypto_core_aes128encrypt crypto_core_aes128encrypt_tinynacl
#define crypto_core_aes128encrypt_OUTPUTBYTES crypto_core_aes128encrypt_tinynacl_OUTPUTBYTES
#define crypto_core_aes128encrypt_INPUTBYTES crypto_core_aes128encrypt_tinynacl_INPUTBYTES
#define crypto_core_aes128encrypt_KEYBYTES crypto_core_aes128encrypt_tinynacl_KEYBYTES
#define crypto_core_aes128encrypt_CONSTBYTES crypto_core_aes128encrypt_tinynacl_CONSTBYTES
#define crypto_core_aes128encrypt_IMPLEMENTATION "tinynacl"
#define crypto_core_aes128encrypt_VERSION "-"

#endif
