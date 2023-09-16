/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 03:01:31 by maltun            #+#    #+#             */
/*   Updated: 2023/09/16 15:04:51 by maltun           ###   ########.fr       */
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

void	which_will_rotate_in_b(t_swap *stack)
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
		rotate_until_ready_get_push(stack, \
		find_biggest_in_stack_b(stack), find_biggest_indx_in_stack_b(stack));
	else
		rotate_until_ready_get_push(stack, ret, ret_index);
}

void	test(t_swap *stack, int num, int num_index)
{
	int	small_step_i;
	int	small_step;

	small_step_i = get_smallest_step_index(stack);
	small_step = stack->stack_a[small_step_i];
	while (stack->stack_b[0] != num && stack->stack_a[0] != small_step)
	{
		if (num_index <= stack->count_b / 2 && small_step_i <= stack->count_a / 2)
			ft_rr(stack);
		else if (num_index > stack->count_b / 2 && small_step_i > stack->count_a / 2)
			ft_rrr(stack);
		else
			break ;
	}
	//b rotate
	while (stack->stack_b[0] != num)
	{
		if (num_index <= stack->count_b / 2)
			ft_rotate_b(stack, 1);
		else
			ft_reverse_rotate_b(stack, 1);
	}
	//a rotate
	while (stack->stack_a[0] != small_step)
	{
		if (small_step_i <= stack->count_a / 2)
			ft_rotate_a(stack, 1);
		else
			ft_reverse_rotate_a(stack, 1);
	}
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
	update_steps(stack);
	which_will_rotate_in_b(stack);
}
