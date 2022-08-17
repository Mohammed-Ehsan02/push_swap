/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fns2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:14:06 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/17 14:28:45 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Get the min value from the list.
 * 
 * @param n 
 * @return int - min value.
 */

int	get_min(t_node *n)
{
	t_node	*tmp;
	int		size;
	int		min;
	int		i;

	i = 0;
	min = n->data;
	size = lst_size(n);
	tmp = n;
	while (i < size)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (min);
}

/**
 * @brief Get the max value from the list.
 * 
 * @param n 
 * @return int - max value.
 */

int	get_max(t_node *n)
{
	t_node	*tmp;
	int		size;
	int		max;
	int		i;

	i = 0;
	max = n->data;
	size = lst_size(n);
	tmp = n;
	while (i < size)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (max);
}

/**
 * @brief Get the position of the data in the list.
 * 
 * @param n 
 * @param data 
 * @return int - position of the node holding the data.
 */

int	get_pos(t_node *n, int data)
{
	t_node	*tmp;
	int		pos;
	int		i;
	int		size;

	size = lst_size(n);
	tmp = n;
	pos = 1;
	i = 0;
	while (i < size)
	{
		if (tmp->data == data)
			break ;
		tmp = tmp->next;
		pos++;
		i++;
	}
	return (pos);
}

/**
 * @brief check if the list is sorted
 * 
 * @param node 
 * @return int 
 */

int	is_sorted(t_node *node)
{
	int		i;
	int		size;
	t_node	*tmp;

	tmp = node;
	size = lst_size(node);
	i = 0;
	while (i < lst_size(node))
	{
		if (tmp->data > tmp->next->data)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i + 1 < lst_size(node))
		return (0);
	else
		return (1);
	return (0);
}

/**
 * @brief freeing the list.
 * 
 * @param a 
 */

void	ft_free(t_node **a)
{
	int		size;
	t_node	*tmp;
	t_node	*tmp1;

	tmp = (*a);
	tmp1 = tmp;
	size = lst_size(*a);
	while (size)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		free(tmp1);
		size--;
	}
}
