#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_cll(struct node *start);
struct node *disply_cll(struct node *start);
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
struct node *delete_beg(struct node *start);
struct node *delete_end(struct node *start);
int main(int argc, char const *argv[])
{
    int option;

    top:

    printf("\n********MAiN OPTION**********");
    printf("\n1. Create a list");
    printf("\n2. Display a list");
    printf("\n3. Insert at the beginning");
    printf("\n4. insert at the end");
    printf("\n5. Delete beg node");
    printf("\n6. Delete lst node");
    scanf("%d", &option);

    switch (option)
    {
    case 1: start = create_cll(start);
            printf("\nLinked list created");
        break;
    case 2:start = disply_cll(start);
        break;
    case 3:start= insert_beg(start);
        break;
    case 4:start = insert_end(start);
        break;
    case 5:start = delete_beg(start);
        break;
    case 6:start = delete_end(start);
    default:
        break;
    }
    goto top;
    return 0;
}
struct node *create_cll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter data");
    scanf("%d",&num);
    while (num!=-1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start==NULL)
        {
            new_node->next=new_node;
            start=new_node;
        }else
        {
           ptr =insert_end(ptr);
        }
        printf("\nEnter the data: ");
        scanf("%d", &num);
    }
    return start;
}
struct node *disply_cll(struct node *start)
{
    struct node *ptr;

    if (start==NULL)
    {
        printf("\nLinked list empty");
    }else
    {
        while (ptr->next!=start)
        {
            printf("%d\t", ptr->data);
            ptr=ptr->next;
        }
        
    }
    printf("\t%d", ptr->data);
    return start;
    
}
struct node *insert_beg(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\nEnter the data");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data =num;
    ptr = start;

    while (ptr->next != start)
    {
        ptr=ptr->next;
    }
    ptr->next = new_node;
    new_node->next =start;
    start=new_node;
    return start;   
}
struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;

    printf("\nEnter data");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr =start;

    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next=start;
    return start;
    
}
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    
    while (ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next = start->next;
    free(start);
    start = ptr;
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;

    ptr= start;
    while (ptr->next!=start)
    {
        preptr = ptr;
        ptr=ptr->next;
    }
    preptr->next = start;
    free(ptr);
    return start;
}