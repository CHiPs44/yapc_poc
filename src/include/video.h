#ifndef _VIDEO_H_
#define _VIDEO_H_

#include <stdint.h>

#include "sprite.h"
#include "font.h"
#include "tilemap.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _rgab5515
    {
        unsigned int r : 5;
        unsigned int g : 5;
        unsigned int a : 1;
        unsigned int b : 5;
    } rgab5515_t;

    typedef struct _video_info
    {
        uint16_t width;
        uint16_t height;
        uint8_t depth;
        rgab5515_t palette[256];
    } video_info_t;

    // typedef struct _video
    // {
    //     uint8_t tile_bitmap[256][8 * 8 / 2]; // 8192
    //     uint8_t font_bitmap[2][256][8];      // 4096
    //     sprite_info_t sprite[256];
    //     font_info_t font_info[2];
    //     tilemap_info_t tilemap_info;
    // } video_t;

#ifdef __cplusplus
}
#endif

#endif /* _VIDEO_H_ */
