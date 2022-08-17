/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:54:14 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/17 15:09:42 by mkhan            ###   ########.fr       */
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
int		ft_isdigit(int c);
int		ft_isalpha(int c);

/* ---- Initalize the list and alias ---- */
void	ft_init_list(t_node **node, char **argv);
void	ft_init_s(t_node	**a, char *s);
void	ft_init_alias(t_node **node, t_node **alias);
void	custom_alias(t_node **alias, int data);

/* ---- Basic list operations ---- */
void	create_node(t_node **head, int data);
void	del_first_node(t_node **n);
void	add_at_begin(t_node	**tail, int data);
void	add_at_end(t_node **head, int data);
int		lst_size(t_node	*n);
void	ft_free(t_node **a);
void	print_list(t_node *a, t_node *tmpa, int len);

int		get_min(t_node *n);
int		get_max(t_node *n);
int		get_pos(t_node *n, int data);

/* ---- Sort functions ---- */
int		start_sort(t_node **a, t_node **b, t_node **tmpa);
int		is_sorted(t_node *node);
void	sort_2_num(t_node **a);
void	sort_3_num(t_node **a);
void	sort_3_num_cont(t_node **a);
void	sort_4_num(t_node **a, t_node **b);
void	sort_4_num_com_move(t_node **a, t_node **b);
void	sort_4_num_cont(t_node **a, t_node **b, int pos);
void	sort_more(t_node **a, t_node **b);

/* ---- Sort Chunk Functions ---- */
void	sort_small_chunk(t_node **a, t_node **b, int len);
void	sort_medium_chunk(t_node **a, t_node **b);
void	sort_the_push_chunk(t_node **a, t_node **b);
void	push_the_chunk(t_node **a, t_node **b, int min, int max);
void	sort_large_chunk(t_node **a, t_node **b);

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

/* ---- Error Handling ---- */
void	ft_error(int argc, char **argv);
int		is_more_sign(char **argv);
int		is_alpha(char **argv);
int		is_duplicate(char **argv);
void	ft_error_continues(char **argv);
int		is_more_sign_str(char **argv);
int		is_alpha_str(char **argv);
int		is_duplicate_str(char **argv);

#endif