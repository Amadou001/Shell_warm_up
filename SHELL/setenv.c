#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    char *variable;
    int check;
    check = setenv("My_Variable", "Hello world!", 0);
    if (check == -1)
    {
        fprintf(stdout, "variable setting failed!\n");
        return EXIT_FAILURE;
    }
    variable = getenv("My_Variable");
    if (variable == NULL)
    {
        fprintf(stdout, "getenv failed!\n");
    }
    else
    {
        printf("variable = %s\n", variable);
    }
    return EXIT_SUCCESS;
}
