
#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 3.141592

int main(int argc, char *agrv[]) {
	double n1, n2;
	int n3;
	double(*func)(double);
	double sum;
	double integ(double a, double b, int n, double(*f)(double));                                                               /* integrate y = f(x) */
	
	if (argc < 4) {
		printf("usage: integ sin/cos/tan lower-limit upper-limit [no-of-steps]\n");
		return 1;
	}
	else if (argc == 4||argc==5)
	{   if (argc==4)
		   agrv[4] = "100";
		n1 = atof(agrv[2]);
		n2 = atof(agrv[3]);
		n3 = atof(agrv[4]);
		
		if (strcmp(agrv[1], "cos") == 0)func = cos;
		else if (strcmp(agrv[1], "sin") == 0)func = sin;
		else if (strcmp(agrv[1], "tan") == 0)func = tan;
	    else {
		  printf("unrecognized trigonometric function name: %s\n", agrv[1]);
		  return 1;
		}
		
		sum = integ(n1, n2, n3,func);
		printf("int_%g^%g  %s(x) = %.3g with %d parts\n", n1,n2, agrv[1],sum, n3);
	}
	
	


}
double integ(double a, double b, int n,
	double(*f)(double)) {
	double sum, x, x1, delta, area;
	int    i;

	delta = (b - a) / n;
	for (i = 0, sum = 0.0; i < n; i++) {
		x = a + i * delta;
		x1 = x + delta;
		area = delta * (f(x) + f(x1)) / 2;
		sum += area;
	}
	return sum;
}
