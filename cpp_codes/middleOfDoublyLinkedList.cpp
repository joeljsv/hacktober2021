/*
Problem statement - WAP to print the middle of a double linked list.
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* create(int* , int);
void display(struct node*);
int getMiddleElement(struct node*);

int main(){
    int n;
    printf("Enter size of list : ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    struct node* head = create(arr,n);
    printf("List :\n");
    display(head);
    int x = getMiddleElement(head);
    if(x == -1){
        printf("Even list! No middle element!\n");
    }
    else{
        printf("Midlle element = %d\n",x);
    }
    return 0;
}

struct node* create(int* arr, int n){
    struct node* head = NULL;
    struct node* ptr = NULL;
    for(int i=0;i<n;i++){
        if(!head){
            head = (struct node*)malloc(sizeof(struct node));
            head->data = arr[0];
            head->prev = NULL;
            head->next = NULL;
            ptr =head; 
        }
        else{
            struct node* newNode = (struct node*)malloc(sizeof(struct node));
            newNode->data = arr[i];
            newNode->prev = ptr;
            newNode->next = NULL;
            ptr = ptr->next = newNode;
        }
    }
    return head;
}

void display(struct node* head){
    while(head){
            printf("%d",head->data);
            if(head->next){
                printf(" -> <- ");
            }
            head=head->next;
    }
    printf("\n");
    return;
}

int getMiddleElement(struct node* head){
    struct node* front = head;
    struct node* rear = head;
    while(rear->next){
        rear = rear->next;
    }
    while(front!=rear){
        front = front->next;
        rear = rear->prev;
        if(rear == head){
            return -1;
        }
    }
    return front->data;
}