#include "ffb_forward.h"
#include <string.h>

ffb_report_buf_t ffb_out_buffer = { .data = {0}, .len = 0, .pending = false };

uint8_t host_dev_addr = 1;
uint8_t host_hid_instance = 0;

int send_ffb_to_wheel(const uint8_t *report, uint16_t len) {
    if (!host_dev_addr) return -1;
    int rc = -1;
    // Example call for TinyUSB v0.14.0+
    // rc = tuh_hid_send_report(host_dev_addr, host_hid_instance, report, len);
    (void)report; (void)len;
    rc = 0;
    return rc;
}
