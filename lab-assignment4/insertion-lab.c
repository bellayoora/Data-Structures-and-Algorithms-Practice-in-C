//Yao Chen
//chen.yao2@northeastern.edu
//To perform insertion sort of integers stored in a file and display the output and store it in another file.
#include <stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    int arr[10],temp;
    int count=0,i,j;
    /*count will have the total number of elements in the array*/

    /*read the file*/
    fp=fopen("Input.txt","r");
    if(fp==NULL){
        //if file returns NULL then can't open the file
        printf("\n Cannot open the file \n");
        exit(0);
    }
    
    //insert your code here
    int i;
        for (i=0; i<10; i++) {
            fscanf(fp, "%d", &arr[i]);
        }
        fclose(fp);

        FILE *fp2;
        fp2=fopen("sorted.txt", "w");

        sort(arr, 10);

        for (i = 0; i < 10; i++) {
            fprintf(fp2, "%d\n", arr[i]);
        }
        fclose(fp2);
    return 0;
}

void sort(int* arr, int length)
    {
        int temp, i, j;
        printf("Output:\n");

        for (j=1; j<length; j++)
        {
            if(arr[j] < arr[j-1]) {
                i = j;
                temp = arr[j];
                while((temp < arr[i-1]) && (i>=1)) {
                    arr[i] = arr[i-1];
                    i--;
                
                printf("%d %d\n", i, temp);
                }
                arr[i] = temp;
            }
            printf("%d %d\n", i, arr[j]);
        }
    }
