/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:12:58 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/29 23:53:25 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cheak_esp(char	*str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			break ;
		if (str[i + 1] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	check_nb(char *str)
{
	int	i;

	i = 0;
	if (cheak_esp(str) == 0)
		return (0);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (!str[i])
			break ;
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			if (str[i - 1] == '+' || str[i - 1] == '-')
				return (0);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] && str[i] != ' ' & str[i] != '\t')
			return (0);
	}
	return (1);
}
