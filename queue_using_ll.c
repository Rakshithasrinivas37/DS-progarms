/*Implementation of queue using linked list*/

#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}queue;

void enqueue(queue **front,queue **rear);
void dequeue(queue **front,queue **rear);
void front_ele(queue **front,queue **rear);
void display(queue **front,queue **rear);

int main()
{
    int choice;
    queue *front=NULL, *rear=NULL;
    do
    {
    printf("Enter the option\n1.enqueue\n2.dequeue\n3.front_ele\n4.display\n5.exit\n");
    scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue(&front,&rear);
            break;
            case 2: dequeue(&front,&rear);
            break;
            case 3: front_ele(&front,&rear);
            break;
            case 4: display(&front,&rear);
            break;
            case 5: exit(0);
        }
    }while(choice > 0 && choice < 6);
    return 0;
}

void enqueue(queue **front,queue **rear)
{
    queue *newnode = (queue *)malloc(sizeof(queue));
    if(newnode == NULL)
    printf("Memory is not allocated\n");
    else
    {
        int data;
        printf("Enter the data: ");
        scanf("%d",&data);
        newnode->data = data;
        newnode->next = NULL;
        if(*front == NULL && *rear == NULL)
        {
            *front = newnode;
            *rear = newnode;
        }
        else
        {
            (*rear)->next = newnode;
            *rear = (*rear)->next;
        }
    }
}

void dequeue(queue **front,queue **rear)
{
    if(*front == NULL && *rear == NULL)
    printf("Queue is empty\n");
    else
    {
        queue *temp;
        if(*front == *rear)
        {
            temp = *front;
            *front = NULL;
            *rear = NULL;
        }
        else
        {
            temp = *front;
            *front = (*front)->next;
        }
        printf("The dequeued element is: %d\n",temp->data);
        free(temp);
    }
}

void front_ele(queue **front,queue **rear)
{
    if(*front == NULL && *rear == NULL)
    printf("queue is empty\n");
    else
    printf("front element in the queue is: %d\n",(*front)->data);
    
}

void display(queue **front,queue **rear)
{
    if(*front == NULL && *rear == NULL)
    printf("queue is empty");
    else
    {
        printf("Queue contains: ");
        queue *temp = *front;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}