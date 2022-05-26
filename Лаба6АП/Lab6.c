#include<stdio.h>

int has3(int x){
    while(x>0){
        if(x%10==3){
            return 1;
        }
        else{
            x/=10;
        }
    }
    return 0;
}

int main(){
    int n;
    printf("Enter some natural number to check if it has '3' in it: ");
    scanf("%d",&n);
    printf("\n");
    printf("*Notice: 0 stays for no 3 found in entered number; 1 - number has 3 in it*\n");
    printf("%d", has3(n));

    return 0;
}