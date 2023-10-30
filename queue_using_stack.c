#include <stdio.h>
#include<stdlib.h>

#define SIZE 5
int top1 = -1, top2 = -1, count = 0;
int stack1[SIZE], stack2[SIZE];

void enqueue();
void dequeue();
void push();
int pop1();
void pop2();
void print();

int main()
{
    int option;
    while(1)
    {
        printf("1.enqueue\n2.push\n3.dequeue\n4.print\n5.exit\n");
        printf("Enter option: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: enqueue();
            break;
            case 2: push();
            break;
            case 3: dequeue();
            break;
            case 4: print();
            break;
            case 5: exit(0);
            break;
        }
    }
}
void enqueue()
{
    int num;
    printf("Enter the element to be inserted: ");
    scanf("%d", &num);
    if(top1 == SIZE-1)
    {
        printf("Stack is full\n");
    }
    else
    {
        stack1[++top1] = num;
    }
    
}
int pop()
{
    if(top1 != -1)
    {
        return stack1[top1--];
    }
}
void push()
{
    while(top1 >= 0)
    {
        stack2[++top2] = pop();
    }
}

void dequeue()
{
    if(top2 == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Deleted element is %d\n", stack2[top2]);
        top2--;
        count--;
    }
}
void print()
{
    for(int i=top2;i>=0;i--)
    {
        printf("%d ",stack2[i]);
    }
    printf("\n");
}