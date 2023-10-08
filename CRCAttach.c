#include <stdio.h>

// Define LTE CRC polynomial (in binary representation)
#define LTE_CRC_POLY 0x04C11DB7

// Function to calculate LTE CRC
unsigned int calculate_crc(unsigned char *data, int len) {
    unsigned int crc = 0xFFFFFFFF;

    for (int i = 0; i < len; i++) {
        crc ^= data[i] << 24;

        for (int j = 0; j < 8; j++) {
            if (crc & 0x80000000) {
                crc = (crc << 1) ^ LTE_CRC_POLY;
            } else {
                crc <<= 1;
            }
        }
    }

    return crc;
}

int main() {
    unsigned char message[] = {0x12, 0x34, 0x56, 0x78}; // Example message
    int message_len = 4; // Length of the message in bytes

    // Calculate CRC
    unsigned int crc = calculate_crc(message, message_len);

    // Attach CRC to message
    *((unsigned int*)(message + message_len)) = crc;

    // Print the message with CRC
    printf("Message with CRC: ");
    for (int i = 0; i < message_len + 4; i++) {
        printf("%02X ", message[i]);
    }
    printf("\n");

    return 0;
}
