#ifndef FFB_FORWARD_H
#define FFB_FORWARD_H
#include <stdint.h>
#include <stdbool.h>
#define MAX_FFB_REPORT_SIZE 64
typedef struct {
    uint8_t data[MAX_FFB_REPORT_SIZE];
    uint16_t len;
    volatile bool pending;
} ffb_report_buf_t;
extern ffb_report_buf_t ffb_out_buffer;
int send_ffb_to_wheel(const uint8_t *report, uint16_t len);
#endif
