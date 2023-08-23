/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:39:32 by maltun            #+#    #+#             */
/*   Updated: 2023/08/22 19:23:51 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_caseof_3(t_swap *stack)
{
	if (ft_issorted(stack))
		return ;
	if (stack->sorted[0] == stack->stack_a[0])
	{
		ft_push_b(stack);
		ft_swap(stack, 1);
		ft_push_a(stack);
	}
	else if (stack->sorted[0] == stack->stack_a[1])
	{
		ft_reverse_rotate_a(stack, 1);
		if (stack->stack_a[0] > stack->stack_a[1])
			ft_swap(stack, 1);
		ft_reverse_rotate_a(stack, 1);
	}
	else if (stack->sorted[0] == stack->stack_a[2])
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			ft_swap(stack, 1);
		ft_reverse_rotate_a(stack, 1);
	}
}

void	ft_caseof_4(t_swap *stack)
{
	if (ft_issorted(stack))
		return ;
	if (stack->sorted[0] == stack->stack_a[0])
	{
		ft_push_b(stack);
	}
	else if (stack->sorted[0] == stack->stack_a[1])
	{
		ft_rotate_a(stack, 1);
		ft_push_b(stack);
	}
	else if (stack->sorted[0] == stack->stack_a[2])
	{
		ft_rotate_a(stack, 1);
		ft_rotate_a(stack, 1);
		ft_push_b(stack);
	}
	else if (stack->sorted[0] == stack->stack_a[3])
	{
		ft_reverse_rotate_a(stack, 1);
		ft_push_b(stack);
	}
	ft_re_sort(stack);
	if (!ft_issorted(stack))
		ft_caseof_3(stack);
	ft_push_a(stack);
	ft_re_sort(stack);
}

void	ft_caseof_5(t_swap *stack)
{
	if (ft_issorted(stack))
		return ;
	if (stack->sorted[0] == stack->stack_a[0])
	{
		ft_push_b(stack);
	}
	else if (stack->sorted[0] == stack->stack_a[1])
	{
		ft_rotate_a(stack, 1);
		ft_push_b(stack);
	}
	else if (stack->sorted[0] == stack->stack_a[2])
	{
		ft_rotate_a(stack, 1);
		ft_rotate_a(stack, 1);
		ft_push_b(stack);
	}
	else if (stack->sorted[0] == stack->stack_a[3])
	{
		ft_reverse_rotate_a(stack, 1);
		ft_reverse_rotate_a(stack, 1);
		ft_push_b(stack);
	}
	else if (stack->sorted[0] == stack->stack_a[4])
	{
		ft_reverse_rotate_a(stack, 1);
		ft_push_b(stack);
	}
	ft_re_sort(stack);
	if (!ft_issorted(stack))
		ft_caseof_4(stack);
	ft_push_a(stack);
	ft_re_sort(stack);
}

void	ft_start_sort(t_swap *stack)
{
	if (stack->count_a == 2)
		ft_swap(stack, 1);
	else if (stack->count_a == 3)
		ft_caseof_3(stack);
	else if (stack->count_a == 4)
		ft_caseof_4(stack);
	else if (stack->count_a == 5)
		ft_caseof_5(stack);
}
