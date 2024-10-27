#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"

struct Node *initFirstNode(){
	struct Node *temp = malloc(sizeof(struct Node));
       	temp->firstName = NULL;
	temp->lastName = NULL; 
	temp->dob = NULL; 
	temp->position = NULL;
	temp->next = NULL; 
	temp->employeeNumber=0; 
	return temp; 
}

struct Node *createEmployee(struct Node *firstNode, char *firstName, char *lastName, char *dob, char *position, int employeeNumber){
	struct Node *newNode = malloc(sizeof(struct Node));
	struct Node *temp = firstNode->next;
	while(temp!=NULL){
		if((strcmp(temp->firstName, firstName)==0) && (strcmp(temp->lastName, lastName)==0)){
			printf("Employee already in database\n"); 
			break; 
		}
		temp = temp->next; 
	}

	newNode->firstName = malloc(sizeof(strlen(firstName)));
	newNode->lastName = malloc(sizeof(strlen(lastName)));
	newNode->dob = malloc(sizeof(strlen(dob)));
	newNode->position = malloc(sizeof(strlen(position))); 
	strcpy(newNode->firstName, firstName); 
	strcpy(newNode->lastName, lastName);
	strcpy(newNode->dob, dob);
	strcpy(newNode->position, position); 
	newNode->employeeNumber = employeeNumber;
	newNode->next = firstNode->next;
	firstNode->next=newNode; 
	return firstNode; 
}	
void searchEmployee(struct Node *firstNode, char *firstName, char *lastName){
	struct Node *temp = firstNode->next; 
        int flag = 0;
	while(temp!=NULL){
		if(strcmp(temp->firstName, firstName)==0){
			printf("\nEmployee %s %s found in database\n", firstName, lastName);
			printf("\nEmployee %d\n", temp->employeeNumber);
			printf("First name: %s\n", temp->firstName); 
			printf("Last name: %s\n", temp->lastName);
			printf("DOB: %s\n", temp->dob);
			printf("Position: %s\n\n", temp->position);	
		        flag = 0; 
			break; 
		}else{
			flag = 1; 
		}

		temp= temp->next; 
	}
	if (flag == 1){		
		printf("Employee %s %s not found in database\n", firstName, lastName);
	}
}
void print(struct Node *firstNode){
	int count = 1; 
	struct Node *temp = firstNode->next;
	printf("\nList of all current Employees at Home Depot Location 4718"); 
	while(temp!=NULL){
		printf("\nEmployee %d\n", temp->employeeNumber);
		printf("First name: %s\n", temp->firstName); 
		printf("Last name: %s\n", temp->lastName);
		printf("DOB: %s\n", temp->dob);
		printf("Position: %s\n\n", temp->position);	
		temp= temp->next;
	        count++; 	
	}
}
void removeEmployee(struct Node *firstNode,char *firstName, char *lastName){
	struct Node *temp = firstNode;
	int flag = 0; 
	while(temp->next!=NULL){
		if((strcmp(temp->next->firstName, firstName) ==0) && strcmp(temp->next->lastName, lastName) == 0){
			temp->next=temp->next->next;
		        printf("Employee %s %s successfully removed\n", firstName, lastName);	
			flag = 0;
			break;
		}else{
			flag = 1;

		}
		temp= temp->next;
	}

	if(flag == 1){
		printf("Employee %s %s not in system.\n", firstName, lastName);
	}
}	
