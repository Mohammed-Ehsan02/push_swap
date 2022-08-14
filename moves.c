/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 20:19:38 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/14 18:53:46 by mkhan            ###   ########.fr       */
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
	int tmp;

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
	int tmp;

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
	del_first_node(&(*a));
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
	del_first_node(&(*b));
	if (!(*b))
		create_node(&(*b), tmp);
	else
		add_at_begin(&(*b), tmp);
	write(1, "pb\n", 3);
}

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

/**
 * @brief rra and rrb at the same time.
 * 
 * @param a 
 * @param b 
 */

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}