#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <sys/wait.h> 
#include <stdlib.h>

int main(void)
{
char *argv[]=  {"/bin/ls", "-l", "/tmp", NULL};
pid_t child_pid;
int status;
for (int i = 0; i < 5; i++)
{
child_pid = fork();
if (child_pid == -1)
{
perror("child pid failed!\n");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
if (execve(argv[0], argv, NULL) == -1)
{
    perror("execution failed!\n");
}
exit(EXIT_SUCCESS);
}
else
{
    wait(&status);
    printf("%d\n", status);
}
}

return 0;
}
