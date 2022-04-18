#include <stdio.h>
#define MAX 3

typedef struct {
    int data[MAX];
    int head;
    int tail;
} queue;

queue Que;

void begin() {
    Que.head = Que.tail = -1;
}

int empty() {
    if(Que.head == -1) {
        return 1;
    } else {
        return 0;
    }
}

int full() {
    if(Que.tail == MAX-1) {
        return 1;
    } else {
        return 0;
    }
}

int enqueue(int d) {
    if(empty() == 1) {
        Que.head = Que.tail = 0;

        Que.data[Que.tail] = d;

        printf("%d queued.\n", Que.data[Que.tail]);

        void printque();
        {
            if(empty() == 0) {
                for( int i = Que.head; i <= Que.tail;i++) {
                    printf("%d\t", Que.data[i]);
                }
            } else {
                printf("Queue empty");
            }
        }
    } else if (full() == 0) {
        Que.tail++;
        Que.data[Que.tail]=d;
        printf("%d queued.\n", Que.data[Que.tail]);
    }
}

int dequeue() {
    int queued = Que.data[Que.head];

    if(empty() == 0) {
        for(int i = Que.head; i <= Que.tail; i++) {
            Que.data[i] = Que.data[i+1];
        }
        Que.tail--;
        return queued;

    } else {
        printf("Queue empty\n");
        return 0;
    }
}
 /*
void printd() {
    if(empty() == 0) {
        for(int i = Que.head; i <= Que.tail; i++) {
            printf("%d\t", &Que.data[i]);
        }
    } else {
        printf("No queued data\n");
    }
}
*/

void printd() {
    if(empty() == 0) {
        printf("Print queued data: ");
        for(int i = Que.tail; i >= Que.head; i--) {
            printf("%d\t", Que.data[i]);
        }
        printf("\n\n");
    } else {
        printf("No queued data\n\n");
    }
}

void delete() {
    begin();
}

int main(void) {
    int choice, data;
    begin();

    do {
    printf("[1] Enqueue 1 data\n");
    printf("[2] Dequeue 1 data\n");
    printf("[3] Print queued data(s)\n");
    printf("[4] Delete queue data(s)\n");
    printf("[5] EXIT\n");
    printf("[*] Input your choide: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Input data: ");
            scanf("%d", &data);
            enqueue(data);
        break;
        case 2:
            printf("Dequeued data: %d\n\n", dequeue());
        break;
        case 3:
            printd();
        break;
        case 4:
            delete();
            printf("Queued data cleared\n\n");
        break;

    }
    } while(choice != 5);

    return 0;
}