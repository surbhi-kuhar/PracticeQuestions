#include <stdio.h>

int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xFF;
}

int main() {
    int num = 0x12345678; 
    int byteIndex;

    for (byteIndex = 0; byteIndex < 4; ++byteIndex) {
        int result = getByte(num, byteIndex);
        printf("Byte %d: %02X\n", byteIndex, result);
    }

    return 0;
}

