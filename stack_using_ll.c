/*Implementation of stack using linked list*/

#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void push(node **stack);
void pop(node **stack);
void top_ele(node **stack);
void display(node **stack);

int main()
{
    int choice;
    node *stack = NULL;
    do
    {
    printf("Enter the option\n1.push\n2.pop\n3.top_ele\n4.display\n5.exit\n");
    scanf("%d",&choice);
        switch(choice)
        {
            case 1: push(&stack);
            break;
            case 2: pop(&stack);
            break;
            case 3: top_ele(&stack);
            break;
            case 4: display(&stack);
            break;
            case 5: exit(0);
        }
    }while(choice > 0 && choice < 6);
    return 0;
}

void push(node **stack)
{
    int data;
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    if(newnode == NULL)
    printf("Memory is not allocated\n");
    else
    {
        printf("Enter the data: ");
        scanf("%d",&data);
        newnode->data = data;
        newnode->next = NULL;
        if(*stack == NULL)
        {
            *stack = newnode;
        }
        else
        {
            newnode->next = *stack;
            *stack = newnode;
        }
    }
}

void pop(node **stack)
{
    if(*stack == NULL)
    printf("Stack is empty\n");
    else
    {
        node *temp;
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

void top_ele(node **stack)
{
    if(*stack == NULL)
    printf("Stack is empty\n");
    else
    {
        printf("Top element in the stack is: %d\n",(*stack)->data);
    }
    
}

void display(node **stack)
{
    if(*stack == NULL)
    printf("Stack is empty");
    else
    {
        printf("Stack contains: ");
        node *temp = *stack;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}