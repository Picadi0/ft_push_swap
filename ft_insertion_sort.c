/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:21:17 by maltun            #+#    #+#             */
/*   Updated: 2023/09/05 00:14:37y maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	get_smallest_step_index(t_swap *stack)
{
	int	i;
	int	ret;
	int	ret_index;

	i = 0;
	ret = stack->stack_a[0];
	ret_index = 0;
	while (i < stack->count_a)
	{
		if (stack->steps[i] < ret)
		{
			ret = stack->steps[i];
			ret_index = i;
		}
		i++;
	}
	return (ret_index);
}

void	rotate_stacks_for_push(t_swap *stack)
{
	int	small_step_i;
	int	small_step;

	small_step_i = get_smallest_step_index(stack);
	small_step = stack->stack_a[small_step_i];
	while (stack->stack_a[0] != small_step)
	{
		if (small_step_i <= stack->count_a / 2)
			ft_rotate_a(stack, 1);
		else
			ft_reverse_rotate_a(stack, 1);
	}
}