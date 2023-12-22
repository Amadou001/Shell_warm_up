#include "shell.h"

void print_node(struct node *head)
{
    struct node *temp;
    temp = head;
while (temp != NULL) // this loop stop to the second last node
{
    printf("%s\n", temp->dir);
    temp = temp->next;
}
}
