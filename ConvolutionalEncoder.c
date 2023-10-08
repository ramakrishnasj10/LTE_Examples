#include <stdio.h>

// Define the generator polynomials (in octal representation)
#define POLY_1 0133
#define POLY_2 0115

// Function to perform convolutional encoding
void convolutional_encoder(int input[], int output[], int len) {
    int state1 = 0; // Initialize state for encoder 1
    int state2 = 0; // Initialize state for encoder 2

    for (int i = 0; i < len; i++) {
        // Encoder 1
        int in_bit = input[i];
        int out_bit1 = (state1 & POLY_1) ^ (state1 & POLY_2);
        state1 = (state1 >> 1) | (in_bit << 5);

        // Encoder 2
        int out_bit2 = (state2 & POLY_1) ^ (state2 & POLY_2);
        state2 = (state2 >> 1) | (in_bit << 5);

        output[i*2] = out_bit1;
        output[i*2 + 1] = out_bit2;
    }
}

int main() {
    int input[] = {1, 0, 1, 1, 0, 0}; // Example input bitstream
    int output[12]; // Output bitstream (1/2 rate, so output will be twice the length of input)

    convolutional_encoder(input, output, 6);

    // Print the encoded output
    printf("Encoded Output: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    return 0;
}
