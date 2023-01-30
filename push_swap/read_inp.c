/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_inp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:18:41 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/30 22:35:01 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort_bon(t_var *v)
{
	long long	*l;
	int			i;

	l = tab_int(v, v->st_a);
	i = 0;
	while (i < ft_lstsize(v->st_a) - 1)
	{
		if (l[i] > l[i + 1])
			return (0);
		i++;
	}
	free(l);
	return (1);
}

void	read_norm(t_var	*v, char *str)
{
	if (ft_strncmp(str, "rrr\n", 3) == 0)
	{
		reverse_rotate_a_bon(v);
		reverse_rotate_b_bon(v);
	}
	else if (ft_strncmp(str, "rr\n", 3) == 0)
	{
		rotate_a_bon(v);
		rotate_b_bon(v);
	}
	else if (ft_strncmp(str, "ss\n", 3) == 0)
	{
		swap_a_bon(v);
		swap_b_bon(v);
	}
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		push_a_bon(v);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		push_b_bon(v);
	else
	{
		write (1, "error", 5);
		exit(0);
	}
}

int	read_inp(t_var	*v)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (ft_strncmp(str, "ra\n", 3) == 0)
			rotate_a_bon(v);
		else if (ft_strncmp(str, "sa\n", 3) == 0)
			swap_a_bon(v);
		else if (ft_strncmp(str, "rb\n", 3) == 0)
			rotate_b_bon(v);
		else if (ft_strncmp(str, "sb\n", 3) == 0)
			swap_b_bon(v);
		else if (ft_strncmp(str, "rra\n", 3) == 0)
			reverse_rotate_a_bon(v);
		else if (ft_strncmp(str, "rrb\n", 3) == 0)
			reverse_rotate_b_bon(v);
		else
			read_norm(v, str);
		str = get_next_line(0);
	}
	if (check_sort_bon(v) == 1 && !v->st_b)
		return (1);
	else
		return (0);
}