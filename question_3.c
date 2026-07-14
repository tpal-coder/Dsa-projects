#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int Data;
    struct Node *Link;
} Node;
typedef struct Stack
{
    int Length;
    Node *Head;
} Stack;

void push(Stack *s, int data);
int pop(Stack *s);
int isEmpty(Stack *s);
void destroyList(Stack *l);
Stack *init();
void displayStack(Stack *s);

int main()
{
    // Menu
    int n = 1;
    Stack *s = NULL;
    while (n)
    {
        printf("\n\t<Menu>\n");
        printf("1.Init stack\n2.Push\n3.Pop\n4.Display\n5.Exit\n");
        int operation = 0;
        printf("Enter operation: ");
        if ((scanf("%d", &operation) != 1))
        {
            while (getchar() != '\n')
                ;
            continue;
        }

        int data;
        int *temp;
        switch (operation)
        {
        case 1:
            if (s != NULL)
            {
                destroyList(s);
                printf("Stack is reseted...\n");
            }

            s = init();
            if (s != NULL)
            {
                printf("Init done successfully...\n");
            }
            else
            {
                printf("Init failed...\n");
            }

            break;
        case 2:
            if (!s)
            {
                printf("Start init first\n");
                continue;
            }
            else
            {
                printf("Enter data for push: ");
                scanf("%d", &data);
                push(s, data);
            }
            break;
        case 3:
            if (!s || isEmpty(s))
            {
                printf("The stack-underflow\n");
            }
            else
            {
                printf("The data after pop: %d\n", pop(s));
            }
            break;
        case 4:
            if (s != NULL)
            {
                printf("===Display===\n");
                displayStack(s);
            }
            else
            {
                printf("Start init first\n");
            }
            break;
        case 5:
            n = 0;
            break;
        default:
            printf("Invalid operation choice.\n");
            break;
        }
    }
    if (s != NULL)
    {
        destroyList(s);
    }

    return 0;
}
void destroyList(Stack *s)
{
    if (s == NULL)
    {
        return;
    }

    Node *current = s->Head;
    Node *next;
    while (current != NULL)
    {
        next = current->Link;
        free(current);
        current = next;
    }
    free(s);
}
void push(Stack *s, int data)
{
    if (s == NULL)
    {
        return;
    }
    
    Node *newNode = (Node *)calloc(sizeof(Node), 1);
    newNode->Data = data;
    newNode->Link = s->Head;
    s->Head = newNode;
    (s->Length)++;
}
int pop(Stack *s)
{
    Node *temp = s->Head;
    s->Head = s->Head->Link;
    int data = temp->Data;
    free(temp);
    (s->Length)--;
    return data;
}
void displayStack(Stack *s)
{
    if (isEmpty(s))
    {
        printf("The stack is empty\n");
        return;
    }
    Node *temp = s->Head;
    while (temp != NULL)
    {
        printf("| %d |\n", temp->Data);
        temp = temp->Link;
    }
    printf("------\n");
}
int isEmpty(Stack *s)
{
    return (s == NULL || s->Length == 0 || s->Head == NULL);
}
Stack *init()
{
    Stack *s = (Stack *)calloc(sizeof(Stack), 1);
    return s;
}loc(sizeof(Stack), 1);
    return s;
}