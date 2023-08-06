/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:52:30 by maltun            #+#    #+#             */
/*   Updated: 2023/08/05 22:50:39 by maltun           ###   ########.fr       */
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

int	main(int ac, char **av)
{
	int		i;
	t_swap	*swap;

	i = 0;
	swap = ft_calloc(sizeof(t_swap), 1);
	check_valid(ac, av, swap);
	ft_push_b(swap);
	ft_printf("stack a = ");
	while (i < swap->count_a)
	{
		ft_printf("%d ", swap->stack_a[i]);
		i++;
	}
	ft_printf("\nstack b = ");
	i = 0;
	while (i < swap->count_b)
	{
		ft_printf("%d ", swap->stack_b[i]);
		i++;
	}
	ft_printf("\n");
	return (0);
}
