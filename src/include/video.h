#ifndef _VIDEO_H_
#define _VIDEO_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _rgb5515
{
    unsigned int r:5;
    unsigned int g:5;
    unsigned int a:1;
    unsigned int b:5;
} rgb5515_t;

typedef struct _video_info
{
    uint16_t    width;
    uint16_t    height;
    uint8_t     depth;
    rgb5515_t   palette[256];
} video_info_t;

// typedef struct
// {
// } tile_t;

typedef enum _font_encoding
{
    ENCODING_ASCII = 0,
    ENCODING_CP437,
    ENCODING_CP850,
    ENCODING_ATARI,
    ENCODING_PETSCII,
} font_encoding_t;

typedef struct _font_info
{                       // bytes
    uint8_t  width;     // 1: limit to 16?
    uint8_t  height;    // 1: limit to 16?
    uint8_t  underline; // 1: <= height
    uint8_t  encoding;  // 1: ascii only, cp437, cp850, atari, petscii...
    uint8_t *bitmap;    // 4: pointer to bitmap
} font_info_t;          // 8 bytes total

typedef struct _sprite_info
{                         // bytes
    int16_t  x;           // 2: can be negative if (even partially) offscreen
    int16_t  y;           // 2: can be negative if (even partially) offscreen
    uint8_t  alpha:    8; // 1: transparent color index
    uint8_t  depth:    2; // 0=1bpp/monochrome, 1=2bpp/4 colors, 2=4bpp/16 colors, 3=8bpp/256 colors
    uint8_t  palette:  4; // palette number 0 to 15
    uint8_t  width:    2; // 0=8, 1=16, 2=32, 3=64
    uint8_t  height:   2; // 0=8, 1=16, 2=32, 3=64
    bool     h_flip:   1; // flip horizontally?
    bool     v_flip:   1; // flip vertically?
    uint8_t  rotate:   2; // 0=0° 1=90° 2=180° 3=270°
    bool     visible:  1; // 0=hidden, 1=visible
    uint16_t reserved: 9; // 4: 32 bits total
} sprite_info_t;          // 8 bytes total

typedef struct _tilemap_info
{                        // bytes
    uint16_t width;      // 2
    uint16_t height;     // 2
    uint16_t window_x;   // 2: left of tilemap window / 8
    uint16_t window_y;   // 2: top of tilemap window / 8
    uint16_t window_w;   // 2: width of tilemap window / 8
    uint16_t window_h;   // 2: height of tilemap window / 8
    int8_t   offset_x;   // 1: offset to left of tilemap, 0 to width - window_w
    int8_t   offset_y;   // 1: offset to top of tilemap, 0 to height - window_h
    int8_t   scroll_x:4; // 1: -7 to +7 pixels
    int8_t   scroll_y:4; // 1: -7 to +7 pixels
} tilemap_info_t;        // 16 bytes total

typedef struct
{
    uint8_t c:        8; // char to display
    uint8_t bg:       4; // background color
    uint8_t fg:       4; // foreground color
    uint8_t reverse:  1; // swap bg & fg
    uint8_t alpha:    1; // ignore bg
    uint8_t scale_x:  4; // 0 is processed as 1, up to 15 (16)
    uint8_t scale_y:  4; // idem, scale + 1 is used
    uint8_t font:     1; // 0=font #1 1=font #2
    uint8_t reserved: 5; // of 32 bits
} text_char_t;           // 4 bytes total

typedef struct
{
    uint8_t         tile_bitmap[256][8*8/2];    // 8192
    uint8_t         font_bitmap[2][256][8];     // 4096
    sprite_info_t   sprite[256];
    font_info_t     font_info[2];
    tilemap_info_t tilemap_info;
} video_t;

#ifdef __cplusplus
}
#endif

#endif /* _VIDEO_H_ */
