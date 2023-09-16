/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:37:47 by maltun            #+#    #+#             */
/*   Updated: 2023/07/19 19:21:42 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (c != (char)48 && !c)
		write(1, "", 1);
	else
		write(1, &c, 1);
	return (1);
}

int	writeuntil(char *str)
{
	int	i;

	i = 0;
	while (*str && *str != '%')
	{
		ft_putchar(*str);
		i++;
		str++;
	}
	return (i);
}

void	print2(const char *str, int *len, va_list *lst, void *itoa)
{
	if (*str == '%' && *(str + 1) == 'p')
	{
		itoa = ft_ltoa(va_arg(*lst, unsigned long), *(str + 1), len);
		*len += ft_putstr(itoa, 'p');
	}
	else if (*str == '%' && (*(str + 1) == 'd' || *(str + 1) == 'i'))
	{
		itoa = (void *)ft_itoa(va_arg(*lst, int));
		*len += ft_putstr(itoa, 'n');
	}
	else if (*str == '%' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
	{
		itoa = ft_ltoa(va_arg(*lst, unsigned int), *(str + 1), len);
		*len += ft_putstr(itoa, 'n');
	}
	else if (*str == '%' && *(str + 1) == 'u')
	{
		itoa = (void *)ft_uitoa(va_arg(*lst, unsigned int));
		*len += ft_putstr(itoa, 'n');
	}
	if (itoa)
		free(itoa);
}

void	print(const char *str, int *len, va_list *lst, int *jump)
{
	void	*itoa;

	itoa = NULL;
	if (*str == '%' && *(str + 1) == 'c')
		*len += ft_putchar(va_arg(*lst, int));
	else if (*str == '%' && *(str + 1) == '%')
		*len += ft_putchar('%');
	else if (*str == '%' && *(str + 1) == 's')
		*len += ft_putstr(va_arg(*lst, char *), 'n');
	else if (*str == '%' && *(str + 1) == 'u')
		print2(str, len, lst, itoa);
	else if (*str == '%' && *(str + 1) == 'p')
		print2(str, len, lst, itoa);
	else if (*str == '%' && (*(str + 1) == 'd' || *(str + 1) == 'i'))
		print2(str, len, lst, itoa);
	else if (*str == '%' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		print2(str, len, lst, itoa);
	else if (*str)
	{
		*jump = writeuntil((char *)str);
		*len += *jump;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		len;
	int		jump;

	len = 0;
	jump = 0;
	va_start(lst, str);
	while (*str)
	{
		print(str, &len, &lst, &jump);
		if (*str == '%')
			str = str + 2;
		else
			str += jump;
	}
	va_end(lst);
	return (len);
}
