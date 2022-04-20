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

void createHead(void) {
    struct node *pointer;
    int item;
    pointer = (struct node *) malloc(sizeof(struct node *));
    if(pointer == NULL)
    {
        printf("\n OVERFLOW");
        pause();
    }
    else
    {
        printf("Masukkan Data: ");
        scanf("%d", &item);
        pointer->data = item;
        pointer->next = head;
        head = pointer;
        printf("DATA SAVED AT HEAD!\n");
        pause();
    }
}

void createTail()
{
    struct node *pointer, *temp;
    int item;
    pointer = (struct node *) malloc(sizeof(struct node *));
     if(pointer == NULL)
    {
        printf("\n OVERFLOW");
        pause();
    }
    else
    {
        printf("Masukkan Data: ");
        scanf("%d", &item);
        pointer->data = item;
        if(head == NULL)
        {
            pointer->next = NULL;
            head = pointer;
            printf("DATA SAVED!");
            pause();
        }
        else
        {
            temp = head;
            while(temp -> next != NULL)
            {
                temp = temp->next;
            }
            temp->next = pointer;
            pointer->next = NULL;
            printf("DATA SAVED AT TAIL!\n");
            pause();
        }
    }
}

void createAny()
{
    int i, loc, item;
    struct node *pointer, *temp;
    pointer = (struct node *)malloc(sizeof(struct node));
    if(pointer == NULL)
    {
        printf("\n OVERFLOW");
        pause();
    }
    else
    {
        printf("Masukkan Data: ");
        scanf("%d", &item);
        pointer->data = item;
        printf("Simpan di lokasi: ");
        scanf("%d", &loc);
        temp = head;
        for(i = 0; i < loc; i++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("DATA NOT SAVED!\n");
                pause();
                return;
            }
        }
            pointer->next = temp->next;
            temp->next = pointer;
            printf("DATA SAVED!\n");
            pause();
    }
}

void read(void) {
    struct node *pointer;
    pointer = head;

    clear();

    if (pointer == NULL) {
        printf("NO DATA!\n");
        pause();
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
        pause();
    }
    
}

int main(void) {
    int choice = -1;
    do {
        clear();

        printf("MENU LINKED LIST\n\n");
        printf("[1] Input data at head\n");
        printf("[2] Input data at tail\n");
        printf("[3] Input data at any\n");
        printf("[4] Print data\n");
        printf("[0] EXIT\n");
        printf("[*] Input: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createHead();
            break;
            
        case 2:
            createTail();
            break;

        case 3:
            createAny();
            break;

        case 4:
            read();
            break;

        default:
            break;
        }
    } while(choice != 0);
    return 0;
}