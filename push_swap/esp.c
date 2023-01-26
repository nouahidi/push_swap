/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:12:58 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/16 12:54:56 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_esp(char *str)
{
	int		i;
	int 	j;
	char	*st;

	i = 0;
	j = 0;
	st = malloc(25);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			st[j++] = ' ';
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while ((str[i] != ' ' && str[i] != '\t') && str[i])
			st[j++] = str[i++];
	}
	st[j] = '\0';
	return (st);
}
