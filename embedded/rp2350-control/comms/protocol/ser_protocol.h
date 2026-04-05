#ifndef SER_PROTOCOL_H_
#define SER_PROTOCOL_H_

/*
    Formatting for the software-electrical serialization protocol 
    Wiki page: https://milwiki.cbrxyz.com/wiki/Software-electrical_data_serialization_protocol
    Modelled after Adrian's electrical message system for the purple board: 
    https://github.com/uf-mil-electrical/SubjuGator9/blob/main/Thruster-Control/2024-2025/COTS-Thrust-Board/Firmware/src/MIL_electrical_message_system.h
*/

// ----------------------------------------- DEFINES -------------------------------------------- //
#define SYNC_VALUE 0x3701
#define SYNC_HI (uint8_t) (SYNC_VALUE >> 8)
#define SYNC_LO (uint8_t) (SYNC_VALUE & 0xFF)
#define MAX_PAYLOAD_LENGTH 256

// ROVER SERIAL CODES 
#define ROVER_CLASS_ID 0x30
#define CMD_VEL_PKT_SUBCLASS_ID 0x00
#define POSE_PKT_SUBCLASS_ID 0x01
#define BATTERY_STATUS_PKT_SUBCLASS_ID 0x10

typedef struct ser_message {
    uint16_t sync; 
    uint8_t class_id;
    uint8_t subclass_id; 

    union {
        struct {
            uint8_t low;
            uint8_t high;
        } bytes;
        uint16_t value; 
    } payload_length;

    uint8_t payload[MAX_PAYLOAD_LENGTH];
} ser_message_t;

typedef enum {
    SYNC_H = 0, 
    SYNC_L = 1,
    CLASS_ID = 2,
    SUBCLASS_ID = 3, 
    PAYLOAD_LENGTH_H = 4,
    PAYLOAD_LENGTH_L = 5,
    PAYLOAD = 6,
    CHECKSUM_H = 7,
    CHECKSUM_L = 8
} ser_state_t;

#endif