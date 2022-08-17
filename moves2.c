/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:05:23 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/17 14:52:58 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief  Shift up all elements of stack a by 1. 
 * The first element becomes the last one.
 * @param a 
 */

void	ra(t_node **a)
{
	(*a) = (*a)->next;
	write(1, "ra\n", 3);
}

/**
 * @brief Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 * @param b 
 */

void	rb(t_node **b)
{
	(*b) = (*b)->next;
	write(1, "rb\n", 3);
}

/**
 * @brief ra and rb at the same time.
 * 
 * @param a 
 * @param b 
 */

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

/**
 * @brief Shift down all elements of stack a by 1.
 * The last element becomes the first one
 * 
 * @param a 
 */

void	rra(t_node **a)
{
	(*a) = (*a)->prev;
	write(1, "rra\n", 4);
}

/**
 * @brief Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 * 
 * @param b 
 */

void	rrb(t_node **b)
{
	(*b) = (*b)->prev;
	write(1, "rrb\n", 4);
}
