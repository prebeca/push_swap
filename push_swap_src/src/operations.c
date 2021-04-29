/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:25:10 by user42            #+#    #+#             */
/*   Updated: 2021/04/29 17:41:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dst, char *instruction)
{
	t_stack	*item;

	if (instruction)
		ft_putendl_fd(instruction, STDOUT_FILENO);
	if (*src == NULL)
		return ;
	item = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	item->next = NULL;
	ft_stackadd_front(dst, item);
}

void	swap(t_stack **stack, char *instruction)
{
	t_stack	*item;

	if (instruction)
		ft_putendl_fd(instruction, STDOUT_FILENO);
	if (*stack == NULL)
		return ;
	item = (*stack)->next;
	if (item == NULL)
		return ;
	if (item->next)
		item->next->previous = *stack;
	(*stack)->next = item->next;
	item->previous = (*stack)->previous;
	ft_stackadd_front(stack, item);
}

void	rotate(t_stack **stack, char *instruction)
{
	t_stack	*item;

	if (instruction)
		ft_putendl_fd(instruction, STDOUT_FILENO);
	if (stack == NULL || *stack == NULL)
		return ;
	if (ft_stacksize(*stack) < 2)
		return ;
	item = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = item->previous;
	item->next = NULL;
	ft_stackadd_back(stack, item);
}

void	reverse_rotate(t_stack **stack, char *instruction)
{
	t_stack	*last;

	if (instruction)
		ft_putendl_fd(instruction, STDOUT_FILENO);
	if (stack == NULL || *stack == NULL)
		return ;
	if (ft_stacksize(*stack) < 2)
		return ;
	last = ft_stacklast(*stack);
	if (last->previous)
		last->previous->next = NULL;
	last->previous = NULL;
	ft_stackadd_front(stack, last);
}

t_stack	*ft_stackatindex(t_stack *stack, int index)
{
	int	max_index;

	if (stack == NULL)
		return (NULL);
	max_index = ft_stacksize(stack) - 1;
	if (index < 0)
		index = max_index + index + 1;
	if (index < 0)
		return (stack);
	if (index > max_index)
		return (ft_stacklast(stack));
	while (index)
	{
		stack = stack->next;
		--index;
	}
	return (stack);
}
