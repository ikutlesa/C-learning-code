#include <stdio.h>
#include <cmath>


int main() /*program 5: Approximate a Derivative by a
		    Difference Quotient */
{
		int n=1;
		double  x=1.0, h=1.0, deriv=cos(x), diffquo, error;
        
		printf("deriv=%13.6e \n \n", deriv);
        printf("\t    h \t            diffquo \t     abs(deriv - diffquo) \n");
        printf("\n");
		/* Let h range from 10^{-1} down to 10^{-20} */

		while(n <= 20){
			h=h/10;
			diffquo = (sin(x+h) - sin(x))/h;
			error = fabs(deriv - diffquo);
			printf("\t %5.1e \t  %13.6e \t %13.6e \n", h, diffquo, error);
			n++;
		}
      return 0;	
}