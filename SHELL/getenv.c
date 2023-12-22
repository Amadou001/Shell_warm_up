#include "shell.h"

char *_getenv(const char *name)
{
    char **ev = environ; // set a pointer of strings that point to the environment variables list.
    char *token;
    while (*ev != NULL) // that list ends this a NULL pointer, so the loop stop there
    {
        token = strtok(*ev, "="); // get the first variable's name and store it in token 
        while (token != NULL) // this loop is not compulsory because there is only one = sign in each variable
         {
             if (strcmp(token, name) == 0)  // use of strcmp to compare the the variable's name to the given word
             {
                return strtok(NULL, "="); // return the value of the variable
             }
             token = strtok(NULL, "=");
         }
         ev++;
    }
    return (NULL);  // NULL is returned if the given name does not match any of the variable's name
}
