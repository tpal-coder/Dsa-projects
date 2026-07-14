#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int Data;
    struct Node *link;
} Node;
typedef struct Stack
{
    Node *Head;
    Node *Tail;
    int count;
} Stack;
void printLinkedList(Stack *l);
void insertFirst(Stack *l, int data);
void insertLast(Stack *l, int data);
void deleteFirst(Stack *l);
void deleteLast(Stack *l);
Stack *init();
void destroyList(Stack *l);
int main()
{
    Stack *l = init();
    if (l == NULL)
    {
        return 1;
    }

    insertFirst(l, 10);
    insertFirst(l, 20);
    insertFirst(l, 30);
    insertFirst(l, 40);
    insertFirst(l, 50);
    printLinkedList(l);

    deleteFirst(l);
    deleteFirst(l);
    deleteFirst(l);
    printLinkedList(l);

    insertLast(l, 60);
    insertLast(l, 70);
    insertLast(l, 80);
    insertLast(l, 90);
    printLinkedList(l);

    deleteLast(l);
    deleteLast(l);
    deleteLast(l);
    printLinkedList(l);

    destroyList(l);
    return 0;
}
void printLinkedList(Stack *l)
{
    if (l == NULL || l->Head == NULL)
    {
        printf("The list is empty...\n");
        return;
    }

    Node *temp = l->Head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->Data);
        temp = temp->link;
    }
    printf("NULL\n");
}
void insertFirst(Stack *l, int data)
{
    if (l == NULL)
        return;

    Node *new_node = (Node *)calloc(sizeof(Node), 1);
    if (new_node == NULL)
    {
        printf("Allocation failed...\n");
        return;
    }

    new_node->Data = data;
    if (l->count == 0)
    {
        l->Head = l->Tail = new_node;
    }
    else
    {
        new_node->link = l->Head;
        l->Head = new_node;
    }
    l->count++;
}
void insertLast(Stack *l, int data)
{
    if (l == NULL)
    {
        return;
    }

    if (l->Head == NULL)
    {
        insertFirst(l, data);
    }
    else
    {
        Node *new_node = (Node *)calloc(sizeof(Node), 1);
        if (new_node == NULL)
        {
            printf("Allocation failed....\n");
            return;
        }

        new_node->Data = data;
        l->Tail->link = new_node;
        l->Tail = new_node;
        l->count++;
    }
}
void deleteFirst(Stack *l)
{
    if (l == NULL || l->Head == NULL)
    {
        printf("List is empty...\n");
        return;
    }

    Node *temp = l->Head;
    l->Head = l->Head->link;
    free(temp);
    l->count--;
    if (l->count == 0)
    {
        l->Tail = NULL;
    }
}
void deleteLast(Stack *l)
{
    if (l == NULL || l->Head == NULL)
    {
        printf("List is empty...\n");
        return;
    }

    Node *to_delete = l->Tail;
    if (l->count == 1)
    {
        l->Head = l->Tail = NULL;
    }
    else
    {
        Node *temp = l->Head;
        while (temp->link != l->Tail)
        {
            temp = temp->link;
        }
        l->Tail = temp;
        l->Tail->link = NULL;
    }

    free(to_delete);
    l->count--;
}
Stack *init()
{
    Stack *l = (Stack *)calloc(sizeof(Stack), 1);
    if (l == NULL)
    {

        printf("Allocation failed...\n");
        return NULL;
    }
    return l;
}
void destroyList(Stack *l)
{
    if (l == NULL)
    {
        return;
    }

    Node *current = l->Head;
    Node *next;
    while (current != NULL)
    {
        next = current->link;
        free(current);
        current = next;
    }
    free(l);
}
rent = next;
    }
    free(l);
}
