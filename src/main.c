// Standard libs
// #include <stdint.h>
#include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
#include <wchar.h>

// Pico SDK
#include "pico.h"
#include "hardware/clocks.h"
#include "hardware/vreg.h"
// #include "pico/multicore.h"
#include "pico/stdlib.h"
// #include "pico/rand.h"

int main()
{
    // vreg_set_voltage(VREG_VOLTAGE_MAX);
    // bool ok = set_sys_clock_khz(250 * KHZ, false);
    stdio_init_all();
    // sleep_ms(1000);
    // printf("set_sys_clock_khz? %s\n", ok ? "OK" : "KO");
    while (true) {
        printf("Hello, %s!\n", "world");
        wprintf(L"Hello, %ls!\n", L"CHiPs44");
        sleep_ms(1000);
    }
}
