#include <stdio.h>
#include <unistd.h>

int main(void)
{
__pid_t my_ppid;
my_ppid = getppid();
printf("%u\n", my_ppid);
return 0;
}
// getppid is used here to get the parent process ID
// the ID of the parent process remains the same in every execution
// the same value can be obtained by using the command echo $$