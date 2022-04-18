#include <stdio.h>
#include <stdlib.h>

void clear() //clear terminal or cmd
{
    #ifdef _WIN32 //if windows
    system("cls");
    #elif defined(__linux__) //if linux
    system("clear");
    #endif
}

void stop()
{
    printf("Tekan ENTER untuk melanjutkan");
    getchar();
    getchar();
}

struct node {
    int data;
    struct node *next;
};

struct node *head;

void create(void) {
    struct node *pointer, *temp;
    int item, check = 0;
    temp = (struct node *)malloc(sizeof(struct node *));

    clear();

    if(temp == NULL) {
        printf("OVERFLOW\n");
        stop();
    } else {
        printf("Input data: ");
        scanf("%d", &item);
        temp->data = item;

        if(head == NULL) {
            temp->next = NULL;
            head = temp;
            printf("INPUT SUCCEED!\n");
            stop();
        } else {
            pointer = head;
            while(pointer->next != NULL) {
                pointer = pointer->next;
                if(pointer->data == temp->data) {
                    check = 1;
                }
            }
            if(check == 1) {
                printf("DUPLICATE DATA DETECTED!\n");
                stop();
            } else {
                temp->next = NULL;
                pointer->next = temp;
                printf("INPUT SUCCEED!\n");
                stop();
            }
        }
    }
}

void read(void) {
    struct node *pointer;
    pointer = head;

    clear();

    if (pointer == NULL) {
        printf("NO DATA!\n");
        stop();
    } else {
        printf("Data: ");
        while(pointer != NULL) {
            if(pointer->next != NULL) {
                printf("%d - ", pointer->data);
            } else {
                printf("%d\n", pointer->data);
            }
            pointer = pointer->next;
        }
        stop();
    }
    
}

void update(void) {
    struct node *pointer, *temp;
    int itemOld, itemNew, check = 0, found = 0;
    pointer = head;
    temp = head;

    clear();

    if(pointer == NULL) {
        printf("OVERFLOW\n");
        stop();
    } else if(head == NULL) {
            printf("NO DATA DETECTED!\n");
            stop();
    } else {
        printf("Input data to update: ");
        scanf("%d", &itemOld);

        while(pointer->next != NULL) {
            pointer = pointer->next;
            if(pointer->data == itemOld) {
                found++;
                printf("Old data: %d\n", itemOld);
                printf("Input new data: ");
                scanf("%d", &itemNew);

                while (temp->next != NULL) {
                    temp = temp->next;
                    if(temp->data == itemNew) {
                        check = 1;
                    }
                }
                if(check == 1) {
                    printf("DUPLICATE DATA DETECTED!\n");
                    stop();
                } else {
                    pointer->data = itemNew;
                    printf("INPUT SUCCEED!\n");
                    stop();
                }
            }
        }
        if(found == 0) {
            printf("NO DATA FOUND!\n");
            stop();
        }
    }
}

void delet() {
    struct node *pointer, *previous, *current;
    int item, check = 0, found = 0, position = 0, number = 1;
    pointer = head;
    previous = head;
    current = head;

    clear();

    if(pointer == NULL) {
        printf("OVERFLOW\n");
        stop();
    } else if(head == NULL) {
            printf("NO DATA DETECTED!\n");
            stop();
    } else {
        printf("Input data to delete: ");
        scanf("%d", &item);

        while(pointer->next != NULL) {
            pointer = pointer->next;
            if(pointer->data == item) {
                position = number;
                printf("Data: %d", pointer->data);
                found = 1;
            }
            position++;
        }
        if(found == 0) {
            printf("NO DATA FOUND!\n");
            stop();
        } else {
            if(position == 0) {
                head = current->next;
                free(current);
                current = NULL;
            } else
            {
                while (position != 0)
                {
                    previous = current;
                    current = current->next;
                    position--;
                }
                previous->next = current->next;
                free(current);
                current = NULL;
            }
        }
    }
}

int main(void) {
    int choice = -1;
    do {
        clear();

        printf("[1] Input data\n");
        printf("[2] Print data\n");
        printf("[3] Update data\n");
        printf("[4] Delete data\n");\
        printf("[0] EXIT\n");
        printf("[*] Input: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        
        case 2:
            read();
            break;

        case 3:
            update();
            break;

        case 4:
            delet();
            break;

        default:
            break;
        }
    } while(choice != 0);
    return 0;
}