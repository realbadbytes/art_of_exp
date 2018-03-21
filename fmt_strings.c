#include <stdio.h>

int main()
{
    char string[10];
    int a = -73;
    unsigned int b = 31337;

    strcpy(string, "sample");

    //sample prints
    printf("[a] decimal: %d, hex: %x, unsigned: %u\n", a, a, a);
    printf("[a] decimal: %d, hex: %x, unsigned: %u\n", b, b, b);
    printf("[b field width] 3: '%3u', 10: '%10u', 8: '%08u'\n", b, b, b);
    printf("[string] %s addr: %08x\n", string, string);

    //unary operator
    printf("var a is at addr: %08x\n", &a);
}
