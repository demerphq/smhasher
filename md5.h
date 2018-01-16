#pragma once
/**
 * \brief          MD5 context structure
 */
typedef struct
{
    uint32_t state[4];     /*!< intermediate digest state  */
    uint32_t total[2];     /*!< number of bytes processed  */
    unsigned char buffer[64];   /*!< data block being processed */

    unsigned char ipad[64];     /*!< HMAC: inner padding        */
    unsigned char opad[64];     /*!< HMAC: outer padding        */
}
md5_context;
