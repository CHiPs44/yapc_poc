#ifndef _VIDEO_H_
#define _VIDEO_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// typedef struct
// {
// } tile_t;

typedef struct {
    uint8_t width;    // <=8
    uint8_t height;   // <=8
    uint8_t encoding; // cp437, cp850, atari, amstrad_en, petscii, ...
    uint8_t reserved; // paddind to 32 bits
} font_info_t;

typedef struct
{
    int16_t  x;
    int16_t  y;
    uint8_t  alpha:     4; // transparent color index
    bool     size:      2; // 0=8x8 1=16x8 2=8x16 3=16x16
    bool     flip_h:    1;
    bool     flip_v:    1;
    uint8_t  rotate:    2; // 0=0° 1=90° 2=180° 3=270°
    uint32_t reserved: 22; // of 32 bits
} sprite_info_t;

typedef struct {
    uint16_t width;
    uint16_t height;
    int16_t  window_x; // left of tilemap window / 8
    int16_t  window_y; // top of tilemap window / 8
    int16_t  window_w; // width of tilemap window / 8
    int16_t  window_h; // height of tilemap window / 8
    int8_t   offset_x; // offset to left of tilemap, 0 to 
    int8_t   offset_y; // offset to left of tilemap
    int8_t   scroll_x; // -7 to +7
    int8_t   scroll_y; // -7 to +7
} tilemap_info_t;

typedef struct
{
    uint8_t c:          8; // char to display
    uint8_t bg:         4; // background color
    uint8_t fg:         4; // foreground color
    uint8_t font:       1; // 0=font #1 1=font #2
    uint8_t reverse:    1; // swap bg & fg
    uint8_t alpha:      1; // ignore bg
    uint8_t scale_x:    4; // 0 is processed as 1
    uint8_t scale_y:    4; // (scale + 1 is used)
    uint8_t reserved:   5; // of 32 bits
} text_char_t;

typedef struct
{
    uint8_t tile_bitmap[256][8*8/2];    // 8192
    uint8_t font_bitmap[2][256][8];     // 4096
    sprite_info_t sprite[256];
    font_info_t font_info[2];

} video_t;


#ifdef __cplusplus
}
#endif

#endif /* _VIDEO_H_ */
