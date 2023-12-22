#include "shell.h"

void print_path(char *path)
{
    char *token;
    char *get_path;
    get_path = _getenv(path);
    token = strtok(get_path, ":");
    while (token != NULL)
    {
        fprintf(stdout, "%s\n", token);
        token = strtok(NULL, ":");
    }
    
}

int main(void)
{
    print_path("PATH");

    return 0;
}
