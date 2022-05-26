#include<stdio.h>
#include<math.h>

void task(double epsX){
    int n = 0;
    double S = 0,eps,cur,x = 0.7;
    do{
        cur=powf(-1,n)*powf(x,2*n);
        S+=cur;
        eps = S - 1/(1+x*x);
        cur+=cur;
        n++;
    }while(fabs(eps)>epsX);
    n++;
    printf("For given %lf: S= %lf eps= %lf n= %d \n",epsX,S,eps,n);
}

int main(){
    double eps1,eps2;
    printf("Enter eps1 and eps2: \n");
    scanf("%lf%lf",&eps1,&eps2);

    task(eps1);
    task(eps2);

    return 0;
}