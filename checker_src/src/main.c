/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:51:25 by user42            #+#    #+#             */
/*   Updated: 2021/04/28 23:01:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_values(int argc, char **argv, t_list **stack)
{
	if ((*stack = create_stack(argc, argv)) == 0)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (1);
	}
	if (has_duplicate(*stack))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_lstclear(stack, &free);
		return (1);
	}
	return (0);
}

int	check_instructions(t_list **stack)
{
	t_list *instructions;

	instructions = NULL;
	if (read_intructions(&instructions) == 1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_lstclear(stack, &free);
		return (1);
	}
	if (apply_instructions(stack, instructions))
		ft_putendl_fd("KO", STDOUT_FILENO);
	else if (is_sorted(*stack))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	ft_lstclear(&instructions, &free);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list *stack;

	if (argc == 1)
		return (0);
	stack = NULL;
	if (check_values(argc, argv, &stack))
		return (1);
	if (check_instructions(&stack))
		return (1);
	ft_lstclear(&stack, &free);
	return (0);
}
