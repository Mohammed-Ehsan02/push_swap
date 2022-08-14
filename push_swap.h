/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:54:14 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/14 21:40:48 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node {
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
}	t_node;

/* ---- Libft Functions ---- */
char	**ft_split(char const *s, char c);
int		ft_atoi(char *str);
int		ft_atoil(char **tab, char *str);

void	init_list(t_node **node, char **argv);
void	ft_init_s(t_node	**a, char *s);

/* ---- Basic list operations ---- */
void	create_node(t_node **head, int data);
void	del_first_node(t_node **n);
void	add_at_begin(t_node	**tail, int data);
void	add_at_end(t_node **head, int data);
int		lst_size(t_node	*n);
void	ft_free(t_node **a);

int	get_min(t_node *n);
int	get_max(t_node *n);
int	get_pos(t_node *n, int data);

void	create_alias(t_node **node, t_node **alias);
int		start_sort(t_node **a, t_node **b, t_node **tmpa);

/* ---- Stack moves ---- */
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/* ---- Sort functions ---- */
void	sort_2_num(t_node **a);
void	sort_3_num(t_node **a);
void	sort_4_num(t_node **a);

#endif