#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strlcpy(char *dst, const char *src, int size)
{
	int	i;
	int	result;

	i = 0;
	result = ft_strlen((char *)src);
	if (size < 1)
		return (result);
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (result);
}

int	ft_atoi(const char *s)
{
	int	result;
	int	neg;
	int	i;

	result = 0;
	neg = 1;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + s[i] - '0';
		i++;
	}
	result *= neg;
	return (result);
}