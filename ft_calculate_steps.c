/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_steps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 02:58:46 by maltun            #+#    #+#             */
/*   Updated: 2023/09/16 14:29:39 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	check_ra_rra(t_swap *stack, int ret_index)
{
	if (ret_index >= stack->count_b / 2)
		return (stack->count_b - ret_index);
	else
		return (ret_index);
}

int	get_stack_b_moves(t_swap *stack, int org_ret_index, int flag)
{
	int	i;
	int	ret;
	int	ret_index;

	i = 0;
	ret = stack->stack_b[0];
	ret_index = 0;
	if (flag)
		return (check_ra_rra(stack, org_ret_index));
	while (i < stack->count_b)
	{
		if (ret < stack->stack_b[i])
		{
			ret = stack->stack_b[i];
			ret_index = i;
		}
		i++;
	}
	ret_index = check_ra_rra(stack, ret_index);
	return (ret_index);
}

int	find_largesti_after_num(t_swap *stack, int num)
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
		if (stack->stack_b[i] <= num && (stack->stack_b[i] >= ret || !ret))
		{
			flag = 1;
			ret = stack->stack_b[i];
			ret_index = i;
		}
		i++;
	}
	return (get_stack_b_moves(stack, ret_index, flag));
}

void	check_steps(t_swap *stack)
{
	int	i;

	i = 0;
	if (!stack->count_a)
	{
		last_stage(stack);
		return ;
	}
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
	rotate_same_time(stack);
}

void	ft_insertion_sort(t_swap *stack)
{
	ft_push_b(stack);
	ft_push_b(stack);
	check_steps(stack);
}
