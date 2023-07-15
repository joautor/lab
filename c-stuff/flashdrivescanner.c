#include <stdio.h>

int main(int argc, char** argv)
{
    FILE* usb_ptr;
    unsigned char buffer[512];
    int i, j;

    if (argc == 1) {
        printf("wot no stick?\n");
        return -1;
    }
    usb_ptr = fopen(argv[1], "rb");
    if(usb_ptr == NULL) printf("error opening USB Drive for reading");

    i = 0;
    while(1) {
        if (fread(buffer, 512, 1, usb_ptr) < 1) break;
        ++i;
        if (!(i & 127)) printf("%d sectors read ...\r", i);
        if (buffer[0] == 'B' && buffer[1] == 'M') {
            for (j = 0; j < 32; j++) printf("%02X ", buffer[j]);
            printf("| ");
            for (j = 0; j < 32; j++) {
                if (buffer[j] >= ' ' && buffer[j] <= '~') printf("%c", buffer[j]);
                else printf(".");
            }
            printf("\n");
        }
    }
    fclose(usb_ptr);
    return 0;
}
