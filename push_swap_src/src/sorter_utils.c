/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:27:58 by user42            #+#    #+#             */
/*   Updated: 2021/05/04 17:33:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_index_of_first_between(t_stack *stack, int min, int max)
{
	t_stack	*downward;
	t_stack	*upward;
	int		pos;
	int		len;

	len = ft_stacksize(stack);
	downward = stack;
	upward = ft_stacklast(stack);
	pos = 0;
	while (pos < len / 2 + len % 2)
	{
		if (downward->value >= min && downward->value < max)
			return (pos);
		if (upward->value >= min && upward->value < max)
			return (len - pos - 1);
		downward = downward->next;
		upward = upward->previous;
		++pos;
	}
	return (-1);
}

void	get_it_to_the_top(t_stack **stack_a, int stack_len, int elem_pos)
{
	t_stack	*elem;

	elem = ft_stackatindex(*stack_a, elem_pos);
	if (elem_pos <= stack_len / 2)
		while ((*stack_a) != elem)
			rotate(stack_a, "ra");
	else
		while ((*stack_a) != elem)
			reverse_rotate(stack_a, "rra");
}

int		ft_stack_index_of(t_stack *stack, t_stack *elem)
{
	int i;

	i = 0;
	while (stack)
	{
		if (stack == elem)
			return (i);
		++i;
		stack = stack->next;
	}
	return (-1);
}
