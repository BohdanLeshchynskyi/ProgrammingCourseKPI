#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int** minor(int**mat,int*size,int el){
    *size=*size-1;
    int **matrix2;
    matrix2 = (int**)malloc(*size*sizeof(int*));
    for(int i=0; i<*size; i++){
        *(matrix2+i) = (int*)malloc(*size*sizeof(int));
    }    
    for(int i=0,i2=0; i<(*size)+1; i++,i2++){
        if(i==el){
            i2--;
        } 
        for(int j=0, j2=0; j<(*size)+1; j++){
            if(i!=el && j!=el){
                *(*(matrix2+i2)+j2) = *(*(mat+i)+j);
                j2++;
                }
            }
        }

    for(int i=0; i<(*size)+1; i++){
        free(*(mat+i));
    } 
    free(mat); 

    return matrix2;
}

int main(){
    srand(time(0));
    int n;
    int diagMax = 0;
    printf("Enter natural n for matrix order: ");
    scanf("%d",&n);
    printf("\n");

    int **matrix;
    matrix = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++){
        *(matrix+i) = (int*)malloc(n*sizeof(int));
    }

    printf("The initial randomly filled matrix is: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            *(*(matrix+i)+j) = rand()%100;
            printf("%d \t",*(*(matrix+i)+j));
        }  
        printf("\n");  
    }
    for(int i=1;i<n; i++){
        if(*(*(matrix+diagMax)+diagMax)<*(*(matrix+i)+i)){
            diagMax = i;
        } 
    }
    printf("The martix diagonal biggest element`s value is: %d\n The diagonal`s biggest element minor is: \n",*(*(matrix+diagMax)+diagMax));

    matrix = minor(matrix,&n,diagMax);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d \t",*(*(matrix+i)+j));
        }
        printf("\n");
    }

    for(int i=0; i<n; i++){
        free(*(matrix+1));
    }
    free(matrix);

    getchar();

    return 0;
} 