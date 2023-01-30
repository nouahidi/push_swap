/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:02:00 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/30 12:01:17 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	t = *lst;
	while (t->next != NULL)
		t = t->next;
	t->next = new;
}

t_list	*ft_lstnew(long long content)
{
	t_list	*t;

	t = malloc(sizeof(t_list));
	if (!t)
		return (NULL);
	t->content = content;
	t->next = NULL;
	return (t);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	t_list	*t;
	int		i;

	i = 0;
	t = lst;
	if (!t)
		return (0);
	while (t)
	{
		t = t->next;
		i++;
	}
	return (i);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*t;

	if (!lst)
		return ;
	while (*lst)
	{
		t = (*lst)->next;
		free(*lst);
		*lst = t;
	}
	*lst = NULL;
}
