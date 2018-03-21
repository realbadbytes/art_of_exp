#include <stdio.h>

int main()
{
    int i;
    char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
    int int_array[5] = {1, 2, 3, 4, 5};

    char *char_ptr;
    int *int_ptr;

    char_ptr = char_array;
    int_ptr = int_array;

    for (i=0;i<5;i++){
        printf("[integer ptr] points to %p, which contains int %d\n", int_ptr, *int_ptr);
        int_ptr++;
    }

    for (i=0;i<5;i++){
        printf("[char ptr] points to %p, which contains char '%c'\n", char_ptr, *char_ptr);
        char_ptr++;
    }
}
