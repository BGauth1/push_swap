/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:07:39 by gbertet           #+#    #+#             */
/*   Updated: 2023/03/29 15:07:41 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

long long	ft_atoi(const char *s)
{
	long long	result;
	int			neg;
	int			i;

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

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		i;
	size_t		len1;
	size_t		len2;
	char		*result;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc((len1 + len2 + 2) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}
	while (i - len1 < len2)
	{
		result[i] = s2[i - len1];
		i++;
	}
	result[i] = ' ';
	result[i + 1] = '\0';
	return (result);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	int		len;

	len = ft_strlen(s);
	res = malloc((len + 2) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, len + 1);
	res[len] = ' ';
	res[len + 1] = '\0';
	return (res);
}
