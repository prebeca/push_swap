/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:22:33 by user42            #+#    #+#             */
/*   Updated: 2021/04/29 18:43:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

bool	has_duplicate(t_list *stack)
{
	t_list	*curr;
	t_list	*end;
	int		curr_value;
	int		end_value;

	end = stack->next;
	while (end)
	{
		end_value = *(int*)(end->content);
		curr = stack;
		while (curr != end)
		{
			curr_value = *(int*)(curr->content);
			if (end_value == curr_value)
				return (true);
			curr = curr->next;
		}
		end = end->next;
	}
	return (false);
}

int		append_new_elem(t_list **stack, char *value)
{
	t_list	*new_elem;
	int		*new_value;

	if ((new_value = malloc(sizeof(int))) == 0)
		return (1);
	*new_value = ft_atoi(value);
	if ((new_elem = ft_lstnew(new_value)) == 0)
	{
		free(new_value);
		return (1);
	}
	ft_lstadd_front(stack, new_elem);
	return (0);
}

t_list	*create_stack(int argc, char **argv)
{
	t_list	*stack;

	stack = NULL;
	--argc;
	while (argc > 0)
	{
		if (!is_all_num(argv[argc]) || !is_int(argv[argc]))
		{
			ft_lstclear(&stack, &free);
			return (0);
		}
		if (append_new_elem(&stack, argv[argc]))
		{
			ft_lstclear(&stack, &free);
			return (0);
		}
		argc--;
	}
	return (stack);
}

bool	is_sorted(t_list *stack)
{
	int	curr_value;
	int	last_value;

	last_value = *(int*)(stack->content);
	stack = stack->next;
	while (stack)
	{
		curr_value = *(int*)(stack->content);
		if (curr_value < last_value)
			return (false);
		last_value = curr_value;
		stack = stack->next;
	}
	return (true);
}
