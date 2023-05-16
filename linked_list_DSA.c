#include <stdio.h>
#include <stdlib.h>


struct Node{
    struct Node* next;
    int data;
};


struct Node* start = NULL;

void insert(int key){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new -> data = key;
    new -> next = start;
    start = new;
}

int getMin(){
    struct Node* temp = start;

    if (temp == NULL){
        printf("Underflow\n");
        return NULL;
    }

    int min = temp-> data;
    while(temp != NULL){
        if(temp -> data < min){
            min = temp -> data;
        }
        temp = temp -> next;
    }
    return min;
}

void delete(){
    struct Node* temp = start;
    struct Node* prev = NULL;
    int min = getMin();

    if (min == NULL){
        return;
    }

    while(temp -> data != min){
        prev = temp;
        temp = temp -> next;
    }

    if (prev == NULL){
        start = temp -> next;
    }
    else{
        prev -> next = temp -> next;
    }
    printf("Deleted %d\n", temp -> data);
    free(temp);
}

void display(){
    struct Node* temp = start;
    while(temp != NULL){
        printf("%d \n", temp->data);
        temp = temp-> next;
    }
}

void main(){
    int u = 4;
    while(1){
        printf("\n1. Add Number\n2. Delete Minimum\n3. Display List\n4. Exit\n\n>> ");
        scanf("%d",&u);
        switch(u){
            case 1:
                int key;
                printf("Enter the number to be inserted: ");
                scanf("%d",&key);
                insert(key);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return;
        }
    }
}