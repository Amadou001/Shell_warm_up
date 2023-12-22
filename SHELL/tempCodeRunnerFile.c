#include "shell.h"

void insert_node_end(struct node **head, char *str)
{
    struct node *newnode, *temp;
    newnode = create_node(str);
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    temp = *head;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newnode;
}