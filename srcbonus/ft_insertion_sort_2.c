/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:12:51 by maltun            #+#    #+#             */
/*   Updated: 2023/09/16 15:49:33 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	get_smallest_step_index(t_swap *stack)
{
	int	i;
	int	ret;
	int	ret_index;

	i = 0;
	ret = stack->steps[0];
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

int	find_biggest_indx_in_stack_b(t_swap *stack)
{
	int	i;
	int	ret_index;
	int	ret;

	i = 0;
	ret_index = 0;
	ret = stack->stack_b[0];
	while (i < stack->count_b)
	{
		if (ret < stack->stack_b[i])
		{
			ret = stack->stack_b[i];
			ret_index = i;
		}
		i++;
	}
	return (ret_index);
}

int	find_biggest_in_stack_b(t_swap *stack)
{
	int	i;
	int	ret_index;
	int	ret;

	i = 0;
	ret_index = 0;
	ret = stack->stack_b[0];
	while (i < stack->count_b)
	{
		if (ret < stack->stack_b[i])
		{
			ret = stack->stack_b[i];
			ret_index = i;
		}
		i++;
	}
	return (ret);
}

void	last_stage(t_swap *stack)
{
	int	num_index;
	int	num;

	num_index = find_biggest_indx_in_stack_b(stack);
	num = find_biggest_in_stack_b(stack);
	while (stack->stack_b[0] != num)
	{
		if (num_index <= stack->count_b / 2)
			ft_rotate_b(stack, 1);
		else
			ft_reverse_rotate_b(stack, 1);
	}
	while (stack->count_b)
		ft_push_a(stack);
}
