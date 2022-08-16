/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:04:38 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/15 17:14:29 by mkhan            ###   ########.fr       */
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
	// printf("i am in sort 3\n");
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
	// printf("i am going out of sort 3\n");
}

/**
 * @brief Perform operation to sort four numbers.
 * 
 * @param a 
 * @param b 
 */

void	sort_4_num(t_node **a, t_node **b)
{
		// printf("i am in sort 4\n");
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
		// printf("i am out of sort 4\n");
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
	while (i[0])
	{
		pa(a, b);
		i[0]--;
	}
}
