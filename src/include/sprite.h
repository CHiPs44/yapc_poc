#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _sprite_info
{                         // bytes
    int16_t  x;           // 2: can be negative if (even partially) offscreen
    int16_t  y;           // 2: can be negative if (even partially) offscreen
    uint8_t  alpha:    8; // 1: transparent color index
    uint8_t  depth:    2; // 0=1bpp / monochrome, 1=2bpp / 4 colors, 2=4bpp / 16 colors, 3=8bpp / 256 colors
    uint8_t  palette:  4; // palette number 0 to 15
    uint8_t  width:    2; // 0=8, 1=16, 2=32, 3=64
    uint8_t  height:   2; // 0=8, 1=16, 2=32, 3=64
    bool     h_flip:   1; // flip horizontally?
    bool     v_flip:   1; // flip vertically?
    uint8_t  rotate:   2; // 0=0° 1=90° 2=180° 3=270°
    bool     visible:  1; // 0=hidden, 1=visible
    uint16_t reserved: 9; // 4: 32 bits total
} sprite_info_t;          // 8 bytes total

#ifdef __cplusplus
}
#endif

#endif /* _SPRITE_H_ */
