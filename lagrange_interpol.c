#include <stdio.h>
#include <conio.h>
#define MAX 10
int main()
{
    float x[MAX], y[MAX], k = 0, z, nr, dr;
    int i, j, m;
    //clrscr();
    printf("\n enter the number of elements: ");
    scanf("%d", &m);
    printf("\n enter the x values:\n");
    for (i = 0; i < m; i++)
        scanf("%f", &x[i]);
    printf("\n enter the y values\n");
    for (i = 0; i < m; i++)
        scanf("%f", &y[i]);
    printf("\n enter  value of x for which you want to find y: ");
    scanf("%f", &z);

    for (i = 0; i < m; i++)
    {
        nr = 1;
        dr = 1;
        for (j = 0; j < m; j++)
        {
            if (j != i)
            {
                nr = nr * (z - x[j]);
                dr = dr * (x[i] - x[j]);
            }
        }
        k = k + ((nr / dr) * y[i]);
    }
    printf("\n final result=%f\n", k);
    return 0;
}