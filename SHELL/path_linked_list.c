#include "shell.h"


struct node *path_linked_list(char *path)
{
    struct node *head, *temp, *node;
    char *path_value, *token;
    path_value = _getenv(path); // get the value of path and store it to path_value
    if (path_value == NULL)
    {
        fprintf(stderr, "Environment variable %s not found\n",path);
        return NULL;
    }
    token = strtok(path_value, ":"); // first directory in path_value is stored in token
    node = create_node(token);  // creation of the first token
    head = node;                // pointing head to the first node
    token = strtok(NULL, ":");  // get the second directory in path_value
    while (token != NULL)
    {
        insert_node_end(&head, token);  // this loop the create a new node and insert it to the list untill token becomes NULL
        token = strtok(NULL, ":");
    }

   return head; 
}
