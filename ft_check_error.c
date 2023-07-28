/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:48:53 by maltun            #+#    #+#             */
/*   Updated: 2023/07/28 18:46:44 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	check_int(char **av, int ac, int shouldfree)
{
	int	i;

	i = 0;
	if (!shouldfree)
		i = 1;
	while (av[i])
	{
		if (ft_strlen(av[i]) > 11 \
		|| ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < -2147483648)
		{
			ft_printf("Error : value must be integer\n");
			gofree(av, ac, shouldfree);
			exit(0);
		}
		i++;
	}
}

void	check_repeats(char **av, t_swap *swap, int ac, int shouldfree)
{
	int	i;
	int	j;
	int	o;

	i = 0;
	if (!shouldfree)
		i = 1;
	while (av[i++])
	{
		o = i;
		while (av[o++])
		{
			j = 0;
			while (av[i - 1][j] == av[o - 1][j] && ++j) 
			{
				if (av[i - 1][j - 1] == '\0' && av[o - 1][j - 1] == '\0') 
				{
					ft_printf("Error :%s\n", "Values should not repeats");
					gofree(av, ac, shouldfree);
					exit(0);
				}
			}
		}
	}
	ft_init(swap, av, ac, shouldfree);
}

void	check_values(int ac, char **av, t_swap *swap, int shouldfree)
{
	int	i;
	int	j;

	i = 0;
	if (!shouldfree)
		i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				if (!(j == 0 && av[i][j] == '-' && av[i][1]))
				{
					ft_printf("%s\n", "Error: Malformed input");
					gofree(av, ac, shouldfree);
					exit(0);
				}
			}
			j++;
		}
		i++;
	}
	check_repeats(av, swap, ac, shouldfree);
}

void	check_valid_v2(char **av, t_swap *swap, int shouldfree)
{
	int		i;
	int		ac;
	char	**av2;

	i = 0;
	ac = 0;
	av2 = ft_split(av[1], ' ');
	while (av2[ac])
		ac++;
	if (ac == 0)
	{
		ft_printf("%s\n", "Error: no input");
		gofree(av2, ac, shouldfree);
		exit(0);
	}
	if (ac == 1)
	{
		gofree(av2, ac, shouldfree);
		exit(0);
	}
	check_values(ac - 1, av2, swap, shouldfree);
}

void	check_valid(int ac, char **av, t_swap *swap)
{
	int	i;

	i = 0;
	if (ac == 1)
	{
		ft_printf("%s\n", "Error: no input");
		gofree(av, ac, 0);
		exit(0);
	}
	if (ac == 2)
	{
		check_valid_v2(av, swap, 1);
	}
	else
	{
		check_values(ac, av, swap, 0);
	}
}
