#include "shell.h"

void free_linked_list(struct node *head)
{
    struct node *temp;
    while (head != NULL)
    {
       temp = head;
       head = head->next;
       free(temp->dir);
       free(temp); 
    }
}
