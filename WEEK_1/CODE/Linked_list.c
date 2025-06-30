#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
}__attribute__((packed)) node_s;

node_s *head = NULL;
int init(int data)
{
    if(head!=NULL)
    {
        printf("List alreday created\n");
        return -1;
    }
    head = malloc(sizeof(node_s));
    if(head==NULL)
    {
        printf("Memory not allocated\n");
        return -2;
    }
    head->data=data;
    head -> next = NULL;
    
   // printf("%d\n",head->data);
   // printf("%p\n",head->next);
}

int add(int data)
{
    node_s *new_node;
    new_node = malloc(sizeof(node_s));
    if(new_node==NULL)
    {
        printf("Meory not allocated\n");
        return -2;
    }
    new_node ->data = data;
    new_node -> next = head;
    head =new_node;
    return 0;
}
int add_at_end(int data)
{
    node_s *n,*p;
    n =malloc(sizeof(node_s));
    if(n==NULL)
    {
        printf("Memory allocation is Failed\n");
        return -1;
    }
    n -> data=data;
    n->next = NULL;
    for(p = head;p->next!=NULL;p=p->next)
    {
        /*Move to the last node*/
    }
    p->next = n;
    return 0;
}
int traverse()
{
    if(!head)
    {
        printf("List is empty\n");
        return -1;
    }
    for(node_s *cur = head ; cur !=NULL;cur = cur -> next)
    {
        printf("%d --> ",cur->data);
    }
    printf("NULL\n");
    return 0;
}
int main()
{
    init(100); 
    init(22);
    add(10);
    add(20);
    add(30);
    add_at_end(200);
    add_at_end(300);
    add_at_end(400);
    traverse();
    return 0;
}