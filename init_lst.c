/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:12:51 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/17 15:09:04 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief creating a list when data is n number of arguments.
 * 
 * @param node 
 * @param argv 
 */

void	ft_init_list(t_node **node, char **argv)
{
	int	i;

	i = 2;
	create_node(&(*node), ft_atoi(argv[1]));
	while (argv[i])
	{
		add_at_end(&(*node), ft_atoi(argv[i]));
		i++;
	}
}

/**
 * @brief Creating a list of data, when provided as one string in
 * 		  the arguments. 
 * @param a 
 * @param s 
 */

void	ft_init_s(t_node	**a, char *s)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	j = 1;
	arr = ft_split(s, ' ');
	create_node(&(*a), ft_atoil(arr, arr[0]));
	while (arr[j])
	{
		add_at_end(a, ft_atoil(arr, arr[j]));
		j++;
	}
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/**
 * @brief creating nodes for alias.
 * 
 * @param alias 
 * @param data 
 */

void	custom_alias(t_node **alias, int data)
{
	if (!(*alias))
		create_node(alias, data);
	else
		add_at_end(alias, data);
}

/**
 * @brief Create a alias object of a.
 * 
 * @param node 
 * @param alias 
 */

void	ft_init_alias(t_node **node, t_node **alias)
{
	int		i[5];
	t_node	*tmp;
	t_node	*tmp1;

	i[0] = 0;
	i[4] = lst_size(*node);
	tmp = (*node);
	while (i[0] < i[4])
	{
		i[3] = tmp->data;
		i[1] = 0;
		i[2] = 0;
		tmp1 = (*node);
		while (i[1] < i[4])
		{
			if (i[3] > tmp1->next->data)
				i[2]++;
			tmp1 = tmp1->next;
			i[1]++;
		}
		tmp1 = tmp1->next;
		custom_alias(alias, i[2]);
		tmp = tmp->next;
		i[0]++;
	}
}
