/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:04:38 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/14 19:46:33 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_num(t_node **a)
{
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

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
