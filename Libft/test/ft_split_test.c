#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../dev/libft.h"
#include "../dev/ft_strtrim.c"
#include "../dev/ft_split.c"
#include "../dev/ft_strlen.c"
#include "../dev/ft_strlcpy.c"
#include "../dev/ft_substr.c"

int	ft_counter2(const char *s, int c)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s && *s == c)
			count++;
			s++;
	}
	return (count);
}
int main()
{
	int i;
	i = ft_counter("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	printf("%d\n", i);
	i = ft_counter2("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	printf("%d\n", i);
	printf("%ld", ft_strlen(""));
	char	set [] = "\t \n";
	char s1[] = "lorem ipsum dolor sit amet \n \t\n \t  ";
	char *out;
	out = ft_strtrim(s1, set);
	printf("%s$\n", out);

	//split
	char **myarray;
	myarray = ft_split("      split       this for   me  !       ", ' ');
	for (size_t i = 0; i < 5; i++)
	{
		printf("%s\n",myarray[i]);
	}
}