#pragma once
#include <stdint.h>
#include <cstdint>

// Using Jesse Moras' payload code first implemented in Battery Monitor Driver 
// Sync and ID constants per MIL UART protocol:
// https://milwiki.cbrxyz.com/wiki/Software-electrical_data_serialization_protocol
#define SYNC_CHAR_ONE 0x37
#define SYNC_CHAR_TWO 0x01
#define ROVER_CLASS_ID 0x30
#define ROVER_SUBCLASS_ID_DISTANCE 0x0A

/*
@brief computes the fletcher 16 check sum over buf[start...end] inclusive
*/
static void fletcher16(uint8_t *buf, int start, int end, uint8_t *sum1_out, uint8_t *sum2_out);

