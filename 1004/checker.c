#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100
#define bound pow(2, 127)
#define ZERO 0.000000001 /* X is considered to be 0 if |X|<ZERO */

int Jacobi( int n, double a[][MAX_SIZE], double b[], double x[], 
double TOL, int MAXN );

int Gauss_Seidel( int n, double a[][MAX_SIZE], double b[], double x[], 
double TOL, int MAXN );

int main()
{
	int n, MAXN, i, j, k;
	double a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE], x[MAX_SIZE];
	double TOL;

	while (scanf("%d", &n) != EOF) {
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++)
				scanf("%lf", &a[i][j]);
			scanf("%lf", &b[i]);
		}
		scanf("%lf %d", &TOL, &MAXN);

		printf("Result of Jacobi method:\n");
		for ( i=0; i<n; i++ )
			x[i] = 0.0;
		k = Jacobi( n, a, b, x, TOL, MAXN );
		switch ( k ) {
			case -2:
				printf("No convergence.\n");
				break;
			case -1: 
				printf("Matrix has a zero column.  No unique solution exists.\n");
				break;
			case 0:
				printf("Maximum number of iterations exceeded.\n");
				break;
			default:
				printf("no_iteration = %d\n", k);
				for ( j=0; j<n; j++ )
					printf("%.8lf\n", x[j]);
				break;
		}

		printf("Result of Gauss-Seidel method:\n");
		for ( i=0; i<n; i++ )
			x[i] = 0.0;
		k = Gauss_Seidel( n, a, b, x, TOL, MAXN );
		switch ( k ) {
			case -2:
				printf("No convergence.\n");
				break;
			case -1: 
				printf("Matrix has a zero column.  No unique solution exists.\n");
				break;
			case 0:
				printf("Maximum number of iterations exceeded.\n");
				break;
			default:
				printf("no_iteration = %d\n", k);
				for ( j=0; j<n; j++ )
					printf("%.8lf\n", x[j]);
				break;
		}
		printf("\n");
	}
	return 0;
}

