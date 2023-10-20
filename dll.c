#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

typedef struct double_ll
{
    int data;
    struct double_ll *prev;
    struct double_ll *next;
}dll;

void insert(dll **head);
void reverse(dll **head);
void mid_element(dll **head);
void count(dll **head);
void delete_alt_nodes(dll **head);
void display(dll **head);

int main()
{
    dll *head = NULL;
    int option;
    while(1)
    {
        printf("1. Insert\n2. Reverse\n3. Count nodes\n4. Find mid element\n5. Delete alternate nodes\n6. Display\n7. Exit\nEnter the option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: insert(&head);
                    break;
            case 2: reverse(&head);
                    break;
            case 3: count(&head);
                    break;
            case 4: mid_element(&head);
                    break;
            case 5: delete_alt_nodes(&head);
                    break;
            case 6: display(&head);
                    break;
            case 7: exit(1);
                    break;
        }
    }
}

void insert(dll **head)
{
    int data;
    printf("Enter the data to be inserted: ");
    scanf("%d", &data);
    dll *newnode = (dll *)malloc(sizeof(dll));
    if(newnode == NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = NULL;
        if(*head == NULL)
        {
            *head = newnode;
        }
        else
        {
            dll *temp = *head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}

void reverse(dll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        dll *temp = *head;
        dll *temp1 = NULL;
        dll *temp2 = NULL;
        while(temp != NULL)
        {
            temp2 = temp;
            temp1 = temp->next;
            temp->next = temp->prev;
            temp->prev = temp1;
            temp = temp->prev;
        }
        *head = temp2;
    }
}

void count(dll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        int count = 0;
        dll *temp = *head;
        while(temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        printf("No. of nodes = %d\n", count);
    }
}

void mid_element(dll **head)
{
   if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        dll *slow_ptr = *head;
        dll *fast_ptr = *head;
        while(slow_ptr->next != NULL && fast_ptr->next != NULL)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        printf("The mid element is %d\n", slow_ptr->data);
    } 
}

void delete_alt_nodes(dll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        dll *temp = *head;
        dll *temp1 = temp->next;
        while(temp->next != NULL)
        {
            temp->next = temp1->next;
            temp1->next->prev = temp;
            free(temp1);
            temp = temp->next;
            temp1 = temp->next;
        }
    }
}

void display(dll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        dll *temp = *head;
        printf("List elements are: ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}