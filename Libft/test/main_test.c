#include <string.h>
#include <stdio.h>
#include "../dev/libft.h"
#include "../dev/ft_memset.c"
#include "../dev/ft_bzero.c"
#include "../dev/ft_memcpy.c"

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
	// int intdest[5];
	// int intsrc[5] ={25,345,766,1,2};
	strcpy(src, "this is a test for memcpy!");
	strcpy(dest, "abcde fghi");
	memcpy(dest+9, dest, 9 * sizeof(char));
	// memcpy(intdest,intsrc,5);
	puts(dest);

	strcpy(src, "this is a test for memcpy!");
	strcpy(dest, "abcde fghi");
	// memmove(dest+9, dest, 9 * sizeof(char));
	
	ft_memcpy(dest+9, dest, 9 *sizeof(char));
	// memmove(dest, dest+1, 9 * sizeof(char));

	puts(dest);

	//memmove
	
	return (0);
}