//enter your name here
//Yao Chen
//enter your email here
//chen.yao2@northeastern.edu
/*C Program to read and print the n employee details using structure and dynamic memory allocation*/
#include <stdio.h>
#include <stdlib.h>
/*structure to hold the details of an employee*/
typedef struct employee
{
    int empId;
    char Name[100];
    char Designation[100];
    char Dept[10];

}employee_t;
/* Read the employee details using scanf*/
void readData(int n, employee_t* s)
{
    // Add your code here
    for (int i = 1; i <= n; i++) { 
    printf("\nEnter the employeeID, Name, designation and Department of Employee %d:\n", i);
    scanf("%d",&s->empId);
    scanf("%s", s->Name);
    scanf("%s", s->Designation);
    scanf("%s", s->Dept);
    s++;
}

}
/* Function to print the employee details*/
void display(int n, employee_t * s)
{
    // Add your code here
    for (int i = 1; i <= n; i++) {
        printf("\nThe details of Employee %d:\n", i);
        printf("empId: %d\n", s->empId);
        printf("Name: %s\n", s->Name);
        printf("Designation: %s\n", s->Designation);
        printf("Dept: %s\n", s->Dept);
        s++;
    }
}

/*----------Main Program--------*/
int main()

{
    // Main Function to print the employee details
    // Add your code here
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    employee_t* p_employee = (employee_t*)malloc(sizeof(employee_t)*n);
    readData(n, p_employee);
    display(n, p_employee);
    free(p_employee);
    return 0;
    

}


