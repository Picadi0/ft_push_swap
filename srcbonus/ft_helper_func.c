/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:21:45 by maltun            #+#    #+#             */
/*   Updated: 2023/09/16 18:15:45 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_error(t_swap *stack)
{
	stack->count_a = 31;
	ft_printf("Error\n");
	exit(0);
}

char	*concat_with_char(char *str1, char *str2, char c)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = ft_calloc((ft_strlen(str1) + ft_strlen(str2)), sizeof(char *));
	while (str1 && str1[i])
	{
		ret[i] = str1[i];
		i++;
	}
	ret[i++] = c;
	while (str2 && str2[j])
	{
		ret[i] = str2[j];
		i++;
		j++;
	}
	free(str1);
	return (ret);
}

void	check_ifcontain_numb(char **av, int ac, int shouldfree)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
			{
				break ;
			}
			j++;
		}
		if (av[i][j] == 0)
		{
			ft_putstr_fd("Error\n", 2);
			gofree(av, ac, shouldfree);
			exit(0);
		}
		j = 0;
		i++;
	}
}

void	update_steps(t_swap *stack)
{
	int	i;

	i = 0;
	if (!stack->steps)
		stack->steps = ft_calloc(stack->count_a, sizeof(int));
	while (i < stack->count_a)
	{
		stack->steps[i] = find_largesti_after_num(stack, stack->stack_a[i]);
		if (i > stack->count_a / 2)
			stack->steps[i] += stack->count_a - i;
		else
			stack->steps[i] += i;
		stack->steps[i] += 1;
		i++;
	}
}

void	concat_all_av(int ac, char **av, t_swap *stack)
{
	int		i;
	int		j;
	char	*allinone;

	i = 1;
	j = 0;
	check_ifcontain_numb(&av[1], ac, 0);
	while (i - 1 < ac)
	{
		allinone = concat_with_char(allinone, av[i], ' ');
		i++;
	}
	check_valid_v2(allinone, stack, 1);
}
