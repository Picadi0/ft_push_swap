/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:48:53 by maltun            #+#    #+#             */
/*   Updated: 2023/09/02 18:37:41 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	check_int(char **av, int ac, int shouldfree)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!shouldfree)
		i = 1;
	while (av[i])
	{
		while (av[i][j] == '-' || av[i][j] == '0')
			j++;
		if (ft_strlen(&av[i][j]) > 11 \
		|| ft_atol(&av[i][j]) > 2147483647 || ft_atol(&av[i][j]) < -2147483648)
		{
			ft_putstr_fd("Error\n", 2);
			gofree(av, ac, shouldfree);
			exit(0);
		}
		j = 0;
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
					ft_putstr_fd("Error\n", 2);
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
					ft_putstr_fd("Error\n", 2);
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

void	check_valid_v2(char *av, t_swap *swap, int shouldfree)
{
	int		i;
	int		ac;
	char	**av2;

	i = 0;
	ac = 0;
	av2 = ft_split(av, ' ');
	free(av);
	while (av2[ac])
		ac++;
	if (ac == 0)
	{
		gofree(av2, ac, shouldfree);
		exit(0);
	}
	if (ac == 1)
	{
		check_values(ac - 1, av2, swap, shouldfree);
		exit(0);
	}
	check_values(ac - 1, av2, swap, shouldfree);
}

void	check_valid(int ac, char **av, t_swap *swap)
{
	int	i;

	i = 0;
	if (ac == 1)
		exit(0);
	else
		concat_all_av(ac, av, swap);
}
