#include <stdio.h>
#include <string.h>

int main()
{
    char message[10];
    int count;
    int i;

    strcpy(message, "hello world\n");

    printf("how many times: ");
    scanf("%d", &count);
    for (i=0; i<count; i++)
        printf("%3d - %s\n", i, message);
}
