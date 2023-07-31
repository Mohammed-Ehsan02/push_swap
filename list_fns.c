/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:10:15 by mkhan             #+#    #+#             */
/*   Updated: 2023/07/31 14:07:02 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Create a node object.
 * 
 * @param head 
 * @param data 
 */

void	create_node(t_node **head, int data)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->prev = tmp;
	tmp->data = data;
	tmp->next = tmp;
	(*head) = tmp;
}

/**
 * @brief Delete the first node of the list.
 * 
 * @param n 
 */

void	del_first_node(t_node **n)
{
	t_node	*tmp;

	if ((*n) == NULL)
		return ;
	tmp = (*n);
	if (tmp == (*n)->next)
	{
		free((*n));
		(*n) = NULL;
		return ;
	}
	(*n)->next->prev = (*n)->prev;
	(*n)->prev->next = (*n)->next;
	(*n) = (*n)->next;
	free(tmp);
}

/**
 * @brief Adds a new node at the begining of the list.
 * 
 * @param tail 
 * @param data 
 */

void	add_at_begin(t_node	**tail, int data)
{
	t_node	*new;
	t_node	*tmp;

	create_node(&new, data);
	if (!(*tail))
		return ;
	tmp = (*tail)->prev;
	new->next = (*tail);
	new->prev = tmp;
	(*tail)->prev = new;
	tmp->next = new;
	(*tail) = new;
}

/**
 * @brief Adds a new node at the end of the list.
 * 
 * @param head 
 * @param data 
 */

void	add_at_end(t_node **head, int data)
{
	t_node	*new;
	t_node	*tmp;

	create_node(&new, data);
	if (!(*head))
		return ;
	tmp = (*head)->prev;
	tmp->next = new;
	new->prev = tmp;
	new->next = (*head);
	(*head)->prev = new;
}

/**
 * @brief calculating the size of list.
 * 
 * @param n 
 * @return int 
 */

int	lst_size(t_node	*n)
{
	int	size;
	int	data;

	size = 1;
	data = n->data;
	n = n->next;
	while (data != n->data)
	{
		size++;
		n = n->next;
	}
	return (size);
}
