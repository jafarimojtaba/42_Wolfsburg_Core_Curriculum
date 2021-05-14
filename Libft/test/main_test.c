#include <string.h>
#include <stdio.h>
#include "../dev/libft.h"
#include "../dev/ft_memset.c"

int main()
{
	// memset
	char str[50];
	strcpy(str, "this is a test for memset!");
	puts(str);
	memset(str, '$', 7);
	printf("original function : ");
	puts(str);
	// ft_memset
	ft_memset(str, '$', 7);
	printf("recreated function: ");
	puts(str);



	return (0);
}