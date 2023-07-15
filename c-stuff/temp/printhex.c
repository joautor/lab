#include <stdio.h>

#define BIN_PATTERN "%c%c%c%c%c%c%c%c"
#define CONVERT_TO_BINARY(byte) \
    (byte & 0x80) ? '1' : '0', \
    (byte & 0x40) ? '1' : '0', \
    (byte & 0x20) ? '1' : '0', \
    (byte & 0x10) ? '1' : '0', \
    (byte & 0x08) ? '1' : '0', \
    (byte & 0x04) ? '1' : '0', \
    (byte & 0x02) ? '1' : '0', \
    (byte & 0x01) ? '1' : '0'


int main()
{
/*    unsigned char c = 0;
    for(; c < 255; ++c) {
        printf("%d\t%x\n", (int)c, c);
    }
    printf("%d\t%x\n", (int)c, c);
    printf("-----------------------\n");
    ++c;
    printf("%d\t%x\n", (int)c, c);
*/
    char c = 0;
    for (int counter = 0; counter <= (255 + 1); ++counter) {
        printf("%d\t%x\t" BIN_PATTERN "\n", (int)c, c, CONVERT_TO_BINARY(c));      // %X - for capital letter hex
        ++c;
    }
    return 0;
}
