/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:15:57 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/12 15:14:04 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief creating a list when data is n number of arguments.
 * 
 * @param node 
 * @param argv 
 */
void	init_list(t_node **node, char **argv)
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
 * @brief Create a node object.
 * 
 * @param head 
 * @param data 
 */
void	create_node(t_node **head, int data)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->prev = tmp;
	tmp->data = data;
	tmp->next = tmp;
	(*head) = tmp;
}

/**
 * @brief Adds a new node at the begining of the list.
 * 
 * @param tail 
 * @param data 
 */
void	add_at_begin(t_node	**tail, int data)
{
	t_node	*new;
	t_node	*tmp;

	create_node(&new, data);
	if(!(*tail))
		return ;
	tmp = (*tail)->prev;
	new->next = (*tail);
	new->prev = tmp;
	(*tail)->prev = new;
	tmp->next = new;
	(*tail) = new;
	
}
/**
 * @brief Adds a new node at the end of the list.
 * 
 * @param head 
 * @param data 
 */
void	add_at_end(t_node **head, int data)
{
	t_node	*new;
	t_node	*tmp;
	
	create_node(&new, data);
	if(!(*head))
		return ;
	tmp = (*head)->prev;
	tmp->next = new;
	new->prev = tmp;
	new->next = (*head);
	(*head)->prev = new;
}

/**
 * @brief Creating a list of data, when provided as one string in
 * 		  the arguments. 
 * @param a 
 * @param s 
 */
void	ft_init_s(t_node	**a, char *s)
{
	int	i;
	int	j;
	char **arr;

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
 * @brief calculating the size of list.
 * 
 * @param n 
 * @return int 
 */
int	lst_size(t_node	*n)
{
	int	size;
	int	data;
	
	size = 1;
	data = n->data;
	n = n->next;
	while (data != n->data)
	{
		size++;
		n = n->next;
	}
	return (size);
}

/**
 * @brief freeing the list.
 * 
 * @param a 
 */
void	ft_free(t_node **a)
{
	int	size;
	t_node	*tmp;
	t_node	*tmp1;
	
	tmp = (*a);
	tmp1 = tmp;
	size = lst_size(*a);
	while (size)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		free(tmp1);
		size--;
	}
}

/**
 * @brief creating nodes for alias.
 * 
 * @param alias 
 * @param data 
 */
void	custom_create(t_node **alias, int data)
{
	if(!(*alias))
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
void	create_alias(t_node **node, t_node **alias)
{
	int	i[5];
	t_node *tmp;
	t_node *tmp1;
	
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
		custom_create(alias, i[2]);
		tmp = tmp->next;
		i[0]++;
	}
}

// void	sort_list(t_node **a, t_node **b, t_node **tmpa)
// {
// 	int len;
	
// 	len = lst_size(*a);
// 	create_alias(a, tmpa);
// }

int	start_sort(t_node **a, t_node **b, t_node **tmpa)
{
	if (is_sorted(*a))
	{
		ft_free(a);
		return(0);
	}
	// sort_list(a, b, tmpa);
}

int main (int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_node	*tmpa;
	
	a = NULL;
	b = NULL;
	tmpa = NULL;
	if (argc >= 2)
	{
		if (argc == 2)
		{
			ft_init_s(&a, argv[1]);
		}
		else
			ft_init_list(&a, argv);
		start_sort(&a, &b, &tmpa);
	}
	return (0);
}
