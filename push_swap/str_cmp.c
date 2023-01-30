/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:55:39 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/30 14:57:53 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t		i;

	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if ((unsigned char)str1[i] < (unsigned char)str2[i])
			return (-1);
		if ((unsigned char)str1[i] > (unsigned char)str2[i])
			return (1);
		i++;
	}
	return (0);
}
