/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:48:56 by user42            #+#    #+#             */
/*   Updated: 2021/04/28 22:50:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	apply_rotate(t_list **stack, t_list **tmp_stack, char *instruction)
{
	if (ft_strlen(instruction) == 2)
	{
		if (ft_strcmp("ra", instruction) == 0)
			rotate(stack);
		else if (ft_strcmp("rb", instruction) == 0)
			rotate(tmp_stack);
		else
		{
			rotate(stack);
			rotate(tmp_stack);
		}
		return ;
	}
	if (ft_strcmp("rra", instruction) == 0)
		reverse_rotate(stack);
	else if (ft_strcmp("rrb", instruction) == 0)
		reverse_rotate(tmp_stack);
	else
	{
		reverse_rotate(stack);
		reverse_rotate(tmp_stack);
	}
}

void	apply_swap(t_list **stack, t_list **tmp_stack, char *instruction)
{
	if (ft_strcmp("sa", instruction) == 0)
		swap(stack);
	else if (ft_strcmp("sb", instruction) == 0)
		swap(tmp_stack);
	else
	{
		swap(stack);
		swap(tmp_stack);
	}
}

void	apply_push(t_list **stack, t_list **tmp_stack, char *instruction)
{
	if (ft_strcmp("pa", instruction) == 0)
		push(tmp_stack, stack);
	else
		push(stack, tmp_stack);
}

int		apply_instructions(t_list **stack, t_list *instructions)
{
	t_list	*tmp_stack;
	int		error;

	tmp_stack = NULL;
	while (instructions)
	{
		if (*(char*)(instructions->content) == 's')
			apply_swap(stack, &tmp_stack, instructions->content);
		else if (*(char*)(instructions->content) == 'p')
			apply_push(stack, &tmp_stack, instructions->content);
		else
			apply_rotate(stack, &tmp_stack, instructions->content);
		instructions = instructions->next;
	}
	error = ft_lstsize(tmp_stack);
	ft_lstclear(&tmp_stack, &free);
	return (error);
}
