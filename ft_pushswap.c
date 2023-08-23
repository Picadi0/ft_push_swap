/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:52:30 by maltun            #+#    #+#             */
/*   Updated: 2023/08/22 10:33:29 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	gofree(char **av, int ac, int shouldfree)
{
	int	i;

	i = 0;
	if (!shouldfree)
		return ;
	while (i <= ac)
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	ft_init(t_swap *swap, char **av, int ac, int shouldfree)
{
	int	i;

	i = 0;
	check_int(av, ac, shouldfree);
	swap->stack_a = ft_calloc(sizeof(int *), ac + 1);
	swap->stack_b = ft_calloc(sizeof(int *), ac + 1);
	if (shouldfree)
	{
		while (av[i++])
		{
			swap->stack_a[i - 1] = ft_atoi(av[i - 1]);
			swap->count_a++;
		}
	}
	else
	{
		i = 1;
		while (av[i++])
		{
			swap->stack_a[i - 1 - 1] = ft_atoi(av[i - 1]);
			swap->count_a++;
		}
	}
	gofree(av, ac, shouldfree);
	ft_is_sorted(swap);
}

void	ft_print_stacks(t_swap *stack)
{
	int	i;

	i = 0;
	ft_printf("stack a = ");
	while (i < stack->count_a)
	{
		ft_printf("%d ", stack->stack_a[i]);
		i++;
	}
	ft_printf("\nstack b = ");
	i = 0;
	while (i < stack->count_b)
	{
		ft_printf("%d ", stack->stack_b[i]);
		i++;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_swap	*stack;

	stack = ft_calloc(sizeof(t_swap), 1);
	check_valid(ac, av, stack);
	ft_start_sort(stack);
	ft_print_stacks(stack);
	return (0);
}
