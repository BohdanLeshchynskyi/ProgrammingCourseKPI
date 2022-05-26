#include <stdio.h> 
#include <math.h> // математична бібліотека 

int main(){

    double a,b,c,x,y; // оголошуємо змінні

    printf("Enter parameters a, b and c to compute the values of x and y:\n");

    scanf("%lf",&a); // ввод парамтрів a,b,c відповідно
    scanf("%lf",&b);
    scanf("%lf",&c);

    if ( (fabs(b)+c)<0 || fabs(b)==0 ){
        printf("Something went wrong! Try setting other values of paraeters of b and c!"); // превірка математичної правдивості
    }
    else{

        x = pow((1 + pow(tan(a/2), 2)),sqrt(fabs(b)+c)); // обрахунки х та у відповідно
        y = 2*pow(tan(a/fabs(b)),-1);  

        printf("The x value is: %lf\n", x); // вивід обрахованих значеннь змінних
        printf("The y value is: %lf\n", y);

    }

    return 0;

}   