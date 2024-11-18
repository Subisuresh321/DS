#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *current;

void create() {
    int num;
    printf("\nEnter the number of elements in LL: ");
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(head == NULL) {
            head = current = newnode;
        } else {
            current->next = newnode;
            current = newnode;
        }
    }
}

void display() {
    current = head;
    while(current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

void insertBeg(int *num) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    (*num)++;
}

void insertEnd(int *num) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if(head == NULL) {
        head = newnode;
    } else {
        current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
    (*num)++;
}

void insertPos(int *num) {
    int pos;
    printf("\nEnter the pos to insert: ");
    scanf("%d", &pos);
    if(pos < 1 || pos > (*num) + 1) {
        printf("Enter a valid position\n");
        return;
    } else if(pos == 1) {
        insertBeg(num);
    } else {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data: ");
        scanf("%d", &newnode->data);
        current = head;
        for(int i = 1; i < pos - 1; i++) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
        (*num)++;
    }
}

void insert(int *num) {
    int inschoice;
    printf("\nWhere do you want to insert 1. At Beginning 2. At End 3. At a position: ");
    scanf("%d", &inschoice);
    switch(inschoice) {
        case 1: insertBeg(num); break;
        case 2: insertEnd(num); break;
        case 3: insertPos(num); break;
        default: printf("Enter a correct choice\n"); break;
    }
}

void deleteBeg(int *num) {
    if(head == NULL) {
        printf("List is empty\n");
    } else {
        struct node *temp = head;
        head = head->next;
        free(temp);
        (*num)--;
    }
}

void deleteEnd(int *num) {
    if(head == NULL) {
        printf("List is empty\n");
    } else {
        if(head->next == NULL) {
            free(head);
            head = NULL;
        } else {
            current = head;
            while(current->next->next != NULL) {
                current = current->next;
            }
            free(current->next);
            current->next = NULL;
        }
        (*num)--;
    }
}

void delPos(int *num) {
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if(pos < 1 || pos > *num) {
        printf("Invalid position\n");
    } else if(pos == 1) {
        deleteBeg(num);
    } else {
        current = head;
        for(int i = 1; i < pos - 1; i++) {
            current = current->next;
        }
        struct node *temp = current->next;
        current->next = temp->next;
        free(temp);
        (*num)--;
    }
}

void delete(int *num) {
    int delchoice;
    printf("\nWhere do you want to delete 1. At Beginning 2. At End 3. At a position: ");
    scanf("%d", &delchoice);
    switch(delchoice) {
        case 1: deleteBeg(num); break;
        case 2: deleteEnd(num); break;
        case 3: delPos(num); break;
        default: printf("Enter a correct choice\n"); break;
    }
}

int main() {
    int num = 0;
    int op = 0;
    while(op != 5) {
        printf("\nEnter an option:\t1.Create\t2.Display\t3.Insert\t4.Delete\t5.Exit\n");
        scanf("%d", &op);
        switch(op) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(&num); break;
            case 4: delete(&num); break;
            case 5: break;
            default: printf("Enter a valid option\n"); break;
        }
    }
    return 0;
}
