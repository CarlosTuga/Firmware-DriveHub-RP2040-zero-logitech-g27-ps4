#ifndef WHEEL_PROFILES_H
#define WHEEL_PROFILES_H
#include <stdint.h>
// Logitech G27 example VID/PID
#define G27_VID 0x046D
#define G27_PID 0xC29B
typedef struct {
    uint8_t report_id;
    uint8_t data[16];
} g27_report_t;
#endif
