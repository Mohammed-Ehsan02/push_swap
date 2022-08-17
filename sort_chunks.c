/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:11:25 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/17 14:02:32 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sort numbers from 0 to 34.
 * 
 * @param a 
 * @param b 
 * @param len 
 */

void	sort_small_chunk(t_node **a, t_node **b, int len)
{
	if (len == 2)
		sort_2_num(a);
	if (len == 3)
		sort_3_num(a);
	if (len == 4)
		sort_4_num(a, b);
	if (len >= 5 && len <= 34)
		sort_more(a, b);
}

/**
 * @brief Push the elements to chunk b.
 * 
 * @param a 
 * @param b 
 * @param min 
 * @param max 
 */

void	push_the_chunk(t_node **a, t_node **b, int min, int max)
{
	int	size;

	while (1)
	{
		if ((*a)->data >= min && (*a)->data <= max)
		{
			pb(a, b);
			if ((*b)->data <= (min + max) / 2)
				rb(b);
		}
		else
			ra(a);
		if (*b)
		{
			size = lst_size(*b);
			if (size == max + 1)
				break ;
		}
	}
}
/**
 * @brief Sort the pushed chunk.
 * 
 * @param a 
 * @param b 
 */

void	sort_the_push_chunk(t_node **a, t_node **b)
{
	int	size;
	int	max;
	int	pos;
	int	mid;

	while (1)
	{
		max = get_max(*b);
		pos = get_pos(*b, max);
		size = lst_size(*b);
		mid = size / 2;
		if ((*b)->data == max)
			pa(a, b);
		else if (pos <= mid)
			rb(b);
		else
			rrb(b);
		if (size == 2)
			break ;
	}
	if ((*b)->data < (*b)->next->data)
		sb(b);
	pa(a, b);
	pa(a, b);
}

/**
 * @brief Sort the medium size of chunk. From 35 to 134
 * 
 * @param a 
 * @param b 
 */

void	sort_medium_chunk(t_node **a, t_node **b)
{
	int	size;
	int	min;
	int	max;
	int	tmp;
	int	i;

	i = 0;
	size = lst_size(*a);
	min = size / 4;
	min--;
	max = min;
	while (max < size)
	{
		push_the_chunk(a, b, i, max);
		i = max + 1;
		tmp = max;
		max += min;
	}
	if (size - tmp == 4)
		sort_3_num(a);
	else
		sort_more(a, b);
	sort_the_push_chunk(a, b);
}

/**
 * @brief Sort the large chunk of numbers from 135 to 500.
 * 
 * @param a 
 * @param b 
 */

void	sort_large_chunk(t_node **a, t_node **b)
{
	int	size;
	int	min;
	int	max;
	int	i;

	i = 0;
	size = lst_size(*a);
	min = size / 10;
	min--;
	max = min;
	while (max < size - 9)
	{
		push_the_chunk(a, b, i - 1, max + 4);
		i = max + 2;
		max += min;
	}
	sort_more(a, b);
	sort_the_push_chunk(a, b);
}
