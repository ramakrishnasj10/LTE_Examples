#include <stdio.h>

// Define constants for LTE header, payload, and CRC bits
#define HEADER_BITS 24
#define PAYLOAD_BITS 256
#define CRC_BITS 24

int main() {
    // Generate 304 bits of LTE data (for demonstration purposes)
    unsigned char receivedBits[304] = {
        // Header bits (24 bits)
        1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0,

        // Payload bits (256 bits)
        1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1,
        // ... (more payload bits, truncated for brevity)

        // CRC bits (24 bits)
        0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0
    };

    // Print received bits (for demonstration purposes)
    printf("Received bits: ");
    for (int i = 0; i < 304; i++) {
        printf("%d", receivedBits[i]);
    }
    printf("\n");

    // Extract essential bits (payload)
    unsigned char essentialBits[PAYLOAD_BITS];
    for (int i = HEADER_BITS; i < HEADER_BITS + PAYLOAD_BITS; i++) {
        essentialBits[i - HEADER_BITS] = receivedBits[i];
    }

    // Print extracted essential bits
    printf("Essential bits (Payload): ");
    for (int i = 0; i < PAYLOAD_BITS; i++) {
        printf("%d", essentialBits[i]);
    }
    printf("\n");

    // Discard non-essential bits (header and CRC bits)
    printf("Discarded bits (Header + CRC): ");
    for (int i = 0; i < HEADER_BITS + CRC_BITS; i++) {
        printf("%d", receivedBits[i]);
    }
    printf("\n");

    return 0;
}
