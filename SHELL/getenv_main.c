#include "shell.h"


int main()
{
    char *path;
    path = _getenv("PATH");
    if (path == NULL)
    {
        fprintf(stderr, "environment not set\n");
    }
    else
     fprintf(stdout, "%s\n", path);
}
