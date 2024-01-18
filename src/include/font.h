#ifndef _FONT_H_
#define _FONT_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef enum _font_encoding
    {
        ENCODING_ASCII = 0,
        ENCODING_CP437,
        ENCODING_CP850,
        ENCODING_ATARI,
        ENCODING_PETSCII,
    } font_encoding_t;

    typedef struct _font_info
    {                      // bytes
        uint8_t width;     // 1: limit?
        uint8_t height;    // 1: limit?
        uint8_t underline_pos; // 1: <= height, position of underline
        uint8_t underline_height; // 1: <= height, thickness of underline
        uint8_t encoding;  // 1: ASCII only, CP437, CP850, ATARI, PETSCII...
        uint8_t *bitmap;   // 4: pointer to bitmap
    } font_info_t;         // 8 bytes total?

#ifdef __cplusplus
}
#endif

#endif /* _FONT_H_ */
