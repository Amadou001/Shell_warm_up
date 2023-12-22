#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main(void)
{
    char *buffer = NULL;
    size_t len = 0;
    ssize_t bytes_read;

    while (1)
    {
        printf("$ ");
        bytes_read = getline(&buffer, &len, stdin);

        if (bytes_read == -1)
        {
            perror("getline failed!\n");
            break;
        }

        // Remove the newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Allocate memory for argv array
        char **argv = (char **)malloc(2 * sizeof(char *));

        if (argv == NULL)
        {
            perror("argv allocation failed!\n");
            free(buffer);
            return -1;
        }

        // Copy the command to argv[0] and set argv[1] to NULL
        argv[0] = strdup(buffer);
        argv[1] = NULL;

        // Fork a new process
        pid_t pid = fork();

        if (pid == -1)
        {
            perror("fork failed!\n");
            free(argv[0]);
            free(argv);
            free(buffer);
            return -1;
        }

        if (pid == 0)
        {
            // Child process
            if (execvp(argv[0], argv) == -1)
            {
                perror("execution failed!\n");
                free(argv[0]);
                free(argv);
                free(buffer);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            // Parent process
            // Wait for the child process to finish
            wait(NULL);
        }

        // Free allocated memory
        free(argv[0]);
        free(argv);
    }

    // Free buffer before exiting
    free(buffer);

    return 0;
}
