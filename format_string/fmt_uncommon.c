#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A;
    int B;
    int count_one;
    int count_two;

    A = 5;
    B = 7;

    /* Example of %n format string */
    printf("The number of bytes written so far X%n is being stored in "
        "count_one, and the number of bytes written to here X%n is being "
        "stored in count_two.\n", &count_one, &count_two);

    printf("count_one: %d\n", count_one);
    printf("count_two: %d\n", count_two);

    /* Stack example */
    printf("A is %d and is at %08x.\nB is %x.\n", A, &A, B);

    exit(0);
}



