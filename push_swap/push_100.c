/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:32:18 by nouahidi          #+#    #+#             */
/*   Updated: 2023/01/26 16:05:09 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_100(t_var	*v)
// {
// 	int		k;
// 	t_list	*t;
// 	int		p;
// 	int		x;
// 	int		tm;
// 	int		tmp;

// 	k = v->k / 5;
// 	tm = v->k;
// 	tmp = k;
// 	t = v->p;
// 	while (t)
// 	{
// 		v->k = ft_lstsize(v->p);
// 		x = position_n(t->position, v);
// 		if (t->position < k)
// 		{
// 			p = t->position;
// 			if (x <= v->k / 2)
// 			{
// 				while (1)
// 				{
// 					if (v->p->position == p)
// 					{
// 						if (p > k - (tmp / 2) && ft_lstsize(v->pb) > 1)
// 						{
// 							push_b(v);
// 							rotate_b(v);
// 						}
// 						else
// 							push_b(v);
// 						break ;
// 					}
// 					rotate_a(v);
// 				}
// 			}
// 			else
// 			{
// 				while (1)
// 				{
// 					if (v->p->position == p)
// 					{
// 						if (p > k - (tmp / 2) && ft_lstsize(v->pb) > 1)
// 						{
// 							push_b(v);
// 							rotate_b(v);
// 						}
// 						else
// 							push_b(v);
// 						break ;
// 					}
// 					reverse_rotate_a(v);
// 				}
// 			}
// 			if (!v->p)
// 				break ;
// 		}
// 		t = t->next;
// 		if (t->next == NULL && ft_lstsize(v->pb) < tm)
// 		{
// 			t = v->p;
// 			k = tmp + k;
// 		}
// 	}
// }

void	push_3(t_var *v)
{
	t_list	*t;
	t_list	*max;

	t = v->pb;
	while (t)
	{
		if (t->position == 3)
			max = t;
		t = t->next;
	}
	while (1)
	{
		if (v->pb->content == max->content)
		{
			push_a(v);
			break ;
		}
		rotate_b(v);
	}
	if (v->pb->position == 2)
	{
		push_a(v);
		push_a(v);
	}
	else
	{
		push_a(v);
		push_a(v);
		swap_a(v);
	}
}

void	push_top(long long top, t_var	*v, int i)
{	
	while (1)
	{
		if (top == v->pb->content)
		{
			push_a(v);
			return ;
		}
		if (i == 0)
			reverse_rotate_b(v);
		else if (i == 1)
			rotate_b(v);
	}
}

void	push_5(t_var *v)
{
	t_list	*pn;
	t_list	*pf;
	t_list	*t;

	if (v->pb->next == NULL)
	{
		push_a(v);
		return ;
	}
	t = v->pb;
	while (t)
	{
		if (t->position == ft_lstsize(v->pb))
			pn = t;
		t = t->next;
	}
	t = v->pb;
	while (t)
	{
		if (t->position == (ft_lstsize(v->pb) - 1))
			pf = t;
		t = t->next;
	}
	if (ft_lstsize(v->pb) == 3)
	{
		push_3(v);
		return ;
	}
	if (pn->position >= ft_lstsize(v->pb) / 2 && pf->position >= ft_lstsize(v->pb) / 2)
	{
		if (position_b(pn->position, v) > position_b(pf->position, v))
			push_top(pn->content, v, 0);
		else
		{
			push_top(pf->content, v, 0);
			push_top(pn->content, v, 0);
			swap_a(v);
		}
	}
	else if (pn->position <= ft_lstsize(v->pb) / 2 && pf->position <= ft_lstsize(v->pb) / 2)
	{
		if (position_b(pn->position, v) < position_b(pf->position, v))
		{
			push_top(pf->content, v, 1);
			push_top(pn->content, v, 1);
			swap_a(v);
		}
		else
			push_top(pn->content, v, 1);
	}
	else if (pn->position >= ft_lstsize(v->pb) / 2 && pf->position <= ft_lstsize(v->pb) / 2)
	{
			push_top(pf->content, v, 1);
		if (pn->position > ft_lstsize(v->pb) / 2)
			push_top(pn->content, v, 0);
		else
			push_top(pn->content, v, 1);
		swap_a(v);
	}
	else
		push_top(pn->content, v, 1);
	if (v->pb)
		push_5(v);
}

void	max_before_max(t_var *v)
{
	t_list	*t;
	t_list	*pn;
	t_list	*pf;

	while (1)
	{
		t = v->pb;
		pn = v->pb;
		if (ft_lstsize(v->p) > 1)
			if (v->p->position > v->p->next->position)
				swap_a(v);
		while (t)
		{
			if (t->position == ft_lstsize(v->pb))
				pn = t;
			t = t->next;
		}
		t = v->pb;
		while (t)
		{
			if (t->position == (pn->position - 1))
				pf = t;
			t = t->next;
		}
		// if (ft_lstsize(v->pb) == 10)
			// printf ("heeeeeere\n");
		if (pn->position == 5 || pf->position == 5)
		{
			push_5(v);
			return ;
		}
		if (position_b(pn->position, v) > ft_lstsize(v->pb) / 2 && position_b(pf->position, v) >= ft_lstsize(v->pb) / 2) //valide
		{
			// printf ("+----->1ere\n");
			// printf ("---------------------====>size is : %d\n", ft_lstsize(v->pb));
			if (position_b(pn->position, v) > position_b(pf->position, v))
				push_top(pn->content, v, 0);
			else
			{
				push_top(pf->content, v, 0);
				if (position_b(pn->position, v) > ft_lstsize(v->pb) / 2)
					push_top(pn->content, v, 0);
				else
					push_top(pn->content, v, 1);
				swap_a(v);
			}
			// printf ("+------>1ere\n");
		}
		else if (position_b(pn->position, v) <= ft_lstsize(v->pb) / 2 && position_b(pf->position, v) <= ft_lstsize(v->pb) / 2)//valide
		{
			// printf ("---->2eme\n");
			if (position_b(pn->position, v) > position_b(pf->position, v))
			{
				push_top(pf->content, v, 1);
				if(position_b(pn->position, v) <= ft_lstsize(v->pb) / 2)
					push_top(pn->content, v, 1);
				else
					push_top(pn->content, v, 0);
				swap_a(v);
			}
			else
				push_top(pn->content, v, 1);
			// printf ("---->2eme\n");
		}
		else if (position_b(pn->position, v) >= ft_lstsize(v->pb) / 2 && position_b(pf->position, v) <= ft_lstsize(v->pb) / 2)
		{
			// printf ("--->3eme\n");
			if (ft_lstsize(v->pb) - (ft_lstsize(v->pb) - position_b(pn->position, v)) > ft_lstsize(v->pb) - position_b(pf->position, v))
				push_top(pn->content, v, 0);
			else
			{
				push_top(pf->content, v, 1);
				if (position_b(pn->position, v) > ft_lstsize(v->pb) / 2)
					push_top(pn->content, v, 0);
				else
					push_top(pn->content, v, 1);
				swap_a(v);
			}
			// printf ("--->3eme\n");
		}
		else if (position_b(pf->position, v) >= ft_lstsize(v->pb) / 2 && position_b(pn->position, v) <= ft_lstsize(v->pb) / 2)
		{
			// printf ("+------------===>4eme\n");
			if (ft_lstsize(v->pb) - (ft_lstsize(v->pb) - position_b(pf->position, v)) > ft_lstsize(v->pb) - position_b(pn->position, v))
				push_top(pn->content, v, 1);
			else
			{
				push_top(pf->content, v, 0);
				if (position_b(pn->position, v) < ft_lstsize(v->pb) / 2)
					push_top(pn->content, v, 1);
				else
					push_top(pn->content, v, 0);
				swap_a(v);
			}
			// printf ("+------------===>4eme\n");
		}
		if (ft_lstsize(v->p) > 1)
			if (v->p->position > v->p->next->position)
				swap_a(v);
		if (!v->pb)
			break ;
	}
}

void	sort_list(t_var *v)
{
	// int	len;

	// len = ft_lstsize(v->pb);
	// while (ft_lstsize(v->pb))
	// {
	// 	push_a(v);
	// 	if (ft_lstsize(v->p) > 1)
	// 		if (v->p->content > v->p->next->content)
	// 			swap_a(v);
	// 	reverse_rotate_b(v);
	// 	push_a(v);
	// 	if (v->p->content > v->p->next->content)
	// 		swap_a(v);
	// 	cheack_sort(v);
	// }
	// t_list	*t;
	// int		x;
	// int		y;

	max_before_max(v);
}

void	push_elm(t_var *v,int ps, int i)
{
	while (1)
	{
		if (ps == v->p->position)
		{
			push_b(v);
			return ;
		}
		if (i == 1)
			rotate_a(v);
		else if (i == 0)
			reverse_rotate_a(v);
	}
}

void	push_100_500(t_var	*v, int	w)
{
	int		k;
	t_list	*t;
	// int		p;
	// int		x;
	int		tm;
	int		tmp;
	int		chunk_limit = 0;

	k = v->k / w;
	tm = v->k;
	tmp = k;
	t = v->p;
	// while (t)
	// {
	// 	v->k = ft_lstsize(v->p);
	// 	x = position_n(t->position, v);
	// 	if (t->position <= k)
	// 	{
	// 		chunk_limit++;
	// 		push_b(v);
	// 		p = t->position;
	// 		if (p > k - (tmp / 2) && ft_lstsize(v->pb) > 1)
	// 			rotate_b(v);
	// 		if (!v->p)
	// 			break ;
	// 	}
	// 	else
	// 		rotate_a(v);
	// 	t = v->p;
	// 	if (chunk_limit == k)
	// 		k += tmp;
	// }
	while (1)
	{
		while (t)
		{
			if (t->position <= k)
			{
				chunk_limit++;
				if (position_n(t->position, v) <= (ft_lstsize(v->p) / 2))
				{
					if (t->position >= k - (tmp / 2))
					{
						push_elm(v, t->position, 1);
						if (ft_lstsize(v->pb) > 1)
							rotate_b(v);
					}
				}
				else
					push_elm(v, t->position, 0);
			}
			t = t->next;
		}
		if (!v->p)
			break ;
		if (k + tmp > ft_lstsize(v->p))
		{
			tmp = ft_lstsize(v->p) - k;
			printf ("%d\n", ft_lstsize(v->p));
			k = ft_lstsize(v->p);
		}
		else
			k = k + tmp;
		t = v->p;
	}
	// sort_list(v);
	if (ft_lstsize(v->p) > 1)
			if (v->p->position > v->p->next->position)
				swap_a(v);
}


// void	push_500(t_var *v)
// {
// 	int		k;
// 	t_list	*t;
// 	int		p;
// 	int		x;
// 	int		tm;
// 	int		tmp;

// 	k = v->k / 10;
// 	tm = v->k;
// 	tmp = k;
// 	t = v->p;
// 	while (t)
// 	{
// 		v->k = ft_lstsize(v->p);
// 		x = position_n(t->position, v);
// 		if (t->position <= k)
// 		{
// 			p = t->position;
// 			if (x <= v->k / 2)
// 			{
// 				while (1)
// 				{
// 					if (v->p->position == p)
// 					{
// 						push_b(v);
// 						break ;
// 					}
// 					rotate_a(v);
// 				}
// 			}
// 			else
// 			{
// 				while (1)
// 				{
// 					if (v->p->position == p)
// 					{
// 						push_b(v);
// 						break ;
// 					}
// 					reverse_rotate_a(v);
// 				}
// 			}
// 			if (!v->p)
// 				break ;
// 		}
// 		t = t->next;
// 		if (t->next == NULL && ft_lstsize(v->pb) < tm)
// 		{
// 			t = v->p;
// 			k = tmp + k;
// 		}
// 	}
// }
