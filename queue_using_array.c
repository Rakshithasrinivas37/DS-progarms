/*Implementation of queue using array*/

#include <stdio.h>
#include<stdlib.h>
#define SIZE 5

int rear = -1;
int front = -1;

void enqueue();
void dequeue();
void front_ele();
void display();

int main()
{
    int choice;
    int queue[SIZE];
    do
    {
    printf("Enter the option\n1.enqueue\n2.dequeue\n3.front_ele\n4.display\n5.exit\n");
    scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue(queue);
            break;
            case 2: dequeue(queue);
            break;
            case 3: front_ele(queue);
            break;
            case 4: display(queue);
            break;
            case 5: exit(0);
        }
    }while(choice > 0 && choice < 6);
    return 0;
}

void enqueue(int *queue)
{
    if(rear == SIZE-1)
    printf("Queue is full\n");
    else
    {
        int data;
        printf("Enter the data: ");
        scanf("%d",&data);
        if(front == -1 && rear == -1)
        {
            front++;
            rear++;
            queue[rear] = data;
        }
        else
        queue[++rear] = data;
    }
        
}

void dequeue(int *queue)
{
    if(front == -1 && rear == -1)
    printf("Queue is empty\n");
    else
    {
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        front++;
    }
}

void front_ele(int *queue)
{
    if(front == -1 && rear == -1)
    printf("queue is empty\n");
    else
    printf("front element in the queue is: %d\n",queue[front]);
    
}

void display(int *queue)
{
    if(front == -1 && rear == -1)
    printf("queue is empty");
    else
    {
        printf("queue contains: ");
        for(int i=front; i<=rear; i++)
        printf("%d ",queue[i]);
    }
    printf("\n");
}