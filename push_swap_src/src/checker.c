/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:22:33 by user42            #+#    #+#             */
/*   Updated: 2021/04/29 18:43:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_all_num(char *str)
{
	if (*str == '-')
		++str;
	while (*str && ft_isdigit(*str))
		++str;
	if (*str == 0)
		return (true);
	return (false);
}

bool	has_duplicate(t_stack *stack)
{
	t_stack *current;

	while (stack)
	{
		current = stack->next;
		while (current)
		{
			if (stack->value == current->value)
				return (true);
			current = current->next;
		}
		stack = stack->next;
	}
	return (false);
}

t_stack	*create_stack(int argc, char **argv)
{
	int		value;
	t_stack	*stack;
	t_stack	*new_elem;

	stack = NULL;
	--argc;
	while (argc > 0)
	{
		if (!is_all_num(argv[argc]) || !is_int(argv[argc]))
		{
			ft_stackclear(&stack);
			return (0);
		}
		value = ft_atoi(argv[argc]);
		if ((new_elem = ft_stacknew(value)) == 0)
		{
			ft_stackclear(&stack);
			return (0);
		}
		ft_stackadd_front(&stack, new_elem);
		argc--;
	}
	return (stack);
}

bool	is_sorted_ascdt(t_stack *stack)
{
	int	curr_value;
	int	last_value;

	last_value = stack->value;
	stack = stack->next;
	while (stack)
	{
		curr_value = stack->value;
		if (curr_value < last_value)
			return (false);
		last_value = curr_value;
		stack = stack->next;
	}
	return (true);
}

bool	is_sorted_dscdt(t_stack *stack)
{
	int	curr_value;
	int	last_value;

	last_value = stack->value;
	stack = stack->next;
	while (stack)
	{
		curr_value = stack->value;
		if (curr_value > last_value)
			return (false);
		last_value = curr_value;
		stack = stack->next;
	}
	return (true);
}
