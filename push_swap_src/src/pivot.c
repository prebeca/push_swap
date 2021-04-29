/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:11:32 by user42            #+#    #+#             */
/*   Updated: 2021/04/29 16:23:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_smallest_after(t_stack *start, t_stack *n_smallest)
{
	t_stack *smallest;

	smallest = NULL;
	if (start)
		smallest = start;
	while (start)
	{
		if (n_smallest && start->value < smallest->value &&
			start->value > n_smallest->value)
			smallest = start;
		else if (!n_smallest && start->value < smallest->value)
			smallest = start;
		start = start->next;
	}
	return (smallest);
}

t_stack	*find_n_smallest(t_stack *stack, int n)
{
	t_stack *n_smallest;
	t_stack *start;

	if (n <= 0)
		return (NULL);
	n_smallest = NULL;
	while (n > 0)
	{
		start = stack;
		if (n_smallest)
			while (start && start->value <= n_smallest->value)
				start = start->next;
		n_smallest = get_smallest_after(start, n_smallest);
		--n;
	}
	return (n_smallest);
}

t_stack	*get_biggest_after(t_stack *start, t_stack *n_biggest)
{
	t_stack *biggest;

	biggest = NULL;
	if (start)
		biggest = start;
	while (start)
	{
		if (n_biggest && start->value > biggest->value &&
			start->value < n_biggest->value)
			biggest = start;
		else if (!n_biggest && start->value > biggest->value)
			biggest = start;
		start = start->next;
	}
	return (biggest);
}

t_stack	*find_n_biggest(t_stack *stack, int n)
{
	t_stack *n_biggest;
	t_stack *start;

	if (n <= 0)
		return (NULL);
	n_biggest = NULL;
	while (n > 0)
	{
		start = stack;
		if (n_biggest)
			while (start && start->value >= n_biggest->value)
				start = start->next;
		n_biggest = get_biggest_after(start, n_biggest);
		--n;
	}
	return (n_biggest);
}
