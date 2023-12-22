#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
    printf("environ address :%p\n", environ);
    printf("env address: %p\n", env);

    return 0;
}
// the addresses of environ and env are the same because they point to the list