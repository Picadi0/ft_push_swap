/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:52:55 by maltun            #+#    #+#             */
/*   Updated: 2023/07/29 00:28:25 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_swap
{
	int	*stack_a;
	int	*stack_b;
	int	count_a;
	int	count_b;
}	t_swap;

void	check_valid(int ac, char **av, t_swap *swap);
void	ft_push_b(t_swap *swap);
void	ft_push_a(t_swap *swap);
void	gofree(char **av, int ac, int shouldfree);
void	ft_init(t_swap *swap, char **av, int ac, int shouldfree);
void	check_int(char **av, int ac, int shouldfree);
void	ft_swap(t_swap *stack, int isA);
void	ft_push_a_2(t_swap *stack);
void	ft_rotate_a(t_swap *stack, int printinfo);
void	ft_rotate_b(t_swap *stack, int printinfo);
void	ft_reverse_rotate_a(t_swap *stack, int printinfo);
void	ft_reverse_rotate_b(t_swap *stack, int printinfo);
void	ft_rr(t_swap *stack);
void	ft_rrr(t_swap *stack);

#endif