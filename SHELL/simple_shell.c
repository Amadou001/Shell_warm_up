#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main (void)
{
    char **argv;
    char *buffer = NULL;
    char *command;
    int n;
    size_t len = 0;
    ssize_t bytes_read;
    pid_t pid;
    int status;
    while (1)
    {
        printf("root/Amadou/$ ");
        bytes_read == getline(&buffer, &len, stdin);
        if (bytes_read == -1)
        {
            free(buffer);
            perror("getline failed!\n");
            break;
        }
        n = strcspn(buffer, "\n");
        command = (char *)malloc(sizeof(char) * (n + 1));
        if (command == NULL)
        {
            perror("command allocution failed!\n");
            free(buffer);
            return -1;
        }
        strncpy(command, buffer, n);
        command[n] = '\0';
        argv = (char **)malloc(2 * sizeof(char *));
        if (argv == NULL)
        {
            perror("argv allocution failed!\n");
            free(command);
            free(buffer);
            return -1;
        }
        argv[0] = command;
        argv[1] = NULL;
        pid = fork();
        if (pid == -1)
        {
            perror("fork failed!\n");
            free(command);
            free(argv);
            free(buffer);
            return -1;
        }
        else if (pid == 0)
        {
         if (execve(argv[0], argv, NULL) == -1)
            {
                perror("excution failed!\n");
                free(command);
                free(argv);
                free(buffer);
                exit(EXIT_FAILURE);
            }
            exit(0);
        }
        else
        {
            wait(&status);
        }
        
        free(command);
        free(argv);
    }
    free(buffer);

    return 0;
}
