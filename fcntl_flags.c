#include <stdio.h>
#include <fcntl.h>

void display_flags(char *, unsigned int);
void binary_print(unsigned int);

int main()
{
    display_flags("O_RDONLY\t\t", O_RDONLY);
    display_flags("O_WRONLY\t\t", O_WRONLY);
    display_flags("O_RDWR\t\t\t", O_RDWR);
    printf("\n");
    display_flags("O_APPEND\t\t", O_APPEND);
    display_flags("O_TRUNC\t\t\t", O_TRUNC);
    display_flags("O_CREAT\t\t\t", O_CREAT);
    printf("\n");
    display_flags("O_WRONLY|O_APPEND|O_CREAT", O_WRONLY|O_APPEND|O_CREAT);
}

void display_flags(char *label, unsigned int value)
{
    printf("%s\t: %d\t:", label, value);
    binary_print(value);
    printf("\n");
}

void binary_print(unsigned int value)
{
    /* mask for the highest byte */
    unsigned int mask = 0xff000000;
    /* shift for the highest byte */
    unsigned int shift = 256*256*256; 
    unsigned int byte;
    unsigned int byte_iterator;
    unsigned int bit_iterator;

    for (byte_iterator = 0; byte_iterator < 4; byte_iterator++) {
        byte = (value & mask) / shift;
        printf(" ");
        for (bit_iterator = 0; bit_iterator < 8; bit_iterator++) {
            /* if the highest bit in byte isn't zero */
            if (byte & 0x80)
                printf("1");
            else
                printf("0");
            /* shift all bits by 1 place */
            byte *= 2;
        }
        /* move mask by 8 bits */
        mask /= 256;
        /* move shift by 8 bits */
        shift /= 256;
    }
}
