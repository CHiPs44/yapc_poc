#ifndef _TILE_H_
#define _TILE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        uint8_t width : 2;   // 0=8, 1=16, 2=32, 3=64
        uint8_t height : 2;  // 0=8, 1=16, 2=32, 3=64
        uint8_t palette : 4; // palette number 0 to 15
        uint32_t reserved : 24;
        uint8_t *data;
    } tile_t;

#ifdef __cplusplus
}
#endif

#endif /* _TILE_H_ */
