/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 00:25:01 by maltun            #+#    #+#             */
/*   Updated: 2023/08/22 18:28:36 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_reverse_rotate_b(t_swap *stack, int printinfo)
{
	int	last;
	int	lastint;

	if (ft_issorted(stack))
		return ;
	last = stack->count_b;
	lastint = stack->stack_b[last - 1];
	while (last)
	{
		stack->stack_b[last] = stack->stack_b[last - 1];
		last--;
	}
	stack->stack_b[0] = lastint;
	if (printinfo)
		ft_printf("rra\n");
}

void	ft_rrr(t_swap *stack)
{
	if (ft_issorted(stack))
		return ;
	ft_reverse_rotate_a(stack, 0);
	ft_reverse_rotate_b(stack, 0);
	ft_printf("rrr\n");
}
