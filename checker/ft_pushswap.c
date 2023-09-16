/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:52:30 by maltun            #+#    #+#             */
/*   Updated: 2023/09/16 18:16:13 by maltun           ###   ########.fr       */
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
	else if (stack->count_a > 5)
		check_steps(stack);
}

void	sort_as_say(t_swap *stack, char *str)
{
	if (str[0] == 's' && str[1] == 'a' && str[2] == '\n')
		ft_swap(stack, 1);
	else if (str[0] == 's' && str[1] == 'b' && str[2] == '\n')
		ft_swap(stack, 0);
	else if (str[0] == 'r' && str[1] == 'a' && str[2] == '\n')
		ft_rotate_a(stack, 0);
	else if (str[0] == 'r' && str[1] == 'b' && str[2] == '\n')
		ft_rotate_a(stack, 0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		ft_reverse_rotate_a(stack, 0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		ft_reverse_rotate_b(stack, 0);
	else if (str[0] == 's' && str[1] == 's' && str[2] == '\n')
		ft_ss(stack);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\n')
		ft_rr(stack);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		ft_rrr(stack);
	else if (str[0] == 'p' && str[1] == 'a' && str[2] == '\n')
		ft_push_a(stack);
	else if (str[0] == 'p' && str[1] == 'b' && str[2] == '\n')
		ft_push_b(stack);
	else
		ft_error(stack);
}

int	main(int ac, char **av)
{
	t_swap	*stack;
	char	*str;

	stack = ft_calloc(1, sizeof(t_swap));
	check_valid(ac, av, stack);
	str = get_next_line(0);
	while (1)
	{
		if (!ft_strlen(str))
		{
			ft_printf("KO\n");
			exit(2);
		}
		if (ft_strlen(str) > 4 || ft_strlen(str) < 3)
			ft_error(stack);
		sort_as_say(stack, str);
		if (ft_issorted(stack))
		{
			ft_printf("OK\n");
			break ;
		}
		free(str);
		str = get_next_line(0);
	}
	return (0);
}
