#include <stdio.h>

void usage(char *name)
{
    printf("bad usage\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    int i, count;
    count = atoi(argv[2]);
    for (i = 0; i < count; i++)
        printf("%d - %s\n", i, argv[1]);
}
