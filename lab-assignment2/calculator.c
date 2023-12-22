//enter your name here
//Yao Chen
//enter your email here
//chen.yao2@northeastern.edu

#include<stdio.h>
int main()
{
    int a,b,c, choice, result;
    
    printf("Enter your choice\n");
    printf(" 1.addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n");
    scanf("%d",&choice);
    
    printf("Enter a and b values ");
    scanf("%d %d", &a, &b);
    
    // Add your code here using switch
    switch(choice) {
        case 1:
            result = a + b;
            printf("Sum=%d", result);
            break;
        case 2:
            result = a - b;
            printf("Difference=%d", result);
            break;
        case 3:
            result = a * b;
            printf("Product=%d", result);
            break;
        case 4:
            if(b == 0) {
                printf("Cannot divide by zero");
            } else {
                result = a / b;
                printf("Quotient=%d", result);
            }
            break;
        default:
            printf("Invalid operator");
    }
           
    return 0;
}
