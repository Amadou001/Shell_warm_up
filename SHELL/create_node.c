#include "shell.h"

struct node *create_node(char *str)
{
    struct node *node;
    size_t len = strlen(str);
    node = (struct node *)malloc(sizeof(struct node));
    if (node == NULL)
    {
        perror("allocution failed!\n");
        return NULL;
    }
    node->dir =(char *)malloc(sizeof(char) * len); // allocution of memory to node->dir is crutial to avoid segmentation default.
    if (node->dir == NULL)
    {
        perror("allocution failed\n");
        return NULL;
    }
    strcpy(node->dir, str);
    node->next = NULL;

    return node;
}