/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:01:32 by maltun            #+#    #+#             */
/*   Updated: 2023/01/26 03:42:29 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned long	ft_strhexlen(unsigned long n)
{
	unsigned long	count;

	count = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n)
	{
		n /= 16;
		count++;
	}
	return (count);
}

char	*convert(char *str, char flag, int *len)
{
	char const			*base16;
	char				*ret;
	unsigned long		i;
	unsigned long		lent;

	i = ft_atol(str);
	lent = ft_strhexlen(i);
	ret = malloc(sizeof(char) * lent);
	base16 = "0123456789abcdef";
	if (flag == 'p')
		*len += ft_putstr("0x", 'n');
	else if (flag == 'X')
		base16 = "0123456789ABCDEF";
	while (lent-- > 0)
	{
		*(ret + lent) = base16[i % 16];
		i /= 16;
	}
	return (ret);
}

unsigned long	ft_nlen(unsigned long n)
{
	unsigned long	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_ltoa(unsigned long n, char flag, int *len)
{
	char					*ret;
	void					*firi;
	unsigned long			size;
	unsigned long			i;

	size = ft_nlen(n);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	ret[size] = '\0';
	while (i < size--)
	{
		ret[size] = (n % 10) + '0';
		n /= 10;
	}
	firi = convert(ret, flag, len);
	free(ret);
	return (firi);
}

int	ft_putstr(char *str, char flag)
{
	if (flag == 'p')
	{
		if (ft_strlen(str) > 16)
		{
			write(1, str, 16);
			return (16);
		}
		else
		{
			write(1, str, ft_strlen(str));
			return (ft_strlen(str));
		}
	}
	else if (str == NULL)
		write(1, "(null)", 6);
	else
	{
		write(1, str, ft_strlen(str));
		return (ft_strlen(str));
	}
	return (6);
}
