#include <string.h>
#include <stdio.h>
#include "../dev/libft.h"
#include "../dev/ft_memset.c"
#include "../dev/ft_bzero.c"

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
	// ft_memset
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
	// ft_bzero
	strcpy(str, "this is a test for memset!");
	ft_bzero(str, 7);
	printf("recreated function: ");
	puts(str);
	puts("");

	return (0);
}