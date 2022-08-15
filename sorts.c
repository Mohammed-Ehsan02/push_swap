/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:04:38 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/15 14:40:21 by mkhan            ###   ########.fr       */
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
	printf("i am in sort 3\n");
	// printf("%d %d %d %d\n", lst_size(*a), (*a)->data, (*a)->next->data, (*a)->prev->data);
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
	printf("i am going out of sort 3\n");
}

void	sort_4_num(t_node **a, t_node **b)
{
	int	min;
	int	pos;

	min = get_min(*a);
	pos = get_pos(*a, min);
	if (pos == 1)
	{
		pb(a, b);
		sort_3_num(a);
		pa(a, b);
	}
	if (pos == 2)
	{
		sa(a);
		if (is_sorted(*a))
			return ;
		pb(a, b);
		sort_3_num(a);
		pa(a, b);
	}
	if (pos == 3)
	{
		rra(a);
		rra(a);
		pb(a, b);
		sort_3_num(a);
		pa(a, b);
	}
	if (pos == 4)
	{
		rra(a);
		if (is_sorted(*a))
			return ;
		pb(a, b);
		sort_3_num(a);
		pa(a, b);
	}
}
