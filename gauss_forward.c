//  INTERPOLATION
// Program 7 : To impliment Gauss's Forward interpolation formula
// ------------------------------------------------------------------------
//
// Table: I use only one 2D array to store all values of x, y and delta y's
// Logic ( i and j are the loop variables )
//
//	  i\j |   0  |   1  |   2   |   3     |   4  |
//	  ----+------+------+-------+---------+------+...
//	   0  |  x1  |  y1  | y2-y1 | dy2-dy1 |      |
//	  ----+------+------+-------+---------+------+...
//	   1  |  x2  |  y2  | y3-y2 |         |      |
//	  ----+------+------+-------+---------+------+...
//	   2  |  x3  |  y3  |       |         |      !
//	  ----+------+------+-------+---------+...
//	      !      !      !       !         !

#include <stdio.h>
#include <conio.h>

#define MAXITEMS 10

int main()
{
    int i, j; // for loop
    int n;    // no of terms
    // 2D array. 1st column for x, 2nd for y and other for difference
    double table[MAXITEMS][MAXITEMS + 1];
    double h;          // constant difference
    double x, y = 0.0; // y is f(x)
    double u, m = 1.0; // m is multiplier
    int z;             // index of f(0)

    printf(" Enter no of terms : ");
    scanf("%d", &n);
    printf(" Enter first term in the x column : ");
    scanf("%lg", &table[0][0]);
    printf(" Enter difference between terms : ");
    scanf("%lg", &h);

    for (i = 0; i < n; i++)
    {
        // calculate other x from first term and difference
        table[i][0] = table[0][0] + (double)(i)*h;
        printf(" Enter the value of f(%lg) : ", table[i][0]);
        scanf("%lg", &table[i][1]);
    }

    for (j = 1; j < n; j++)         // loop to each column
        for (i = 0; i < n - j; i++) // loop to cell within a column
            table[i][j + 1] = table[i + 1][j] - table[i][j];

    printf("\n Enter the value of x for which you want to find f(x) : ");
    scanf("%lg", &x);

    //Finding the value of u
    for (i = 0; i < n; i++)
    {
        u = (x - table[i][0]) / h;
        if (0 < u && u <= 0.5)
            break;
    }
    if (i == n) //search unsuccessful
    {
        printf("\n Condition 0<u<=0.5 not satisfied");
        getch();
        return 1; //exit program
    }
    else
        z = i;

    printf("\n u = %g is found at f(%g)", u, table[z][0]);

    for (j = 1, i = 0; j <= n; j++)
    {
        y += m * table[z - i][j];

        if (j % 2 == 1)
            m *= (u + (double)(i)) / (double)(j);
        else
            m *= (u - (double)(++i)) / (double)(j);

        if ((z - i) < 0 || (z - i) > (n - j - 1))
            break; //checks validity of index in the table
    }

    printf("\n F(%g) = %g\n", x, y);
    return 0;
}