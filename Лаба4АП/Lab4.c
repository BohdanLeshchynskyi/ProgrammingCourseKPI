#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    srand(time(0));
    int n;
    int t;
    printf("Enter an even number of array`s elements : ");
    scanf("%d",&n);
    int array1[n];
    int array2[n];

    for(int i = 0; i<n; i++){
        array1[i]=rand()%10 - 5;
        printf("%d\t",array1[i]);
    }
    printf("The resorted array: \n");
    for(int i=0; i<n/2; i++){
        printf("%d\t",array1[i]);
        printf("%d\t",array1[n/2+i]);
    }
    /*for(int i=0; i<n/2; i++) {
        array2[2*i] = array1[i];
        array2[2*i+1] = array1[n/2+i];
    }
    for(int i = 0; i<n; i++){
        printf("%d\t",array2[i]);
    }*/
    getchar();
    
    return 0;
}