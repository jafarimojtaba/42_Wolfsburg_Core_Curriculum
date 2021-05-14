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
	strcpy(src, "this is a test for memcpy!");
	strcpy(dest, "hello world!");
	memcpy(dest+10, dest, 9);
	puts(dest);

	strcpy(src, "this is a test for memcpy!");
	strcpy(dest, "hello world!");
	ft_memcpy(dest+10, dest, 9);
	puts(dest);

	//memmove
	
	return (0);
}