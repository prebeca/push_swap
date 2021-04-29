/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:15:46 by user42            #+#    #+#             */
/*   Updated: 2021/04/29 16:12:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int a;
	int b;
	int c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && a < c && b < c)
		swap(stack, "sa");
	else if (a > b && a > c && b < c)
		rotate(stack, "ra");
	else if (a < b && a > c && b > c)
		reverse_rotate(stack, "rra");
	else
	{
		swap(stack, "sa");
		sort_three(stack);
	}
}

void	choose_best_sorter(t_stack **stack)
{
	int stack_len;

	stack_len = ft_stacksize(*stack);
	if (stack_len < 1)
		return ;
	if (is_sorted_ascdt(*stack))
		return ;
	if (stack_len == 2)
	{
		swap(stack, "sa");
		return ;
	}
	else if (stack_len == 3)
		sort_three(stack);
	else
		sorter(stack);
	return ;
}

void	biggest_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *biggest;
	int		stack_len;

	while (*stack_b)
	{
		stack_len = ft_stacksize(*stack_b);
		biggest = find_n_biggest(*stack_b, 1);
		if (ft_stack_index_of(*stack_b, biggest) <= stack_len / 2)
			while (*stack_b != biggest)
				rotate(stack_b, "rb");
		else
			while (*stack_b != biggest)
				reverse_rotate(stack_b, "rrb");
		push(stack_b, stack_a, "pa");
	}
}

int		find_pivot(t_stack **stack_a, int stack_len)
{
	int i;
	int pivot;

	i = 2;
	while (stack_len / i > 25)
		i++;
	pivot = find_n_smallest(*stack_a, stack_len / i)->value;
	return (pivot);
}

void	sorter(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		pivot;
	int		pos;
	int		len;
	int		last_pivot;

	stack_b = NULL;
	last_pivot = find_n_smallest(*stack_a, 1)->value;
	while (!is_sorted_ascdt(*stack_a))
	{
		len = ft_stacksize(*stack_a);
		pivot = find_pivot(stack_a, len);
		pos = get_index_of_first_between(*stack_a, last_pivot, pivot);
		while (pos != -1)
		{
			get_it_to_the_top(stack_a, len, pos);
			push(stack_a, &stack_b, "pb");
			if (ft_stacksize(*stack_a) <= 3)
				choose_best_sorter(stack_a);
			pos = get_index_of_first_between(*stack_a, last_pivot, pivot);
		}
		last_pivot = pivot;
	}
	biggest_b_to_a(stack_a, &stack_b);
}
