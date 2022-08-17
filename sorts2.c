/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:02:41 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/17 15:07:06 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Avoiding repition of a common move done in this function.
 * 
 * @param a 
 * @param b 
 */

void	sort_4_num_com_move(t_node **a, t_node **b)
{
	pb(a, b);
	sort_3_num(a);
	pa(a, b);
}

/**
 * @brief Continuation of sort_4_num
 * 
 * @param a 
 * @param b 
 * @param pos 
 */

void	sort_4_num_cont(t_node **a, t_node **b, int pos)
{
	if (pos == 3)
	{
		rra(a);
		rra(a);
		sort_4_num_com_move(a, b);
	}
	if (pos == 4)
	{
		rra(a);
		if (is_sorted(*a))
			return ;
		sort_4_num_com_move(a, b);
	}
}
/**
 * @brief Perform operation to sort four numbers.
 * 
 * @param a 
 * @param b 
 */

void	sort_4_num(t_node **a, t_node **b)
{
	int	min;
	int	pos;

	min = get_min(*a);
	pos = get_pos(*a, min);
	if (pos == 1)
	{
		sort_4_num_com_move(a, b);
	}
	if (pos == 2)
	{
		sa(a);
		if (is_sorted(*a))
			return ;
		sort_4_num_com_move(a, b);
	}
	sort_4_num_cont(a, b, pos);
}

/**
 * @brief Continuation of sort_more.
 * 
 * @param a 
 * @param b 
 * @param i 
 */

void	sort_more_cont(t_node **a, t_node **b, int i)
{
	while (i)
	{
		pa(a, b);
		i--;
	}
}

/**
 * @brief Perform operation to sort more that 4 numbers.
 * 
 * @param a 
 * @param b 
 */

void	sort_more(t_node **a, t_node **b)
{	
	int	i[5];

	i[0] = 0;
	i[1] = lst_size(*a);
	i[3] = get_min(*a);
	i[4] = get_pos(*a, i[3]);
	while (1)
	{
		i[2] = lst_size(*a);
		if (i[2] == 4)
			break ;
		i[3] = get_min(*a);
		if ((*a)->data == i[3])
		{
			pb(a, b);
			i[0]++;
		}
		else if (i[4] < i[1] / 2)
			ra(a);
		else
			rra(a);
	}
	sort_4_num(a, b);
	sort_more_cont(a, b, i[0]);
}
