/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:25:53 by user42            #+#    #+#             */
/*   Updated: 2021/04/29 14:56:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack;

	if (argc == 1)
		return (0);
	if ((stack = create_stack(argc, argv)) == NULL)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (1);
	}
	if (has_duplicate(stack))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_stackclear(&stack);
		return (1);
	}
	choose_best_sorter(&stack);
	ft_stackclear(&stack);
	return (0);
}
