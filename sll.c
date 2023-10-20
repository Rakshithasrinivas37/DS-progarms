#include <stdio.h>
#include <stdlib.h>

typedef struct single_ll
{
    int data;
    struct single_ll *link;
}sll;

void insert_at_first(sll **head);
void insert_at_last(sll **head);
void delete_at_first(sll **head);
void delete_at_last(sll **head);
void delete_alternate(sll **head);
void display(sll **head);
void reverse(sll **head);
void mid_element(sll **head);

int main()
{
    sll *head = NULL;
    int opt;
    while(1)
    {
    printf("1. Insert at first\n2. Insert at last\n3. Delete at first\n4. Delete at last\n5. Delete alternate nodes\n6. Reverse\n7. Mid element\n8. Display\n9. Exit\nEnter option: ");
    scanf("%d", &opt);
    switch(opt)
    {
        case 1: insert_at_first(&head);
        break;
        case 2: insert_at_last(&head);
        break;
        case 3: delete_at_first(&head);
        break;
        case 4: delete_at_last(&head);
        break;
        case 5: delete_alternate(&head);
        break;
        case 6: reverse(&head);
        break;
        case 7: mid_element(&head);
        break;
        case 8: display(&head);
        break;
        case 9: exit(1);
        break;
    }
    }
    return 0;
}

void insert_at_first(sll **head)
{
    int data;
    sll *new_node = (sll *)malloc(sizeof(sll));
    printf("Enter data: ");
    scanf("%d", &data);
    if(new_node == NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        new_node->data = data;
        new_node->link = NULL;
        if(*head == NULL)
        {
            *head = new_node;
        }
        else
        {
            new_node->link = *head;
            *head = new_node;
        }
    }
}

void insert_at_last(sll **head)
{
    int data;
    sll *new_node = (sll *)malloc(sizeof(sll));
    printf("Enter data: ");
    scanf("%d", &data);
    if(new_node == NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        new_node->data = data;
        new_node->link = NULL;
        if(*head == NULL)
        {
            *head = new_node;
        }
        else
        {
            sll *temp = *head;
            while(temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = new_node;
        }
    }
}

void delete_at_first(sll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = *head;
        *head = temp->link;
        printf("Deleted data: %d\n", temp->data);
        free(temp);
    }
}

void delete_at_last(sll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = *head;
        sll *prev = NULL;
        while(temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }
        prev->link = NULL;
        printf("Deleted data: %d\n", temp->data);
        free(temp);
    }
}

void delete_alternate(sll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = *head;
        sll *temp1 = (*head)->link;
        while(temp1 != NULL && temp != NULL)
        {
            temp->link = temp1->link;
            free(temp1);
            temp = temp->link;
            if(temp != NULL)
            {
                temp1 = temp->link;
            }
        }
    }
}

void reverse(sll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *prev = NULL;
        sll *curr = *head;
        sll *next = (*head)->link;
        while(curr != NULL)
        {
            curr->link = prev;
            prev = curr;
            curr = next;
            if(curr != NULL)
                next = curr->link;
        }
        *head = prev;
    }
}

void mid_element(sll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *slow_ptr = *head;
        sll *fast_ptr = *head;
        while(fast_ptr->link != NULL)
        {
            slow_ptr = slow_ptr->link;
            fast_ptr = slow_ptr->link->link;
        }
        printf("Mid element is %d\n", slow_ptr->data);
    }
}

void display(sll **head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = *head;
        printf("Elements are: ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}