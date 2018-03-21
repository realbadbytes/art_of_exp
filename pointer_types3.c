#include <stdio.h>

int main()
{
    int i;
    char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
    int int_array[5] = {1, 2, 3, 4, 5};

    char *char_ptr;
    int *int_ptr;

    // incompatible data types, fixed with typecasting
    char_ptr = (char *) int_array;
    int_ptr = (int *) char_array;

    for (i=0;i<5;i++){
        printf("[integer ptr] points to %p, which contains int %d\n", char_ptr, *char_ptr);
        // hack to do proper ptr arithmetic
        char_ptr = (char *) ((int *) char_ptr + 1);
    }

    for (i=0;i<5;i++){
        printf("[char ptr] points to %p, which contains char '%c'\n", int_ptr, *int_ptr);
        // hack to do proper ptr arithmetic
        int_ptr = (int *) ((char *) int_ptr + 1);
    }
}
