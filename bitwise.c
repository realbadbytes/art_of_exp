#include <stdio.h>

int main()
{
    int i;
    int bit_a;
    int bit_b;

    printf("bitwise OR | \n");
    for (i = 0; i < 4; i++) {
        /* get first bit   */
        /* bitmask of 0010 */
        bit_a = (i & 2) / 2;
        /* get second bit  */
        /* bitmast of 0001 */
        bit_b = (i & 1);
        printf("%d | %d = %d\n", bit_a, bit_b, (bit_a | bit_b));
    }

    printf("\nbitwise AND &\n");
    for (i = 0; i < 4; i++) {
        bit_a = (i & 2) / 2;
        bit_b = (i & 1);
        printf("%d & %d = %d\n", bit_a, bit_b, (bit_a & bit_b));
    }
}
