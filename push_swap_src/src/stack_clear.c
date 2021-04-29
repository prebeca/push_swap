/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:04:01 by user42            #+#    #+#             */
/*   Updated: 2021/04/29 17:14:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackdelone(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->previous)
		stack->previous->next = stack->next;
	if (stack->next)
		stack->next->previous = stack->previous;
	free(stack);
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*todel;

	if (!stack)
		return ;
	todel = *stack;
	while (todel)
	{
		*stack = (*stack)->next;
		ft_stackdelone(todel);
		todel = *stack;
	}
}
