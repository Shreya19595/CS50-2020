#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);

    int cents = round(dollars * 100);     //round func is used to round off the float dollar input

    int qcount = cents / 25;              //qcount is count of quarters
    int left1 = cents % 25;

    int dcount = left1 / 10;             //dcount is count of dimes
    int left2 = left1 % 10;

    int ncount = left2 / 5;              //ncount is count of nickels
    int pcount = left2 % 5;              //pcount is count of pennies

    int total = qcount + dcount + ncount + pcount;

    printf("%i\n", total);
}
