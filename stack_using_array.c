/*Implementation of stack using array*/

#include <stdio.h>
#include<stdlib.h>

#define SIZE 5
int top = -1;

void push(int stack[]);
void pop(int *stack);
void top_ele(int stack[]);
void display(int stack[]);

int main()
{
    int stack[SIZE], choice;
    do
    {
    printf("Enter the option\n1.push\n2.pop\n3.top_ele\n4.display\n5.exit\n");
    scanf("%d",&choice);
        switch(choice)
        {
            case 1: push(stack);
            break;
            case 2: pop(stack);
            break;
            case 3: top_ele(stack);
            break;
            case 4: display(stack);
            break;
            case 5: exit(0);
        }
    }while(choice > 0 && choice < 6);
    return 0;
}

void push(int stack[])
{
    if(top == SIZE-1)
    printf("Stack is full\n");
    else
    {
        int data;
        printf("Enter the data: ");
        scanf("%d",&data);
        stack[++top] = data;
    }
}

void pop(int *stack)
{
    if(top == -1)
    printf("Stack is empty\n");
    else
    top--;
}

void top_ele(int stack[])
{
    if(top == -1)
    printf("Stack is empty\n");
    else
    printf("top element in the stack: %d\n",stack[top]);
}

void display(int stack[])
{
    int i;
    if(top == -1)
    printf("stack is empty");
    else
    {
        printf("stack contains: ");
        for(i=0; i<=top; i++)
        printf("%d ",stack[i]);
    }
    printf("\n");
}