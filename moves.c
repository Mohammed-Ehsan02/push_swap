/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 20:19:38 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/17 14:49:29 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swap the first 2 elements at the top of stack a.
 * 
 * @param a 
 */

void	sa(t_node **a)
{
	int	tmp;

	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
	write(1, "sa\n", 3);
}

/**
 * @brief  Swap the first 2 elements at the top of stack b.
 * 
 * @param b 
 */

void	sb(t_node **b)
{
	int	tmp;

	tmp = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = tmp;
	write(1, "sb\n", 3);
}

/**
 * @brief sa and sb at the same time.
 * 
 * @param a 
 * @param b 
 */

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

/**
 * @brief Take the first element at the top of b and put it at the top of a.
 * 
 * @param a 
 * @param b 
 */

void	pa(t_node **a, t_node **b)
{	
	int	tmp;

	if (!(*b))
		return ;
	tmp = (*b)->data;
	del_first_node(&(*b));
	if (!(*a))
		create_node(&(*a), tmp);
	else
		add_at_begin(&(*a), tmp);
	write(1, "pa\n", 3);
}

/**
 * @brief Take the first element at the top of a and put it at the top of b.
 * 
 * @param a 
 * @param b 
 */

void	pb(t_node **a, t_node **b)
{
	int	tmp;

	if (!(*a))
		return ;
	tmp = (*a)->data;
	del_first_node(&(*a));
	if (!(*b))
		create_node(&(*b), tmp);
	else
		add_at_begin(&(*b), tmp);
	write(1, "pb\n", 3);
}
