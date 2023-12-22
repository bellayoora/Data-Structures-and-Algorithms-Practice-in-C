//chen.yao2@northeastern.edu
//Yao Chen

#include<stdio.h>
#include<string.h>

int compression(char arr[], int n, char res[]){

int i, j, count;
char current;
j = 0;
current = arr[0];
count = 1;

for (i = 1; i <= n; i++) {
    if (arr[i] == current) {
        count++;
    } 
    else {
        res[j] = current;
        j++;
        
        if (count > 1) {
            char num[10];
            sprintf(num, "%d", count);
            int k;
            for (k = 0; k < strlen(num); k++) {
                res[j] = num[k];
                j++;
            }
        }
        
        current = arr[i];
        count = 1;
    }
}

res[j] = '\0';
return strlen(res);

    
    
    
    
    
}
 
int main()
{
    char a[]="aaaaaaaaaaaaaabbbbcccd";
    char res[50];
    int r,n=strlen(a);//n is the size of input array
    r=compression(a,n,res);
    printf("length of the compressed string:%d\n",r);
    return 0;
}
