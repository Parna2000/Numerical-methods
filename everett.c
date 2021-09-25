// INTERPOLATION
// Program 11 : To impliment Laplace-Everett's interpolation formula
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
	int i,j;	// for loop
	int n;		// no of terms
	// 2D array. 1st column for x, 2nd for y and other for difference
	double table[MAXITEMS][MAXITEMS+1];
	double h;			// constant difference
	double x, y = 0.0;	// y is f(x)
	double u, w;			// 
	double m1, m2; 		// m is multiplier
	int z;				// index of f(0)
	
	printf("\n Enter no of terms : ");
	scanf("%d", &n);
	printf(" Enter first term : ");
	scanf("%lg", &table[0][0]);
	printf(" Enter difference between terms : ");
	scanf("%lg", &h);
	
	for( i=0; i<n; i++)
	{
		// calculate other x from first term and difference
		table[i][0] = table[0][0] + (double)(i) * h;
		printf(" Enter the value of f(%lg) : ", table[i][0]);
		scanf("%lg", &table[i][1]);
	}
	
	for( j=1; j<n; j++)	// loop to each column
		for( i=0; i<n-j; i++)	// loop to cell within a column
			table[i][j+1] = table[i+1][j] - table[i][j];
	
	printf("\n Enter the value of x for which you want to find f(x) : ");
	scanf("%lg", &x);
	
	//Finding the value of u
	for( i=0; i<n; i++)
	{
		u = ( x - table[i][0] ) / h;
		if( 0<u && u<1.0 )
			break;
	}
	
	if( i == n ) //search unsuccessful
	{
		printf("\n Condition 0<u<1 not satisfied");
		getch();
		return 1;//exit program
	}
	else
		z = i;
	
	w = 1.0 - u;
	printf("\n u = %g, w = %g is found at f(%g)", u, w, table[z][0]);
	
	i = 0;
	m1 = u;
	m2 = w;
	for( j=1; j<=n; j+=2)
	{
		y += m1 * table[z+1-i][j] + m2 * table[z-i][j];
		
		i++;
		m1 *= (u - (double)(i)) * (u + (double)(i)) / (double)((j+1)*(j+2));
		m2 *= (w - (double)(i)) * (w + (double)(i)) / (double)((j+1)*(j+2));
		
		if( (z-i)<0 || (z+1-i)>(n-j-1) )
			break;	//checks validity of index in the table
	}
	
	printf("\n F(%g) = %g\n", x, y);	
	return 0;
}