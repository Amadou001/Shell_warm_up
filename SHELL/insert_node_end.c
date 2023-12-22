#include "shell.h"

void insert_node_end(struct node **head, char *str)
{
    struct node *newnode, *temp;
    newnode = create_node(str);
    if (newnode == NULL)
    {
        perror("node creation failed\n");
        return;
    }
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    temp = *head;
    while (temp->next != NULL) // this is for traversing the nodes untill we find NULL
    {
        temp = temp->next;
    }
    
    temp->next = newnode; // change NULL to the address of the new node
}