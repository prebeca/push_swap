/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:26:53 by user42            #+#    #+#             */
/*   Updated: 2021/04/29 19:08:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "libft.h"

/*
** stack
*/
typedef struct	s_stack
{
	int				value;
	struct s_stack	*previous;
	struct s_stack	*next;
}				t_stack;

/*
** stack operations
*/
t_stack			*ft_stacknew(int value);
void			ft_stackadd_front(t_stack **stack, t_stack *new_elem);
void			ft_stackadd_back(t_stack **stack, t_stack *new_elem);
int				ft_stacksize(t_stack *stack);
t_stack			*ft_stacklast(t_stack *stack);
void			ft_stackdelone(t_stack *stack);
void			ft_stackclear(t_stack **stack);

/*
** Instructions
*/
void			push(t_stack **src, t_stack **dst, char *instruction);
void			swap(t_stack **stack, char *instruction);
void			rotate(t_stack **stack, char *instruction);
void			reverse_rotate(t_stack **stack, char *instruction);

/*
** Sorting algo
*/
void			choose_best_sorter(t_stack **stack_a);
void			sorter(t_stack **stack_a);

/*
** push_swap
*/
t_stack			*create_stack(int argc, char **argv);
void			print_stacks(t_stack *stack_a, t_stack *stack_b);
bool			has_duplicate(t_stack *stack);
bool			is_sorted_ascdt(t_stack *stack);
bool			is_sorted_dscdt(t_stack *stack);

/*
** Utilities
*/
int				is_int(char *num);
t_stack			*ft_stackatindex(t_stack *stack, int index);
t_stack			*find_n_smallest(t_stack *stack, int n);
t_stack			*find_n_biggest(t_stack *stack, int n);
void			get_it_to_the_top(t_stack **stack_a, int stack_len,
int elem_pos);
int				ft_stack_index_of(t_stack *stack, t_stack *elem);
int				get_index_of_first_between(t_stack *stack, int min, int max);

#endif
