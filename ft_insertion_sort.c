/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 03:01:31 by maltun            #+#    #+#             */
/*   Updated: 2023/09/16 15:54:43 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	rotate_until_ready_get_push(t_swap *stack, int num, int num_index)
{
	while (stack->stack_b[0] != num)
	{
		if (num_index <= stack->count_b / 2)
			ft_rotate_b(stack, 1);
		else
			ft_reverse_rotate_b(stack, 1);
	}
	ft_push_b(stack);
	check_steps(stack);
}

void	until_rotate_b(t_swap *stack, int num, int num_index)
{
	while (stack->stack_b[0] != num)
	{
		if (stack->count_b % 2 == 0)
		{
			if (num_index <= stack->count_b / 2)
				ft_rotate_b(stack, 1);
			else
				ft_reverse_rotate_b(stack, 1);
		}
		else
		{
			if (num_index <= (stack->count_b + 1) / 2)
				ft_rotate_b(stack, 1);
			else
				ft_reverse_rotate_b(stack, 1);
		}
	}
}

void	until_rotate_a(t_swap *stack, int small_step, int small_step_i)
{
	while (stack->stack_a[0] != small_step)
	{
		if (stack->count_a % 2 == 0)
		{
			if (small_step_i <= stack->count_a / 2)
				ft_rotate_a(stack, 1);
			else
				ft_reverse_rotate_a(stack, 1);
		}
		else
		{
			if (small_step_i <= (stack->count_a + 1) / 2)
				ft_rotate_a(stack, 1);
			else
				ft_reverse_rotate_a(stack, 1);
		}
	}
}

void	test(t_swap *stack, int num, int num_index)
{
	int	small_step_i;
	int	small_step;

	small_step_i = get_smallest_step_index(stack);
	small_step = stack->stack_a[small_step_i];
	while (stack->stack_b[0] != num && stack->stack_a[0] != small_step)
	{
		if (num_index <= stack->count_b / 2 \
		&& small_step_i <= stack->count_a / 2)
			ft_rr(stack);
		else if (num_index > stack->count_b / 2 \
		&& small_step_i > stack->count_a / 2)
			ft_rrr(stack);
		else
			break ;
	}
	until_rotate_b(stack, num, num_index);
	until_rotate_a(stack, small_step, small_step_i);
	ft_push_b(stack);
	check_steps(stack);
}

void	rotate_same_time(t_swap *stack)
{
	int	i;
	int	ret_index;
	int	ret;
	int	flag;

	i = 0;
	ret = 0;
	flag = 0;
	while (i < stack->count_b)
	{
		if (stack->stack_b[i] <= stack->stack_a[get_smallest_step_index(stack)] \
		&& (stack->stack_b[i] >= ret || !ret))
		{
			flag = 1;
			ret = stack->stack_b[i];
			ret_index = i;
		}
		i++;
	}
	if (!flag)
		test(stack, \
		find_biggest_in_stack_b(stack), find_biggest_indx_in_stack_b(stack));
	else
		test(stack, ret, ret_index);
}
