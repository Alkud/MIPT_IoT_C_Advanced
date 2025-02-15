// Вид сверху
// В программе описана структура для хранения двоичного дерева:
// typedef struct tree {
//     datatype key;
//     struct tree *left, *right;
// } tree;
// Необходимо реализовать функцию, которая печатает вид дерева сверху. Функция должна строго соответствовать прототипу:
// void btUpView(tree *root)

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int datatype;

typedef struct tree {
    datatype key;
    struct tree* left;
    struct tree* right;
} tree;

tree* create_node(datatype key)
{
    tree* node = calloc(1, sizeof(tree));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void add_node(tree** root, datatype key)
{
    if (*root == NULL)
    {
        *root = create_node(key);
        return;
    }
    if (key < (*root)->key)
    {
        add_node(&((*root)->left), key);
    }
    else
    {
        add_node(&((*root))->right, key);
    }
}

void btUpView(tree* root)
{
    if (root == NULL)
    {
        return;
    }
    tree* up_view_current = calloc(1, sizeof(tree));
    up_view_current->key = root->key;
    up_view_current->left = NULL;
    up_view_current->right = NULL;
    tree* up_view_root = NULL;
    tree* root_current = root->left;
    while (root_current != NULL)
    {
        up_view_root = calloc(1, sizeof(tree));
        up_view_root->key = root_current->key;
        up_view_root->right = up_view_current;
        up_view_root->left = NULL;
        up_view_current = up_view_root;
        root_current = root_current->left;
    }
    while(up_view_current->right != NULL)
    {
        printf("%d ", up_view_current->key);
        up_view_current = up_view_current->right;
    }
    root_current = root;
    while(root_current != NULL)
    {
        printf("%d ", root_current->key);
        root_current = root_current->right;
    }
    printf("\n");
}

int main (void)
{
    char input_string[4095];
    fgets(input_string, 4095, stdin);
    char* number;
    number = strtok (input_string," .\n\r");
    tree* root = NULL;
    // создание дерева из введённой строки
    int n;
    while (number != NULL)
    {
        sscanf(number, "%d", &n);
        add_node(&root, n);
        number = strtok(NULL, " .\n\r");
    }
    btUpView(root);
    return 0;
}