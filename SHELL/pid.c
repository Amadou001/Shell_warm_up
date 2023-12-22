#include <stdio.h>
#include <unistd.h>

int main(void)
{
__pid_t my_pid;
my_pid = getpid();
printf("%u\n", my_pid);

return 0;
}
// getpid is used to get the process ID.
// the ID of the process changes in every execution