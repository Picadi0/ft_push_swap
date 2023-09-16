/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:12:18 by maltun            #+#    #+#             */
/*   Updated: 2023/01/25 13:39:30 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static	unsigned int	ft_unlen(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		len++;
	else if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char				*ret;
	unsigned int		size;
	unsigned int		i;

	i = 0;
	size = ft_unlen(n);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = '\0';
	if (n < 0 && ++i)
	{
		ret[0] = '-';
		n *= -1;
	}
	while (i < size--)
	{
		ret[size] = (n % 10) + '0';
		n /= 10;
	}
	return (ret);
}

static	int	ft_nlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	else if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		size;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_nlen(n);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = '\0';
	if (n < 0 && ++i)
	{
		ret[0] = '-';
		n *= -1;
	}
	while (i < size--)
	{
		ret[size] = (n % 10) + '0';
		n /= 10;
	}
	return (ret);
}
