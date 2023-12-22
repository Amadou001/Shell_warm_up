#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **string_split(const char *str, const char *delimiter, size_t *count)
{
char *input;
char **word = NULL;
char *token;
input = strdup(str);
token = strtok(input, delimiter);
*count = 0;
while(token != NULL)
{
word = realloc(word, (*count + 1) * (sizeof(char *)));
word[*count] = strdup(token);
token = strtok(NULL, delimiter);
(*count)++;
}
free(input);
return word;
}

int main()
{
const char *str = "Welcome to all of you";
const char *delimiter = " ";
size_t count;
char **words = string_split(str, delimiter, &count);
for (int i = 0; i < count; i++)
{
    printf("%s\n", words[i]);
}
for (int j = 0; j < count; j++)
{
free(words[j]);
}
free(words);
return 0;
}
