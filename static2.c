#include <stdio.h>

void function()
{
    int var = 5;
    static int static_var = 5;
    printf("\t[in function] var = %d @ %p\n", var, &var);
    printf("\t[in function] static_var = %d @ %p\n", static_var, &static_var);
    var++;
    static_var++;
}

int main()
{
    int i;
    static int static_var = 1337;
    
    for (i = 0; i < 5; i++)
    {
        printf("[in main] static_var = %d, @ %p\n", static_var, &static_var);
        function();
    }
}
