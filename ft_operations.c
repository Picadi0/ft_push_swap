/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:35:39 by maltun            #+#    #+#             */
/*   Updated: 2023/09/03 02:48:15 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
//sa/sb operations
void	ft_swap(t_swap *stack, int swapa)
{
	int	tmp;

	if (swapa)
	{
		if (stack->count_a > 1)
		{
			tmp = stack->stack_a[0];
			stack->stack_a[0] = stack->stack_a[1];
			stack->stack_a[1] = tmp;
			ft_printf("sa\n");
		}
	}
	else
	{
		if (stack->count_b > 1)
		{
			tmp = stack->stack_b[0];
			stack->stack_b[0] = stack->stack_b[1];
			stack->stack_b[1] = tmp;
			ft_printf("sb\n");
		}
	}
}

void	ft_ss(t_swap *stack)
{
	int	tmp;

	if (stack->count_a > 1)
	{
		tmp = stack->stack_a[0];
		stack->stack_a[0] = stack->stack_a[1];
		stack->stack_a[1] = tmp;
	}
	if (stack->count_b > 1)
	{
		tmp = stack->stack_b[0];
		stack->stack_b[0] = stack->stack_b[1];
		stack->stack_b[1] = tmp;
	}
	ft_printf("ss\n");
}

void	ft_push_b_2(t_swap *stack)
{
	int	last;
	int	i;

	i = 0;
	last = stack->count_b;
	while (last)
	{
		stack->stack_b[last] = stack->stack_b[last - 1];
		last--;
	}
	stack->stack_b[0] = stack->stack_a[0];
	while (i < stack->count_a)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->count_b++;
	stack->count_a--;
	ft_printf("pb\n");
}

void	ft_push_b(t_swap *stack)
{
	int	last;
	int	i;

	if (!stack->count_a)
		return ;
	last = stack->count_b;
	i = 0;
	if (!last)
	{
		stack->stack_b[0] = stack->stack_a[0];
		while (i < stack->count_a)
		{
			stack->stack_a[i] = stack->stack_a[i + 1];
			i++;
		}
		stack->count_b++;
		stack->count_a--;
		ft_printf("pb\n");
	}
	else
		ft_push_b_2(stack);
}

void	ft_push_a(t_swap *stack)
{
	int	last;
	int	i;

	if (!stack->count_b)
		return ;
	last = stack->count_a;
	i = 0;
	if (!last)
	{
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
	else
		ft_push_a_2(stack);
}
