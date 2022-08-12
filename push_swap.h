/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:54:14 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/11 17:16:24 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node {
	struct s_node *next;
	struct s_node *prev;
	int 	data;
}	t_node;

char	**ft_split(char const *s, char c);

#endif