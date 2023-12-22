#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_FILE_NAME_LENGTH 256
#define MAX_PATH_LENGTH 1024

void find_executable(const char *file_name, const char *path)
{
char *path_copy, *token;
char full_path[MAX_PATH_LENGTH];
path_copy = strdup(path);
token = strtok(path_copy, ":");
while (token != NULL)
{
    snprintf(full_path, sizeof(full_path), "%s/%s", token, file_name);
    if (access(full_path, X_OK) == 0)
    {
        printf("%s\n", full_path);
        free(path_copy);
        return;
    }
    token = strtok(NULL, ":");

}
printf("%s not found\n", full_path);

free(path_copy);
}

int main(int ac, char **av)
{
    char *path;
if (ac < 2)
{
    fprintf(stderr, "usage: %s filename..\n", av[0]);
    return (EXIT_FAILURE);
}
path = getenv("PATH");
if (path == NULL)
{
    fprintf(stderr, "Evironment path not set.\n");
    return (EXIT_FAILURE);
}
for (int i = 1; i < ac; i++)
{
    find_executable(av[i], path);
}
return EXIT_SUCCESS;
}
