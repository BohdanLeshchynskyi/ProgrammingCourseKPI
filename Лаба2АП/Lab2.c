#include <stdio.h>
#include <math.h>

double posX( double x1, double a1 ){
    if(x1*x1*x1/(x1+a1) < 0){
        printf("Uncomputable for %lf,%lf",x1,a1);
    }
    else{
    return sqrt(x1*x1*x1/(x1+a1))-log(x1);//function computing values of y while x<0
    }
}
double negX( double x2 , double a2 ){
   return 2*a2*log(-x2);                 //function computing values of y while x>0
}

int main(){

    double initialX, upBound, dx, a, y;

    printf("Set initial x:\n");
    scanf("%lf",&initialX);
    printf("Set the upper bound for x:\n");
    scanf("%lf",&upBound);
    printf("Set the delta x:\n");
    scanf("%lf",&dx);
    printf("Set a constant:\n");
    scanf("%lf",&a);
    
    for(double x = initialX; x<=upBound; x+=dx ){
        if(x<0){
            y = negX(x,a);
        }
        if(x==0){
            y = 0;
        }
        if(x>0){
            y = posX(x,a);
        }
        printf("for x=%lf: y=%lf\n",x,y);
    }

  return 0;  
}
