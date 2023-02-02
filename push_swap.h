/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:51:13 by nouahidi          #+#    #+#             */
/*   Updated: 2023/02/02 15:02:58 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				position;
	long long		content;
	struct s_list	*next;
}					t_list;

typedef struct s_var
{
	char			*ln;
	char			*str;
	int				i;
	long long		*l;
	long long		*le;
	char			*st;
	int				tmp;
	int				chunk_limit;
	int				k;
	int				cnt;
	int				len;
	int				h;
	int				j;
	t_list			*p;
	t_list			*pb;
	t_list			*tp;
	t_list			*max;
	t_list			*b_max;
	t_list			*st_a;
	t_list			*st_b;
}					t_var;

int				ft_atoi(const char *st);
t_list			*ft_lstnew(long long content);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			swap_a(t_var *v);
void			swap_b(t_var *v);
void			reverse_rotate_a(t_var *v);
void			reverse_rotate_b(t_var *v);
void			rotate_a(t_var *v);
void			ft_aatoi(char *st, t_var *v);
void			ft_aatoi_bon(char *st, t_var *v);
void			push_a(t_var *v);
void			push_b(t_var *v);
void			rotate_b(t_var *v);
int				ft_lstsize(t_list *lst);
void			push_swap(t_var *v);
int				ft_search(t_var	*v);
void			list_numbering(t_var *v, long long *l);
void			sort_3(t_var *v);
int				position_n(int pt, t_var	*v);
void			push_100_500(t_var *v, int w);
int				position_b(int pt, t_var	*v);
void			max_before_max(t_var *v);
void			ft_lstclear(t_list **lst);
int				check_nb(char *str);
char			*ft_strdup(const char *str);
char			*ft_strchr(const char *str, int s);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*get_next_line(int fd);
int				ft_strncmp(const char *str1, const char *str2);
void			swap_a_bon(t_var *v);
void			rotate_a_bon(t_var *v);
void			reverse_rotate_a_bon(t_var *v);
void			push_a_bon(t_var *v);
void			push_b_bon(t_var *v);
void			swap_b_bon(t_var *v);
void			reverse_rotate_b_bon(t_var *v);
void			rotate_b_bon(t_var *v);
long long		*tab_int(t_var *v, t_list *st);
int				read_inp(t_var	*v);

#endif