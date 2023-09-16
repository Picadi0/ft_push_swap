/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:07:02 by maltun            #+#    #+#             */
/*   Updated: 2023/01/26 03:37:26 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_putstr(char *str, char flag);
int		ft_putchar(char c);
char	*ft_ltoa(unsigned long n, char flag, int *len);
char	*convert(char *str, char flag, int *len);
size_t	ft_nlen(size_t n);

#endif
