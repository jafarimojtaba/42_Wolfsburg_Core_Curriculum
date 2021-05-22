#include <string.h>
#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>
#include "../dev/libft.h"
#include "../dev/ft_memset.c"
#include "../dev/ft_bzero.c"
#include "../dev/ft_memcpy.c"
#include "../dev/ft_memccpy.c"
#include "../dev/ft_memmove.c"
#include "../dev/ft_memchr.c"
#include "../dev/ft_memcmp.c"
#include "../dev/ft_strlen.c"
#include "../dev/ft_strlcpy.c"
#include "../dev/ft_strlcat.c"
#include "../dev/ft_strchr.c"
#include "../dev/ft_strrchr.c"
#include "../dev/ft_strnstr.c"
#include "../dev/ft_islower.c"
#include "../dev/ft_isupper.c"
#include "../dev/ft_tolower.c"
#include "../dev/ft_toupper.c"
#include "../dev/ft_isalpha.c"
#include "../dev/ft_isprint.c"

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
	memcpy(dest + 9, dest, 9 * sizeof(char));
	puts(dest);
	strcpy(src, "this is a test for memcpy!");
	strcpy(dest, "abcde fghi");
	ft_memcpy(dest + 9, dest, 9 * sizeof(char));
	puts(dest);
	puts("");

	// memmove
	puts("MEMMOVE");
	strcpy(src, "this is a test for memcpy!");
	strcpy(dest, "abcde fghi");
	memmove(dest, dest + 1, 9 * sizeof(char));
	puts(dest);
	strcpy(src, "this is a test for memcpy!");
	strcpy(dest, "abcde fghi");
	ft_memmove(dest, dest + 1, 9 * sizeof(char));
	puts(dest);
	puts("");

	// memccpy
	puts("MEMCCPY");
	strcpy(src, "ABCDEFGHIJKL");
	strcpy(dest, "abcdefghijkl");
	void *ccpy, *ccpy2;
	ccpy = memccpy(dest, src, 'c', 5 * sizeof(char));
	printf("%s \n", (char *)ccpy);
	strcpy(src, "ABCDEFGHIJKL");
	strcpy(dest, "abcdefghijkl");
	ccpy2 = ft_memccpy(dest, src, 'c', 5 * sizeof(char));
	printf("%s \n", (char *)ccpy2);
	// printf("%d, %d", sizeof(ccpy2), sizeof(ccpy));
	puts("");

	// memchr
	puts("MEMCHR");
	strcpy(src, "ABCDEFGHIJKL");
	printf("%s \n", (char *)(memchr(src, 'c', 3)));
	strcpy(src, "ABCDEFGHIJKL");
	printf("%s \n", (char *)(ft_memchr(src, 'c', 3)));
	puts("");

	// memcmp
	puts("MEMCMP");
	strcpy(src, "ABCDEFGHIJiKL");
	strcpy(dest, "ABCDEFGaHIJKL");
	printf("%d \n", memcmp(src, dest, 0));
	printf("%d \n\n", ft_memcmp(src, dest, 0));

	// strlen
	puts("STRLEN");
	char nstr[17] = "Hi how are you?";
	printf("%d \n", (int)strlen(nstr));
	printf("%d \n\n", (int)ft_strlen(nstr));

	// strlcpy
	puts("STRLCPY");
	strcpy(src, "ABCDEFGHIJiKL");
	strcpy(dest, "mno");
	// printf("%d \n", (int)strlcpy(dest, src, 5));
	printf("%d \n", (int)ft_strlcpy(dest, src, 5));
	puts(dest);
	puts("");

	// strlcat
	puts("STRLCAT");
	strcpy(src, "ABC");
	strcpy(dest, "mno");
	// printf("%d \n", (int)strlcat(dest, src, 5));
	printf("%d \n", (int)ft_strlcat(dest, src, 5));
	puts(dest);
	puts("");

	// strchr
	puts("STRCHR");
	strcpy(src, "ABCdefghijkZlmnoZpkrstuvwxyz");
	printf("%s \n", strchr(src, 'O'));
	printf("%s \n\n", ft_strchr(src, 'O'));

	// strrchr
	puts("STRRCHR");
	strcpy(src, "ABCdefghijkZlmnoZpkrstuvwxyz");
	printf("%s \n", strrchr(src, 'O'));
	printf("%s \n\n", ft_strrchr(src, 'O'));

	// strnstr
	puts("STRNSTR");
	const char *largestring = "Foo Ba Bar Bacab";
	const char *smallstring = "car";
	char *ptr;

	// ptr = strnstr(largestring, smallstring, 4);
	// puts(ptr);
	ptr = ft_strnstr(largestring, smallstring, 2);
	printf("%s \n",ptr);

	// islower
	int lower;
	lower = 'S';
	// printf("%d", ft_islower(lower));
	puts("");

	// tolower
	puts("TOLOWER");
	printf("%c", ft_tolower(lower));
	puts("\n");

	// toupper
	puts("TOUPPER");
	printf("%c", ft_toupper(lower));
	puts("\n");

	// isalpha
	puts("ISALPHA");
	printf("%d", ft_isalpha(lower));
	puts("\n");

	// isprint
	puts("ISPRINT");
	for (int c = 1; c <= 127; ++c)
		if (ft_isprint(c) != 0)
			printf("%d ", c);
	puts("\n");

	//
	puts("ATOI");
	char stnum[] = "  +123";
	printf("%d", atoi(stnum));

	return (0);
}