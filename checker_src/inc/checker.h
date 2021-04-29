/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:21:14 by user42            #+#    #+#             */
/*   Updated: 2021/04/29 19:08:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdbool.h>
# include "libft.h"

int		is_int(char *num);
bool	is_all_num(char *str);
t_list	*create_stack(int argc, char **argv);
void	print_stacks(t_list *stack_a, t_list *stack_b);
bool	has_duplicate(t_list *stack);
bool	is_sorted(t_list *stack);

void	push(t_list **src, t_list **dst);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

t_list	*ft_lstatindex(t_list *stack, int index);

int		read_intructions(t_list **intruction);
int		apply_instructions(t_list **stack, t_list *instructions);
#endif
