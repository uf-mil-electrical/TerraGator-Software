#include "msgs/msgs.h"

// Computes a Fletcher 16 checksum over buf[start..end] inclusive.
// Per the MIL UART protocol, checksum STARTS at the CLASS ID byte (indexex at 2)
// and runs through the LAST data byte — SYNC BYTES ARE EXCLUDED!
// Refer here for additional specs: https://milwiki.cbrxyz.com/wiki/Software-electrical_data_serialization_protocol
static void fletcher16(uint8_t *buf, int start, int end, uint8_t *sum1_out, uint8_t *sum2_out)
{
    uint8_t sum1 = 0;
    uint8_t sum2 = 0;
    for (int i = start; i <= end; i++)
    {
        sum1 = (sum1 + buf[i]) % 255;
        sum2 = (sum2 + sum1)  % 255;
    }
    *sum1_out = sum1;
    *sum2_out = sum2;
}