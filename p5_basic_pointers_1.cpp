#include <stdio.h>
void main()
{
	int p[5]={1,4,5,7,8},*pp,produkt,a;
   	pp=p;
	a=10;
	produkt=a *(*(++pp));
	printf("%d\n",*pp);
	printf("%d\n",p[0]);
	printf("%d\n",*(p+2));
	printf("%d\n",p[2]);
	printf("produkt je %d",produkt);
}

