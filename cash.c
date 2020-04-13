#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars<=0);

int cents = round(dollars*100);

int qcount = cents / 25;
int left1 = cents % 25;

int dcount = left1 / 10;
int left2 = left1 % 10;

int ncount = left2 / 5;
int pcount = left2 % 5;

int total = qcount+dcount+ncount+pcount;

printf("%i\n",total);
}
