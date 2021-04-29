/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:25:10 by user42            #+#    #+#             */
/*   Updated: 2021/04/28 22:44:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_list **src, t_list **dst)
{
	t_list *item;

	if (src == NULL || dst == NULL || *src == NULL)
		return ;
	item = *src;
	*src = item->next;
	item->next = NULL;
	ft_lstadd_front(dst, item);
}

void	swap(t_list **stack)
{
	t_list *item;

	if (stack == NULL || *stack == NULL)
		return ;
	item = (*stack)->next;
	if (item == NULL)
		return ;
	(*stack)->next = item->next;
	ft_lstadd_front(stack, item);
}

void	rotate(t_list **stack)
{
	t_list *item;

	if (stack == NULL || *stack == NULL)
		return ;
	if (ft_lstsize(*stack) < 2)
		return ;
	item = *stack;
	*stack = item->next;
	item->next = NULL;
	ft_lstadd_back(stack, item);
}

void	reverse_rotate(t_list **stack)
{
	t_list *item;
	t_list *last;

	if (stack == NULL || *stack == NULL)
		return ;
	if (ft_lstsize(*stack) < 2)
		return ;
	item = ft_lstatindex(*stack, -2);
	last = item->next;
	item->next = NULL;
	last->next = NULL;
	ft_lstadd_front(stack, last);
}

t_list	*ft_lstatindex(t_list *stack, int index)
{
	int max_index;

	if (stack == NULL)
		return (NULL);
	max_index = ft_lstsize(stack) - 1;
	if (index < 0)
		index = max_index + index + 1;
	if (index < 0)
		return (stack);
	if (index > max_index)
		return (ft_lstlast(stack));
	while (index)
	{
		stack = stack->next;
		--index;
	}
	return (stack);
}
