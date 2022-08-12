/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:15:57 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/12 09:51:46 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_node {
	struct s_node *next;
	struct s_node *prev;
	int 	data;
}	t_node;

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

int main (int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_node	*tempa;
	
	a = NULL;
	b = NULL;
	tempa == NULL;
	if (argc >= 2)
	{
		if (argc == 2)
		{
			ft_init_s(&a, argv[1]);
		}
		else
			ft_init_list(&a, argv);
	}
	return (0);
}
