#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));

    int n;
    int neg = 0;
    int indJ;
    printf("Enter n for a quadratic matrix order: \n");
    scanf("%d",&n);

    int **matr;
    matr = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++){
        matr[i]=(int*)malloc(n*sizeof(int));
    }
    printf("The quadratic random filled matrix of order %d : \n", n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            *(matr[i]+j) = rand()%201-100;
            printf("%d\t",*(matr[i]+j));
        }
        printf("\n");
    } 

    int *vectb;
    vectb = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        vectb[i]=0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(*(matr[i]+j)<0){
                neg++;
                indJ = j;
            }
        }
        if(neg==1 && indJ==0){
            vectb[i] = 0;
        }
        else if(neg==0){
            vectb[i] = -1;
        }
        else{
            for(int k=0; k<indJ; k++){
                vectb[i] += *(*(matr+i)+k); 
            } 
        }  
    }

    printf("Vector b: \n");
    for(int i=0; i<n; i++){ 
        printf("%d\t", vectb[i]);
    }

    return 0;
}