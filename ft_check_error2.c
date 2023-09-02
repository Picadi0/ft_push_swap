/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:21:53 by maltun            #+#    #+#             */
/*   Updated: 2023/09/02 18:37:58 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	last_check(t_swap *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->count_a)
	{
		j = i + 1;
		while (j < stack->count_a)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
			{
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	ft_is_sorted_2(t_swap *stack)
{
	int	i;

	i = 0;
	last_check(stack);
	while (i < stack->count_a && stack->count_a != 1)
	{
		if (stack->stack_a[i] != stack->sorted[i])
			break ;
		if (i + 1 == stack->count_a)
		{
			free(stack->sorted);
			exit(0);
		}
		i++;
	}
}

int	ft_issorted(t_swap *stack)
{
	int	i;

	i = 0;
	while (i < stack->count_a)
	{
		if (stack->stack_a[i] != stack->sorted[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_re_sort(t_swap *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	if (!stack->sorted)
		stack->sorted = ft_calloc(stack->count_a, sizeof(int));
	stack->count_sorted = stack->count_a;
	while (i++ < stack->count_a)
		stack->sorted[i - 1] = stack->stack_a[i - 1];
	i = 0;
	while (i < stack->count_a)
	{
		j = i + 1;
		while (j++ < stack->count_a)
		{
			if (stack->sorted[i] > stack->sorted[j - 1])
			{
				tmp = stack->sorted[i];
				stack->sorted[i] = stack->sorted[j - 1];
				stack->sorted[j - 1] = tmp;
			}
		}
		i++;
	}
}

void	ft_is_sorted(t_swap *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	stack->sorted = ft_calloc(stack->count_a, sizeof(int));
	stack->count_sorted = stack->count_a;
	while (i++ < stack->count_a)
		stack->sorted[i - 1] = stack->stack_a[i - 1];
	i = 0;
	while (i < stack->count_a)
	{
		j = i + 1;
		while (j++ < stack->count_a)
		{
			if (stack->sorted[i] > stack->sorted[j - 1])
			{
				tmp = stack->sorted[i];
				stack->sorted[i] = stack->sorted[j - 1];
				stack->sorted[j - 1] = tmp;
			}
		}
		i++;
	}
	ft_is_sorted_2(stack);
}
