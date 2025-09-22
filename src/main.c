#include "ffb_forward.h"
#include <string.h>
#include <stdio.h>

ffb_report_buf_t ffb_out_buffer;

void tud_hid_set_report_cb(uint8_t instance, uint8_t const* report, uint16_t len) {
    (void)instance;
    if (!report || len == 0) return;
    if (len > MAX_FFB_REPORT_SIZE) len = MAX_FFB_REPORT_SIZE;
    memcpy(ffb_out_buffer.data, report, len);
    ffb_out_buffer.len = len;
    ffb_out_buffer.pending = true;
}

int main(void) {
    while (1) {
        if (ffb_out_buffer.pending) {
            send_ffb_to_wheel(ffb_out_buffer.data, ffb_out_buffer.len);
            ffb_out_buffer.pending = false;
        }
    }
    return 0;
}
