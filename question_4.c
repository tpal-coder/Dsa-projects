#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
} Node;

void insert(Node **root, int data);
void in_order(Node *root);
void pre_order(Node *root);
void post_order(Node *root);
void destroyTree(Node *root);


int main()
{
    Node *root = NULL;

    printf("Values are inserted: 21, 5, 15, 10, 23, 29\n");

    insert(&root, 21);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 10);
    insert(&root, 23);
    insert(&root, 29);

    printf("In-order traversal: ");
    in_order(root);

    printf("\nPre-order traversal: ");
    pre_order(root);

    printf("\nPost-order traversal:");
    post_order(root);

    destroyTree(root);
    return 0;
}

void insert(Node **root, int data)
{
    if ((*root) == NULL)
    {
        (*root) = (Node *)calloc(sizeof(Node), 1);
        (*root)->data = data;
    }
    else if ((*root)->data > data)
    {
        insert(&((*root)->left), data);
    }
    else
    {
        insert(&((*root)->right), data);
    }
}
void in_order(Node *root)
{
    if (root != NULL)
    {
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
}
void pre_order(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}
void post_order(Node *root)
{
    if (root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->data);
    }
}
void destroyTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}Tree(root->right);
    free(root);
}