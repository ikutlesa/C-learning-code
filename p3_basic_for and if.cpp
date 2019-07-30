/* crtanje šahovske ploèe */

#include <stdio.h>
void main(void)
{
	int x, y;
	for(y = 1; y < 17; y++) /*pomak po y osi -vertikalno*/
	{
		for(x = 1;x < 17; x++) /*pomak po x osi - horizontalno*/
		{
			if ((x+y)%2 == 0) /*parno polje - blok*/
				printf("\xDB\xDB");
			else printf("  "); /*neparno polje - pozadina*/
		}
		printf("\n"); /*sljedeæi red*/
	}
}