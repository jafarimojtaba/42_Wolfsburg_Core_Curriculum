#include <string.h>
#include <stdio.h>
#include "../dev/libft.h"
#include "../dev/ft_memset.c"
#include "../dev/ft_bzero.c"
#include "../dev/ft_memcpy.c"
#include "../dev/ft_memccpy.c"
#include "../dev/ft_memmove.c"
#include "../dev/ft_islower.c"
#include "../dev/ft_isupper.c"
#include "../dev/ft_tolower.c"
#include "../dev/ft_toupper.c"
#include "../dev/ft_isalpha.c"
#include "../dev/ft_isprint.c"
#include "../dev/ft_strlen.c"

int main()
{
	// memset
	char str[50];
	puts("MEMSET");
	strcpy(str, "this is a test for memset!");
	puts(str);
	memset(str, '$', 7);
	printf("original function : ");
	puts(str);

	strcpy(str, "this is a test for memset!");
	ft_memset(str, '$', 7);
	printf("recreated function: ");
	puts(str);
	puts("");

	// bzero
	puts("BZERO");
	strcpy(str, "this is a test for bzero!");
	puts(str);
	bzero(str, 7);
	printf("original function : ");
	puts(str);
	strcpy(str, "this is a test for bzero!");
	ft_bzero(str, 7);
	printf("recreated function: ");
	puts(str);
	puts("");

	// memcpy
	puts("MEMCPY");
	char src[30], dest[30];
	strcpy(src, "this is a test for memcpy!");
	strcpy(dest, "abcde fghi");
	memcpy(dest+9, dest, 9 * sizeof(char));
	puts(dest);
	strcpy(src, "this is a test for memcpy!");
	strcpy(dest, "abcde fghi");
	ft_memcpy(dest+9, dest, 9 *sizeof(char));
	puts(dest);
	puts("");


	//memmove
	puts("MEMMOVE");
	strcpy(src, "this is a test for memcpy!");
	strcpy(dest, "abcde fghi");
	memmove(dest, dest+1, 9 * sizeof(char));
	puts(dest);
	strcpy(src, "this is a test for memcpy!");
	strcpy(dest, "abcde fghi");
	ft_memmove(dest, dest+1, 9 * sizeof(char));
	puts(dest);
	puts("");

	//memccpy
	puts("MEMCCPY");
	strcpy(src, "ABCDEFGHIJKL");
	strcpy(dest, "abcdefghijkl");
	void *ccpy, *ccpy2;
	ccpy = memccpy(dest, src, 'B', 2 * sizeof(char));
	puts(ccpy);
	strcpy(src, "ABCDEFGHIJKL");
	strcpy(dest, "abcdefghijkl");
	ccpy2 = ft_memccpy(dest, src, 'B', 2 * sizeof(char));
	puts(ccpy2);
	puts("");
	
	//islower
	int lower;
	lower = 'S';
	printf("%d", ft_islower(lower));
	puts("");

	
	//toupper
	printf("%c", ft_tolower(lower));
	puts("");

	//tolower
	printf("%c", ft_toupper(lower));
	puts("");

	//isalpha
	printf("%d", ft_isalpha(lower));
	puts("");

	//isprint
   	for(int c = 1; c <= 127; ++c)
   	if (ft_isprint(c)!= 0)
    printf("%d ", c);
	puts("");


	//strlen
	char nstr[17] ="Hi how are you?";
	printf("%d", (int)strlen(nstr));
	puts("");

	printf("%d", (int)ft_strlen(nstr));
	puts("");

	char stnum[]="  +123";
	printf("%d", atoi(stnum));

	return (0);
}