#include <stdio.h>


double celsistoFahernheit(double celsius) {

    return (celsius * 9 / 5) + 32;
}

double fahrenheittoCelsius(double fahrenheit){

    return (fahrenheit - 32) * 5 / 9;

}

int main(){
    double temp;
    char unit;
    printf("Enter temperature (eg: 36.5C, or 97.7F)");

    scanf("%lf%c", &temp, &unit);

    if ( unit == 'C' || unit == 'c' ){
        printf("%.21f is %.21f \n", temp , celsistoFahernheit(temp));
    }else if ( unit == 'F' || unit == 'f' ) {
        printf("%.21f is %.21f \n", temp , fahrenheittoCelsius(temp));
    }else{
        printf("it was the individal value \n ");
    }
}