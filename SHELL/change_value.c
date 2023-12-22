#include "shell.h"
/**
 * change_value - changes the value of an existing variable
 * @value: the new value to assign to the variable
 * @token: the name of the variable
 * @len: length of the variable'name
 * Return: the address of the new variable
*/
char *change_value(const char *value, char *token, ssize_t len)
{
char *new_entry;
new_entry = (char *)malloc(strlen(value) + len + 2);
if (new_entry ==  NULL)
{
    perror("memory allocution failed\n");
    return NULL;
}
sprintf(new_entry, "%s=%s", token, value);
return new_entry;
}
