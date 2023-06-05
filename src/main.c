// // Standard libs
// #include <stdint.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <wchar.h>
// // Pico SDK
// #include "pico.h"
// #include "hardware/clocks.h"
// #include "hardware/vreg.h"
// #include "pico/multicore.h"
// #include "pico/stdlib.h"
// #include "pico/rand.h"

#include <stdio.h>
#include "pico/stdlib.h"

int main()
{
    stdio_init_all();
    while (true) {
        puts("Hello, world!\n");
        sleep_ms(1000);
    }
}
