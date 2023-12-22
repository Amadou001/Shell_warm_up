#include "shell.h"

int main()
{
    char *variable;
   const char *name = "my_variable";
  const char *value = "hello!";
  int check = 0;
   check = _setenv(name, value, 2);
   if (check == -1)
   {
    perror("_setenv failed\n");
    return 0;
   }
   variable = _getenv(name);
   if (variable == NULL)
   {
    perror("_getenv failed\n");
    return 0;
   }
   else
   {
       fprintf(stdout, "%s\n", variable);
   }
   while (*environ != NULL)
   {
    if ((strncmp(*environ , "my_variable", strlen("my_variable"))) == 0)
    {
        free(*environ);
    }
    environ++;
    
   }
   
   free(environ);
   return 0;   
}