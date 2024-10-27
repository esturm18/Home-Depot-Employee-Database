#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
	char *firstName;
	char *lastName;
	char *dob; 
	char *position;
	int employeeNumber;//working on this part 
	struct Node *next; 
};

//Function prototypes
struct Node *initFirstNode(); 
struct Node *createEmployee(struct Node *firstNode, char *firstName, char *lastName, char *dob, char *position, int count); 
void searchEmployee(struct Node *firstNode, char *firstName, char *lastName);
void print(struct Node *firstNode);
void removeEmployee(struct Node *firstNode, char *firstName, char *lastName); 
