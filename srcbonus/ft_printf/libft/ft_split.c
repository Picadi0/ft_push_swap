/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:45:54 by maltun            #+#    #+#             */
/*   Updated: 2023/07/24 20:16:03 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcounter(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			return (i);
		while (*s != c && *s)
			s++;
		i++;
	}
	return (i);
}

int	start_split(char **ret, char const *s, char c)
{
	int	i;
	int	i2;
	int	len;

	i = 0;
	i2 = 0;
	len = 0;
	while (s[i2])
	{
		while (s[i2] && s[i2] != c)
		{
			len++;
			i2++;
		}
		if ((s[i2] == c || s[i2] == 0) && len > 0)
			ret[i++] = ft_substr(&s[i2] - len, 0, len);
		len = 0;
		if (s[i2] != 0)
			i2++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (0);
	ret = ft_calloc(sizeof(char *), (wordcounter(s, c) + 1));
	if (!ret)
		return (0);
	ret[start_split(ret, s, c)] = 0;
	return (ret);
}
