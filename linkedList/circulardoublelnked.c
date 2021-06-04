#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct node *start= NULL;
struct node *create_cdll(struct node *start);
struct node *disply_cdll(struct node *start);

struct node 
{
    struct node *prev;
    int data;
    struct node *next;
};
int main(int argc, char const *argv[])
{
    int option;
    begin:
    printf("\n\t**************MAIN MENU**************");
    printf("\n1. Create a list");
    printf("\n2. Display the list");
    

    scanf("%d", &option);
    switch (option)
    {
    case 1:start    =create_cdll(start);
        break;
    case 2:start    =disply_cdll(start);
        break;
    
    default:

        break;
    }
    goto begin;
    return 0;
}
struct node *create_cdll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter data: ");
    scanf("%d", &num);

    while (num != -1)
    {
        if(start == NULL)
        {
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node->prev = start;
            new_node->data = num;
            new_node->next= start;
            start= new_node;
        }else
        {
            ptr = start;
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node->data = num;
            while (ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = start;
            start->prev = new_node;
            
        }
        printf("\nEnter the data: ");
        scanf("%d", &num);
    }
    printf("\nList created");
    return start;
}
struct node *disply_cdll(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if (ptr ==NULL)
        printf("\nThe list is empty");
    while (ptr->next!=NULL)
    {
        printf("%d\t", ptr->data);
        ptr=ptr->next;
    }
    printf("%d", ptr->data);
    return start;
}
