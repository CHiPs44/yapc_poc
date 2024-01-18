#ifndef _TILEMAP_H_
#define _TILEMAP_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

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

#ifdef __cplusplus
}
#endif

#endif /* _TILEMAP_H_ */
