#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"

int main(int argc, char *argv[]){
	char firstName[1024]={0};
	char lastName[1024]={0};
	char dob[1024];
	char position[1024]={0}; 
	char buffer[1024];  
	char storeNumber[1024]; 
	printf("Welcome to the Home Depot Employee Database!\n");
	
	printf("Please enter which store number you wish to check the employee database of: ");
        fgets(buffer, 1024, stdin);
	sscanf(buffer, "%s", storeNumber); 

	printf("Welcome to store %s.\nIf you need help with navigating this database, please type: ? into the command line\n", storeNumber);
	
	char helpMessage[] = "\nHere is how you can navigate the Home Depot employee database:\n\n<?> Lists various commands on how to operate the database\n<s> Search for an employee and have their information printed out\n<c> Will create a new employee under that name. When creating a new employee it will ask you various questions about their employee ID number, DOB, etc.\n<r> Remove an employee\n<a> print a list of all employees in the system\n<x> Exit the program\n"; 
	int waiting = 1; 
	char command[1024];
	char extra[1024];
	int count = 100; 
        struct Node *firstNode = initFirstNode(); 	
	//Read in employee information from a file
	FILE *fp;
	char txtInfo[] = ".txt"; 
	strcat(storeNumber, txtInfo);
	fp = fopen(storeNumber, "r");//Read and write to employeeInfo.txt
	if (fp == NULL){
		printf("Invalid store number or file. Try again with a valid store number\n");
		exit(0); 
	}
	int employeeNum = 0;
	int numBuffer[1000];
	while(fgets(buffer, 1024, fp) != NULL){
		fgets(buffer, 1000, fp);
		sscanf(buffer, "%d", &employeeNum); 
		fgets(buffer, 1024, fp);
		sscanf(buffer, "%s", firstName); 
		fgets(buffer, 1024, fp);
		sscanf(buffer, "%s", lastName); 
		fgets(buffer, 1024, fp);
		sscanf(buffer, "%s", dob); 
		fgets(buffer, 1024, fp);
		sscanf(buffer, "%[^\n]", position);
		position[1024] = '\0';
		createEmployee(firstNode, firstName, lastName, dob, position, employeeNum);

	}
	printf("Command: "); 

	while(waiting){
		fgets(buffer, 1024, stdin);
		sscanf(buffer, "%s", command);

		if (command[0] =='?'){
			printf("%s\n", helpMessage); 
		}else if(command[0] == 'x'){
			printf("Thank you for using the Home Depot employee database. Goodbye!\n");
			waiting = 0; 
			exit(0); 
		}else if(command[0] == 'c'){
			count++; 
			printf("Entering a new employee into the system:\n");
		        printf("First name: ");
			fgets(buffer, 1024, stdin);
			sscanf(buffer, "%s", firstName); 
			printf("Last name: ");
			fgets(buffer, 1024, stdin); 
			sscanf(buffer, "%s", lastName); 
			printf("DOB: ");
			fgets(buffer, 1024, stdin);
			sscanf(buffer, "%s", dob); 
		        printf("Position: "); 	
			fgets(buffer, 1024, stdin);
			sscanf(buffer, "%s", position);
		        
			printf("New employee added\n");
			firstNode = createEmployee(firstNode, firstName, lastName, dob, position, count); 	

		}else if(command[0] == 's'){
			printf("Please enter the employee's first name: ");
			fgets(buffer, 1024, stdin);
			sscanf(buffer, "%s", firstName); 
			printf("\nPlease enter their last name: "); 
			fgets(buffer, 1024, stdin); 
			sscanf(buffer, "%s", lastName);

			searchEmployee(firstNode, firstName, lastName);
		}else if(command[0] == 'a'){
			print(firstNode);
		}else if(command[0] == 'r'){
			printf("Please enter the employee's first name: ");
			fgets(buffer, 1024, stdin);
			sscanf(buffer, "%s", firstName); 
			printf("\nPlease enter their last name: "); 
			fgets(buffer, 1024, stdin); 
			sscanf(buffer, "%s", lastName);
			
			removeEmployee(firstNode, firstName, lastName); 
		}else{
			printf("Please enter a valid command. Type ? to see valid commands.\n");
		}

		printf("Command: "); 
	}
	return 0; 

}
