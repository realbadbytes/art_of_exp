#include <stdio.h>

int main()
{
    printf("real uid\t: %d\n", getuid());
    printf("effective uid\t: %d\n", geteuid());
}
