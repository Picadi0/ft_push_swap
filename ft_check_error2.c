/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:21:53 by maltun            #+#    #+#             */
/*   Updated: 2023/08/06 00:21:15 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_is_sorted_2(int *stacka, t_swap *stack)
{
	int	i;

	i = 0;
	while (i < stack->count_a && stack->count_a != 1)
	{
		if (stack->stack_a[i] == stacka[i] && i + 1 == stack->count_a)
		{
			free(stacka);
			exit(0);
		}
		i++;
	}
	free(stacka);
}

void	ft_is_sorted(t_swap *stack)
{
	int	i;
	int	j;
	int	tmp;
	int	*stacka;

	i = 0;
	stacka = ft_calloc(stack->count_a, sizeof(int));
	while (i++ < stack->count_a)
		stacka[i - 1] = stack->stack_a[i - 1];
	i = 0;
	while (i < stack->count_a)
	{
		j = i + 1;
		while (j++ < stack->count_a)
		{
			if (stacka[i] > stacka[j - 1])
			{
				tmp = stacka[i];
				stacka[i] = stacka[j - 1];
				stacka[j - 1] = tmp;
			}
		}
		i++;
	}
	ft_is_sorted_2(stacka, stack);
}
