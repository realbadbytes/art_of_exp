#include <stdio.h>

int global_var;

int global_initialized_var = 5;

void function()
{
    int stack_var;
    
    printf("stack_var at %p\n", &stack_var);
}

int main()
{
    int stack_var;
    static int static_initialized_var = 5;
    static int static_var;
    int *heap_var_ptr;

    heap_var_ptr = (int *)malloc(4);

    printf("----- data segment -----\n");
    printf("global_initialized_var at %p\n", &global_initialized_var);
    printf("static_initialized_var at %p\n", &static_initialized_var);

    printf("----- bss segment -----\n");
    printf("static_var at %p\n", &static_var);
    printf("global_var at %p\n", &global_var);

    printf("----- heap segment -----\n");
    printf("heap_var at %p\n", heap_var_ptr);

    printf("stack_var at %p\n", &stack_var);
    function();
}
