#include "shell.h"
/**
 * _setenv - changes an existing variable or creates a new one
 * @name: the variable's name
 * @value: the variable's value
 * @overwrite: indicates if the existing variable should be changed or not
 * Return: (1) on success or (-1) on failure
*/
int _setenv(const char *name, const char *value, int overwrite)
{
    char **ev = environ;
    char *token;
    while (*ev != NULL)
    {
        token = strtok(*ev, "=");
        if (strcmp(token, name) == 0)
        {
            if (overwrite != 0)
            {
                 if ((*ev = change_value(value, token, strlen(token))) == NULL) 
                 {
                    fprintf(stderr, "changing the value to %s failed\n", value ); // failure
                    return -1;
                 }
                fprintf(stdout, "value changed successfully %s=%s", name, value); // success
                  return 0;
            }
            else
            {
                fprintf(stdout, "The variable exists not changed: %s=%s", name, value); // success
                return 0;
            }
           
        }
        ev++;
        
    }
    if (create_variable(name, value) == -1)
    {
        fprintf(stderr, "creation of the variable %s=%s failed\n", name, value); // failure
        return -1;
    }
    fprintf(stdout, "creation of the variable %s=%s is successful\n", name, value); //success

    return 0;
}
