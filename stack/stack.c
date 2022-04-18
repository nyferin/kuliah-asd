#include <stdio.h>
#include <string.h>
#define MAX_STACK 5

typedef struct
{
    int top;
    char data[5][5];
}STACK;

STACK tumpuk;

void init()
{
    tumpuk.top = -1;
}

int isFull()
{
    if(tumpuk.top == MAX_STACK -1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(tumpuk.top == -1)
        return 1;
    else
        return 0;
}

void Push(char d[5])
{
    tumpuk.top++;
    strcpy(tumpuk.data[tumpuk.top], d);
}

void Pop()
{
    printf("Data yang diambil = %s\n", tumpuk.data[tumpuk.top]);
    tumpuk.top--;
}

void printData()
{
    for(int i=tumpuk.top; i >= 0; i--)
    {
        printf("Data: %s\n", tumpuk.data[i]);
    }
}

void delData()
{
    tumpuk.top = -1;
}

int main(void)
{
    int pilihan;
    init();
    char dt[5];
    do
    {
        printf("1. Push\n2 .Pop\n3. Print data\n4. Delete data\n5. EXIT\n");
        printf("Pilihan anda: ");
        scanf("%d", &pilihan);
        
        switch(pilihan)
        {
            case 1: if(isFull() != 1)
            {
                printf("Data yang ingin diinput = ");
                scanf("%s", dt);
                Push(dt);
            } else
            {
                printf("Stack penuh\n");
            }
            break;
            case 2: if(isEmpty() != 1)
            {
                Pop();
            } else
            {
                printf("Stack masih kosong\n");
            }
            break;
            case 3: if(isEmpty() != 1)
            {
                printData();
            } else
            {
                printf("Masih kosong!\n");
            }
            break;
            case 4: delData();
                    printf("Data sudah dihapus\n");
            break;
            default:
            break;
        }
    } while(pilihan != 5);
    printf("Hello World");

    return 0;
}