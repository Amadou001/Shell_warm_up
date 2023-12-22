#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(void)
{
    char **ev = environ;
    while (*ev != NULL)
    {
        printf("%s\n", *ev);
        ev++;
    }

    return 0;
}
