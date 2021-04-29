/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:00:13 by user42            #+#    #+#             */
/*   Updated: 2021/04/29 19:16:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(char *num)
{
	int num_len;

	num_len = ft_strlen(num);
	if ((num[0] != '-' && num_len < 10) || (num[0] == '-' && num_len < 11))
		return (1);
	if ((num[0] != '-' && num_len > 10) || (num[0] == '-' && num_len > 11))
		return (0);
	if (num[0] == '-' && ft_strcmp(num, "-2147483648") > 0)
		return (0);
	if (num[0] != '-' && ft_strcmp(num, "2147483647") > 0)
		return (0);
	return (1);
}
