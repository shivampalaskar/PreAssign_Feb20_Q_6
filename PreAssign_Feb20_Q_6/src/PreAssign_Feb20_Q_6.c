/*
 ============================================================================
 Name        : PreAssign_Feb20_Q_6.c
 Author      : Shivam Palaskar
 Version     :
 Copyright   : Open source
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define SIZE 5
void enqueue();
void dequeue();
int isFull();
int isEmpty();
void display();
void printData();
void getData();

struct Student {
	int rollNo;
	char name[20];
	int std;
	char sub[6][20];
	int mark[6];
};
char subject[6][20] = { "Physics", "Chemistry", "Mathematics", "Environment",
			"Computer Science", "Sociology" };
struct Student student[SIZE];
int rear = -1, front = -1;

int menuList(){
	int choice;
	printf("\n\nChoose operation to perform: ");
	printf("\n1) Add a Student");
	printf("\n2) Remove a Student");
	printf("\n3) Display");
	printf("\n4) Exit");
	printf("\n Enter a Choice : ");
	scanf("%d", &choice);
	return choice;
}

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);

	int choice;
	do {
		choice = menuList();

		switch (choice) {
		case 1:
			if (isFull())
				printf("\nQueue is Full");
			else
				enqueue();
			break;
		case 2:
			if (isEmpty())
				printf("\nQueue is Empty");
			else
				dequeue();
			break;
		case 3:
			if (isEmpty())
				printf("\nQueue is Empty");
			else
				display();
		}
	} while (choice != 4);

	return EXIT_SUCCESS;
}

int isEmpty() {
	if (front == rear && rear == -1)
		return 1;
	else
		return 0;
}
int isFull() {
	if (((front - rear) == 1) || (front == 0 && (rear == SIZE - 1)))
		return 1;
	else
		return 0;
}

void getData() {
	printf("\nEnter Roll No : ");
	scanf("%d", &student[rear].rollNo);
	printf("\nEnter Name of Student : ");
	scanf("%s", student[rear].name);
	fflush(stdin);
	printf("\n Enter Standard of Student : ");
	scanf("%d", &student[rear].std);
	printf("\n Enter marks obtained by student : ");
	printf("\n Subject   Marks");
}

void enqueue() {
	rear = (rear + 1) % SIZE;
	getData();
	for(int i=0;i<6;i++){
		strcpy(student[rear].sub[i],subject[i]);
		printf("\n%d) %s ",i+1,subject[i]);
		scanf("%d",&student[rear].mark[i]);
	}
	if (front == -1)
		front++;
	printf("\n Student info is successfully added");
}

void dequeue() {
	if (front == rear)
		front = rear = -1; // It is almost like resetting the starting point of queue
	else
		front = (front + 1) % SIZE;
	printf("\n Student info is successfully Removed");
}

void display() {
	int r = rear, f = front;
	while (f != r) {
		printData();
		f = (f + 1) % SIZE;
	}
	printData();
}

void printData() {
	int f = front;
	printf("\n\n Student roll No : %d", student[f].rollNo);
	printf("\n Student Name : %s", student[f].name);
	printf("\n Student Standard : %d", student[f].std);
	printf("\n Student Subjects and Marks : ");
	printf("\n Subject   Marks");
	for (int i = 0; i < 6; i++) {
		printf("\n%d) %-s %d", i + 1, student[f].sub[i], student[f].mark[i]);
	}
}
