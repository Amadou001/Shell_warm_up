#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char *dir;
    struct node *next;
};

extern char **environ;
char *_getenv(const char *name);
void print_path(char *path);
struct node *create_node(char *str);
void print_node(struct node *head);
void insert_node_end(struct node **head, char *str);
struct node *path_linked_list(char *path);
void free_linked_list(struct node *head);
int _setenv(const char *name, const char *value, int overwrite);
char *change_value(const char *value, char *token, ssize_t len);
int create_variable(const char *name, const char *value);


#endif