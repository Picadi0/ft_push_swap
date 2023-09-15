/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:44:16 by maltun            #+#    #+#             */
/*   Updated: 2023/09/16 00:46:31 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_push_a_2(t_swap *stack)
{
	int	last;
	int	i;

	if (!stack->count_a)
		return ;
	i = 0;
	last = stack->count_a;
	while (last)
	{
		stack->stack_a[last] = stack->stack_a[last - 1];
		last--;
	}
	stack->stack_a[0] = stack->stack_b[0];
	while (i < stack->count_b)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->count_a++;
	stack->count_b--;
	ft_printf("pa\n");
}

void	ft_rotate_a(t_swap *stack, int printinfo)
{
	int	i;
	int	first;

	if (!stack->count_a)
		return ;
	i = 0;
	first = stack->stack_a[0];
	while (i < stack->count_a)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i - 1] = first;
	if (printinfo)
		ft_printf("ra\n");
}

void	ft_rotate_b(t_swap *stack, int printinfo)
{
	int	i;
	int	first;

	if (!stack->count_b)
		return ;
	i = 0;
	first = stack->stack_b[0];
	while (i < stack->count_b)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i - 1] = first;
	if (printinfo)
		ft_printf("rb\n");
}

void	ft_rr(t_swap *stack)
{
	ft_rotate_a(stack, 0);
	ft_rotate_b(stack, 0);
	ft_printf("rr\n");
}

void	ft_reverse_rotate_a(t_swap *stack, int printinfo)
{
	int	last;
	int	lastint;

	if (ft_issorted(stack))
		return ;
	last = stack->count_a;
	lastint = stack->stack_a[last - 1];
	while (last)
	{
		stack->stack_a[last] = stack->stack_a[last - 1];
		last--;
	}
	stack->stack_a[0] = lastint;
	if (printinfo)
		ft_printf("rra\n");
}
