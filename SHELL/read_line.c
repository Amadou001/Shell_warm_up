#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *buffer = NULL;
    size_t len = 0;
    __ssize_t bytes_read;
    int character;

    while(1)
    {
        printf("$ ");
       bytes_read = getline(&buffer, &len, stdin);

        if(bytes_read == -1)
        {
            perror("Error\n");
            break;
        }
        if (bytes_read == 0)
        {
            printf("\n");
            break;
        }
        
        printf("Entered command : %s", buffer);
    }

    free(buffer);

    return 0;
}
