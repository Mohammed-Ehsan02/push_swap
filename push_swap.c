/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:15:57 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/26 11:43:50 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Function to print the list and visualize the stacks.
 * Not used anywhere, ONLY FOR TESTING PURPOSE.
 * 
 * @param a 
 * @param tmpa 
 * @param len 
 */

// void	print_list(t_node *a, t_node *tmpa, int len)
// {
// 	while (len)
// 	{
// 		printf("%d  ->  %d\n", a->data, tmpa->data);
// 		a = a->next;
// 		tmpa = tmpa->next;
// 		len--;
// 	}
// }

/**
 * @brief checks len of the stack and calls
 * 			 according sort funcions.
 * @param a 
 * @param b 
 * @param tmpa 
 */

void	sort_list(t_node **a, t_node **b, t_node **tmpa)
{
	int	len;

	(void)b;
	len = lst_size(*a);
	ft_init_alias(a, tmpa);
	if (len <= 34)
		sort_small_chunk(tmpa, b, len);
	if (len > 35 && len <= 134)
		sort_medium_chunk(tmpa, b);
	if (len >= 135 && len <= 500)
		sort_large_chunk(tmpa, b);
	if (len >= 501)
		sort_more(tmpa, b);
}

/**
 * @brief initial start of sort call function.
 * 
 * @param a 
 * @param b 
 * @param tmpa 
 * @return int 
 */

int	start_sort(t_node **a, t_node **b, t_node **tmpa)
{
	if (is_sorted(*a))
	{
		ft_free(a);
		return (0);
	}
	sort_list(a, b, tmpa);
	ft_free(a);
	ft_free(tmpa);
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_node	*tmpa;

	a = NULL;
	b = NULL;
	tmpa = NULL;
	ft_error(argc, argv);
	if (argc >= 2)
	{
		if (argc == 2)
			ft_init_s(&a, argv[1]);
		else
			ft_init_list(&a, argv);
		start_sort(&a, &b, &tmpa);
	}
	return (0);
}
