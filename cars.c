// newly modified
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10
struct details
{
    char type[max], brand[max], regis[max];
};
typedef struct details d;
struct queue
{
    d cars[max];
    int front, rear;
};
typedef struct queue q;
int isfull(q q1)
{
    if (q1.rear == max - 1)
        return 1;
    else
        return 0;
}
void EnterCarDetails(d *p)
{
    printf("Enter car type:\n");
    scanf("%s", p->type);
    printf("Enter car registration no.:\n");
    scanf("%s", p->regis);
    printf("Enter car brand:\n");
    scanf("%s", p->brand);
}
void CarEnter(q *p)
{
    if (isfull(*p) == 1)
        printf("The parking space is full\n");
    else
    {
        d newcar;
        EnterCarDetails(&newcar);
        p->rear++;
        p->cars[p->rear] = newcar;
    }
}
int isempty(q q1)
{
    if (q1.front > q1.rear)
        return 1;
    else
        return 0;
}
d CarExit(q *p)
{
    d emptyCar = {"", "", ""};
    if (isempty(*p) == 1)
    {
        printf("Parking is empty\n");
        return emptyCar;
    }

    else
    {
        d exitingCar = p->cars[p->front];
        printf("Car exiting:\n");
        printf("Type:%s\n", exitingCar.type);
        printf("Brand:%s\n", exitingCar.brand);
        printf("Registration Number:%s\n", exitingCar.regis);
        p->front++;
    }
}
void DisplayCars(q queue)
{
    if (isempty(queue))
    {
        printf("no cars in the parking lot.\n");
    }
    else
    {
        printf("cars in the parking lot:\n");
        for (int i = queue.front; i <= queue.rear; i++)
        {
            printf("Car Type:%s, Brand:%s,Registration:%s\n", queue.cars[i].type, queue.cars[i].brand, queue.cars[i].regis);
        }
    }
}

int SearchCar(q queue, char regist[])
{
    for (int i = queue.front; i <= queue.rear; i++)
    {
        if (strcmp(queue.cars[i].regis, regist) == 0)
        {
            return i - queue.front + 1;
        }
    }
    return -1;
}
void main()
{
    q q1;
    q1.front = 0;
    q1.rear = -1;
    int choice;
    char registration[10];
    while (1)
    {
        printf("Enter the operation:\n");
        printf("1. Add a car to the parking lot\n");
        printf("2. Remove a car from the parking lot\n");
        printf("3. Search for a car by registration number\n");
        printf("4. Display all cars in the parking lot\n");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            printf("Car enters\n");
            CarEnter(&q1);
            break;
        case 2:
            printf("Car leaves\n");
            CarExit(&q1);
            break;
        case 3:
            printf("enter registration number:");
            scanf("%s", registration);
            int position = SearchCar(q1, registration);
            if (position == -1)
            {
                printf("Car not found.\n");
            }
            else
            {
                printf("Car found at position %d.\n", position);
            }
            break;
        case 4:
            DisplayCars(q1);
            break;
        default:
            printf("Invalid operation\n");
            exit(0);
        }
    }
}