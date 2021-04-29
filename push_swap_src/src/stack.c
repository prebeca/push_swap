/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:17:30 by user42            #+#    #+#             */
/*   Updated: 2021/04/29 14:05:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int value)
{
	t_stack *new;

	if ((new = malloc(sizeof(t_stack))) == 0)
		return (NULL);
	new->value = value;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

int		ft_stacksize(t_stack *stack)
{
	int		size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		stack = stack->next;
		++size;
	}
	return (size);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*cur_elem;

	if (!stack)
		return (0);
	cur_elem = stack;
	while (cur_elem->next)
		cur_elem = cur_elem->next;
	return (cur_elem);
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (*stack && new)
	{
		(*stack)->previous = new;
		new->next = *stack;
		*stack = new;
	}
	else
		*stack = new;
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack *last;

	if (*stack && new)
	{
		last = ft_stacklast(*stack);
		last->next = new;
		new->previous = last;
	}
	else
		*stack = new;
}
