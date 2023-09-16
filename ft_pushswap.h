/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:52:55 by maltun            #+#    #+#             */
/*   Updated: 2023/09/16 20:32:03 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_swap
{
	int	*steps;
	int	*sorted;
	int	count_sorted;
	int	*stack_a;
	int	*stack_b;
	int	count_a;
	int	count_b;
	int	num;
	int	num_index;
}	t_swap;

void	try_rotate_both(t_swap *stack);
void	start_to_rotate(t_swap *stack, int num, int num_index);
void	rotate_same_time(t_swap *stack);
int		get_smallest_step_index(t_swap *stack);
void	last_stage(t_swap *stack);
void	check_for_same_times(t_swap *stack);
int		find_biggest_indx_in_stack_b(t_swap *stack);
void	rotate_stacks_for_push(t_swap *stack);
void	ft_insertion_sort(t_swap *stack);
void	check_steps(t_swap *stack);
void	update_steps(t_swap *stack);
int		find_largesti_after_num(t_swap *stack, int num);
int		find_biggest_in_stack_b(t_swap *stack);
void	ft_caseof_5(t_swap *stack);
void	ft_caseof_4(t_swap *stack);
void	ft_caseof_3(t_swap *stack);
void	concat_all_av(int ac, char **av, t_swap *stack);
void	check_ifcontain_numb(char **av, int ac, int shouldfree);
void	check_valid_v2(char *av, t_swap *swap, int shouldfree);
char	*concat_with_char(char *str1, char *str2, char c);
void	last_check(t_swap *stack);
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
void	ft_is_sorted(t_swap *stack);
void	ft_start_sort(t_swap *stack);
char	**until_see_numb(char **av, int ac);
void	ft_re_sort(t_swap *stack);
int		ft_issorted(t_swap *stack);
void	ft_insertion_sort(t_swap *stack);

#endif