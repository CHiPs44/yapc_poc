#ifndef _TERM_H_
#define _TERM_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _text_char
    {
        uint8_t c : 8;       // char to display
        uint8_t bg : 4;      // background color
        uint8_t fg : 4;      // foreground color
        uint8_t palette : 4; // palette number 0 to 15
        uint8_t scale_x : 3; // scale + 1 is used
        uint8_t scale_y : 3; // idem
        uint8_t reverse : 1; // swap bg & fg
        uint8_t alpha : 1;   // ignore bg
        uint8_t font : 4;    // font number
    } text_char_t;           // 32 bits => 4 bytes total

#ifdef __cplusplus
}
#endif

#endif /* _TERM_H_ */
