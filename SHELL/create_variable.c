#include "shell.h"
/**
 * create_variable - create a new variable inside the environment
 * @name: name of the variable
 * @value: value of the variable
 * Return: (0) on success or (-1) on failure.
*/
int create_variable(const char *name, const char *value)
{
    char **new_environ;
    int environ_count = 0;
    char *new_entry;
    new_entry = (char *)malloc(strlen(name) + strlen(value) + 2); // memory allocution for the new variable and its value seperated by the = sign 
    if (new_entry == NULL)
    {
        perror("allocution failed\n");
        return -1;
    }
    sprintf(new_entry, "%s=%s", name, value); 
    while (environ[environ_count] != NULL)
    {
        environ_count++;                            //this loop counts the number of strings inside environ
    }

    new_environ = (char **)malloc(sizeof(char *) * (environ_count + 2)); // memory allocution for the new environment 
    if (new_environ == NULL)
    {
        perror("new environment memory allocution failed\n");
        return -1;
    }
    for (int i = 0; i < environ_count; i++)
    {
        new_environ[i] = environ[i];            //this content of eviron is copied into new_environ
    }
    new_environ[environ_count] = new_entry;
    new_environ[environ_count + 1]= NULL;
    
    environ = new_environ;              // change the environ to the new environ
    return 0;
}