/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:54:14 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/12 15:04:57 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node {
	struct s_node *next;
	struct s_node *prev;
	int 	data;
}	t_node;

char	**ft_split(char const *s, char c);
int		ft_atoi(char *str);
int		ft_atoil(char **tab, char *str);
void	init_list(t_node **node, char **argv);
void	create_node(t_node **head, int data);
void	add_at_begin(t_node	**tail, int data);
void	add_at_end(t_node **head, int data);
void	ft_init_s(t_node	**a, char *s);
int		lst_size(t_node	*n);
void	ft_free(t_node **a);
void	create_alias(t_node **node, t_node **alias);
int		start_sort(t_node **a, t_node **b, t_node **tmpa);

#endif