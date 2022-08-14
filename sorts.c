/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:04:38 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/14 21:43:56 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Perform opertaion to sort two numbers.
 * 
 * @param a 
 */

void	sort_2_num(t_node **a)
{
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

/**
 * @brief Perform operation to sort three numbers.
 * 
 * @param a 
 */

void	sort_3_num(t_node **a)
{
	if ((*a)->data > (*a)->next->data)
	{
		if ((*a)->data < (*a)->prev->data && (*a)->next->data < (*a)->prev->data)
			sa(a);
		if ((*a)->data > (*a)->prev->data && (*a)->next->data > (*a)->prev->data)
		{
			sa(a);
			rra(a);
		}
		if ((*a)->data > (*a)->prev->data && (*a)->next->data < (*a)->prev->data)
			ra(a);
	}
	if ((*a)->data < (*a)->next->data)
	{
		if ((*a)-> data < (*a)->prev->data && (*a)->next->data > (*a)->prev->data)
		{
			sa(a);
			ra(a);
		}
		if ((*a)->data > (*a)->prev->data && (*a)->next->data > (*a)->prev->data)
			rra(a);
	}
}

// void	sort_4_num(t_node **a, t_node **b)
// {
	
// }