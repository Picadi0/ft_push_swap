/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:39:32 by maltun            #+#    #+#             */
/*   Updated: 2023/08/26 16:29:05 by maltun           ###   ########.fr       */
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

void	ft_caseof_4_2(t_swap *stack)
{
	ft_re_sort(stack);
	if (!ft_issorted(stack))
		ft_caseof_3(stack);
	ft_push_a(stack);
	ft_re_sort(stack);
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
	ft_caseof_4_2(stack);
}

void	ft_caseof_5_2(t_swap *stack)
{
	if (stack->sorted[0] == stack->stack_a[3])
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
	ft_caseof_5_2(stack);
}
