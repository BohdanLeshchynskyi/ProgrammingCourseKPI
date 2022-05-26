#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double res(int k, double y){
    return exp(cos(pow(y,2*k)))*sin(pow(y,3*k));
}
double flpoint(double x){
    return fabs(x - (int)x);
} 
int main(){
    int n;
    double x;
    double curm;
    double min;
    double closest = 1;
    printf("Enter some natural n and some real x:\n");
    scanf("%d",&n);
    scanf("%lf",&x);
    double *arr;
    arr = (double*)malloc(n*sizeof(double));
    printf("The numbers are:\n");
    for(int i=0; i<n; i++){
        arr[i]= res(n-i,x);
        printf("%lf\t",arr[i]); 
    }

    min = flpoint(arr[0]);
    closest = arr[0];
    if(min>=0.5){
        min = 1 - min ;
    }

    for(int i=1; i<n-1; i++){
        curm = flpoint(arr[i]);
        if(curm>=0.5){
            curm = 1 - curm;
        }
        if(min>curm){
            min = curm;
            closest = arr[i];
        }  
    }

    printf("\n");
    printf("The closest to an integer number is: %.5lf", closest);

    free(arr);

    return 0;
}