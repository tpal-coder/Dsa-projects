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
void reverseList(Stack *l);
void insertAtPosition(Stack *l, int position, int data);
void deleteAtPosition(Stack *l, int position);
Stack *init();
void destroyList(Stack *l);

int main()
{
    Stack *l = init();
    if (l == NULL)
    {
        return 1;
    }

    printf("The first values are inserted and printed:\n");
    insertFirst(l, 10);
    insertFirst(l, 20);
    insertFirst(l, 30);
    insertFirst(l, 40);
    insertFirst(l, 50);
    printLinkedList(l);

    printf("The first values are deleted and printed:\n");
    deleteFirst(l);
    deleteFirst(l);
    deleteFirst(l);
    printLinkedList(l);

    printf("The values are inserted at last and printed:\n");
    insertLast(l, 60);
    insertLast(l, 70);
    insertLast(l, 80);
    insertLast(l, 90);
    printLinkedList(l);

    printf("The last values are deleted and printed:\n");
    deleteLast(l);
    deleteLast(l);
    deleteLast(l);
    printLinkedList(l);

    printf("Inserted at position: 2 value: 30\n");
    insertAtPosition(l, 2, 30);
    printLinkedList(l);
    printf("Inserted at position: 1 value: 40\n");
    insertAtPosition(l, 1, 40);
    printLinkedList(l);

    printf("Deleted at position: 3\n");
    deleteAtPosition(l, 3);
    printLinkedList(l);
    printf("Deleted at position: 2\n");
    deleteAtPosition(l, 2);
    printLinkedList(l);

    printf("Inserted at position: 2 value: 70\n");
    insertAtPosition(l, 2, 70);
    printLinkedList(l);
    printf("Inserted at position: 1 value: 90\n");
    insertAtPosition(l, 1, 90);
    printLinkedList(l);

    printf("The list is reversed and printed:\n");
    reverseList(l);
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
void reverseList(Stack *l)
{
    if (l == NULL || l->Head == NULL || l->count < 2)
    {
        return;
    }

    Node *current = l->Head;
    Node *prev = NULL;
    Node *next = NULL;
    l->Tail = current;
    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    l->Head = prev;
}
void insertAtPosition(Stack *l, int position, int data)
{
    if (l == NULL || position > l->count + 1 || position < 1)
    {
        printf("Invalid index of Node.\n");
        return;
    }
    else if (position == 1)
    {
        insertFirst(l, data);
    }
    else if (position == l->count + 1)
    {
        insertLast(l, data);
    }
    else
    {
        Node *new_node = (Node *)calloc(sizeof(Node), 1);
        if (new_node == NULL)
        {
            printf("Allocation failed...\n");
            return;
        }
        new_node->Data = data;

        Node *prev;
        prev = l->Head;
        for (int i = 1; i < position - 1; i++)
        {
            prev = prev->link;
        }
        new_node->link = prev->link;
        prev->link = new_node;
        l->count++;
    }
}
void deleteAtPosition(Stack *l, int position)
{
    if (l == NULL || position > l->count || position < 1)
    {
        printf("Invalid position of Node.\n");
        return;
    }
    else if (position == 1)
    {
        deleteFirst(l);
    }
    else if (position == l->count)
    {
        deleteLast(l);
    }
    else
    {
        Node *target, *prev;
        prev = l->Head;
        for (int i = 1; i < position - 1; i++)
        {
            prev = prev->link;
        }
        target = prev->link;
        prev->link = target->link;
        free(target);
        l->count--;
    }
}(target);
        l->count--;
    }
}