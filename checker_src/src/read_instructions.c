/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:58:48 by user42            #+#    #+#             */
/*   Updated: 2021/04/28 22:50:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	is_valid_instruction(char *instruction)
{
	int	intruction_len;

	intruction_len = ft_strlen(instruction);
	if (intruction_len < 2 || intruction_len > 3)
		return (false);
	if (!ft_strcmp("sa", instruction) || !ft_strcmp("sb", instruction) ||
		!ft_strcmp("ss", instruction) || !ft_strcmp("pa", instruction) ||
		!ft_strcmp("pb", instruction) || !ft_strcmp("ra", instruction) ||
		!ft_strcmp("rb", instruction) || !ft_strcmp("rr", instruction) ||
		!ft_strcmp("rra", instruction) || !ft_strcmp("rrb", instruction) ||
		!ft_strcmp("rrr", instruction))
		return (true);
	return (false);
}

int		read_intructions(t_list **intructions)
{
	int		ret;
	char	*line;
	t_list	*new_instruction;

	line = NULL;
	ret = get_next_line(STDIN_FILENO, &line);
	while (ret != -1 && ret != 0)
	{
		if (is_valid_instruction(line) == false)
		{
			free(line);
			ft_lstclear(intructions, &free);
			return (1);
		}
		new_instruction = ft_lstnew(line);
		ft_lstadd_back(intructions, new_instruction);
		line = NULL;
		ret = get_next_line(STDIN_FILENO, &line);
	}
	free(line);
	return (0);
}
