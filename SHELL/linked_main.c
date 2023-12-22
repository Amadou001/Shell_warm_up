#include "shell.h"

int main(void)
{
    struct node *head;
    head = path_linked_list("PATH");
    print_node(head);
    free_linked_list(head);
}
