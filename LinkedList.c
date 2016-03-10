#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int id;
    int freq;
    struct ListNode* next;
};

struct ListNode *head, *tail;


void Insert(int data)
{
    if(head==NULL)
    {
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->id = data;
        temp->freq = 1;
        temp->next = NULL;
        head = temp;
        tail = temp;
    }
    else
    {
        struct ListNode* temp = head;
        while(temp->next != NULL)
        {
            if(temp->id == data) break;
            temp = temp->next;
        }
        if(temp->id==data)
        {
            temp->freq++;
        }
        else
        {
            struct ListNode* temp1 = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp1->id = data;
            temp1->freq = 1;
            temp1->next = NULL;
            temp->next = temp1;
            tail = temp1;
        }
    }

    Print(head);
}


void Delete(int data)
{
    struct ListNode* temp = head;
    struct ListNode* left;
    while(temp != NULL)
    {
        if(temp == head->next) left = head;
        else left = left->next;
        if(temp->id == data) break;
        temp = temp->next;
    }

    if(temp==NULL)
    {
        printf("Not Found\n");
    }
    else if(temp->id==data)
    {
        if(temp->freq>1) temp->freq--;
        else
        {
            if(temp == head)
            {
                free(temp);
                head = NULL;
                tail = NULL;
            }
            else if(temp->next==NULL)
            {
                left->next = NULL;
                tail = left;
                free(temp);
            }
            else
            {
                struct ListNode* temp1 = temp->next;
                left->next = temp1;
                free(temp);
            }
        }

        Print();
    }
}


void Find(int data)
{
    struct ListNode* temp = head;
    while(temp != NULL)
    {
        if(temp->id == data) break;
        temp = temp->next;
    }

    if(temp==NULL)
    {
        printf("Frequency of data with id = %d is 0\n",data);
    }
    else if(temp->id==data)
    {
        printf("Frequency of data with id = %d is %d\n",data, temp->freq);
    }
}


void Print()
{
    struct ListNode* temp = head;
    if(temp == NULL)
    {
        printf("List is Empty!!\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d %d\n",head, head->next);
        printf("<%d, %d> ", temp->id, temp->freq);
        temp = temp->next;
    }
    printf("\n");
}


void Reverse()
{
    struct ListNode* left = NULL;
    struct ListNode* current = head;
    struct ListNode* right;
    while (current != NULL)
    {
        right = current->next;
        current->next = left;
        left = current;
        current = right;
    }

    head = left;

    Print();
}

int main()
{
    head = NULL;
    tail = NULL;
    char cmd;
    while(1)
    {
        scanf("%c",&cmd);
        if(cmd == 'I')
        {
            int data;
            scanf("%d",&data);

            Insert(data);
        }
        else if(cmd == 'D')
        {
            int data;
            scanf("%d",&data);

            Delete(data);
        }
        else if(cmd == 'F')
        {
            int data;
            scanf("%d",&data);

            Find(data);
        }
        else if(cmd == 'R')
        {
            Reverse();
        }
        else if(cmd == 'T')
        {
            break;
        }
    }
}
