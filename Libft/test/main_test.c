#include <string.h>
#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>
#include "../dev/libft.h"

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
	printf("%s \n", (char *)(memchr("bonjour", 'b', 4)));
	printf("%s \n", (char *)(ft_memchr("bonjour", 'b', 4)));
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	printf("%s\n", (char *)memchr(tab, -1, 7));
	printf("%s\n", (char *)ft_memchr(tab, -1, 7));
	puts("");

	// memcmp
	puts("MEMCMP");
	strcpy(src, "ABCDEFGHIJiKL");
	strcpy(dest, "ABCDEFGaHIJKL");
	printf("%d \n", memcmp(src, dest, 0));
	printf("%d \n\n", ft_memcmp(src, dest, 0));	
	printf("%d \n", memcmp("abcdefghij", "abcdefgxyz", 7));
	printf("%d \n\n", ft_memcmp("abcdefghij", "abcdefgxyz", 7));

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
	printf("%s \n\n", ptr);

	// strncmp
	puts("STRNCMP");
	strcpy(src, "ABCDEFGHIJiKL");
	strcpy(dest, "ABCDEFGaHIJKL");
	printf("%d \n", strncmp(src, dest, 15));
	printf("%d \n\n", ft_strncmp(src, dest, 15));
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

	// atoi
	puts("ATOI");
	char stnum[] = "  \n\v\t\r\f\n\v\t\r\f546:5";
	printf("%d\n", atoi(stnum));
	char stnum2[] = "  \n\v\t\r\f\n\v\t\r\f546:5";
	printf("%d\n", ft_atoi(stnum2));
	printf("%s", stnum2);
	printf("%s\n", stnum);

	// calloc
	int *ptr1;
	ptr1 = calloc(1, 2147483647);
	ptr1[0] = 2147483647;
	char *str3 = "Hi how are you";
	printf("%p	ptr1	", ptr1);
	printf("%d\n", *ptr1);

	printf("%p	ptr1+1	", ptr1 + 1);
	printf("%d\n", *(ptr1 + 1));

	printf("%p	ptr1+2	", ptr1 + 2);
	printf("%d\n", *(ptr1 + 2));

	printf("%p	ptr1+3	", ptr1 + 3);
	printf("%d\n", *(ptr1 + 3));

	printf("%p	ptr1+4	", ptr1 + 4);
	printf("%d\n", *(ptr1 + 4));

	printf("%p	str3	", str3);
	printf("%s\n", str3);

	printf("%p	ptr1	", ptr1);
	printf("%d\n", *ptr1);

	printf("%p	ptr1+1	", ptr1 + 1);
	printf("%d\n", *(ptr1 + 1));

	printf("%p	ptr1+2	", ptr1 + 2);
	printf("%d\n", *(ptr1 + 2));

	printf("%p	ptr1+3	", ptr1 + 3);
	printf("%d\n", *(ptr1 + 3));

	printf("%p	ptr1+4	", ptr1 + 4);
	printf("%d\n", *(ptr1 + 4));

	// ft_calloc
	char *ptr2;
	ptr2 = ft_calloc(1, 2);

	printf("%p	ptr2	", ptr2);
	printf("%d\n", *ptr2);

	printf("%p	ptr2+1	", ptr2 + 1);
	printf("%d\n", *(ptr2 + 1));

	printf("%p	ptr2+2	", ptr2 + 2);
	printf("%d\n", *(ptr2 + 2));

	printf("%p	ptr2+3	", ptr2 + 3);
	printf("%d\n", *(ptr2 + 3));

	printf("%p	ptr2+4	", ptr2 + 4);
	printf("%d\n", *(ptr2 + 4));

	//strdup
	char *mystr, *yourstr;
	mystr = "hi how are you";
	yourstr = ft_strdup(mystr);
	printf("%s\n", yourstr);

	printf("%d\n",ft_strncmp("test\200", "test\0",6));

	//strtrim
	char	set [] = "\t \n";
	char s1[] = "lorem ipsum dolor sit amet \n \t\n \t  ";
	char *out;
	out = ft_strtrim(s1, set);
	printf("%s$", out);

	//split
	// char *myarray[20];
	// myarray[0][0] = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	// for (size_t i = 0; i < 20; i++)
	// {
	// 	printf("%s\n",myarray[i]);
	// }

	//itoa

	int n = 123456789;

	char s[10];
	s = ft_itoa(n);
	
	return (0);
}