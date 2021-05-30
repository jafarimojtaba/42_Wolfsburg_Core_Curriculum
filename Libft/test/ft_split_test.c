#include <stdio.h>>
int	ft_counter(const char *s, int c)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}
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
}