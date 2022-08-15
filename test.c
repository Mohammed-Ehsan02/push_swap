/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:15:57 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/15 16:41:47 by mkhan            ###   ########.fr       */
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

void	print_list(t_node *a, t_node *tmpa, int len)
{
	while (len)
	{
		printf("%d  ->  %d\n", a->data, tmpa->data);
		a = a->next;
		tmpa = tmpa->next;
		len--;
	}
}

/**
 * @brief checks len of the stack and calls
 * 			 according sort funcions. --under progress--
 * @param a 
 * @param b 
 * @param tmpa 
 */
void	sort_list(t_node **a, t_node **b, t_node **tmpa)
{
	int len;
	(void)b;
	len = lst_size(*a);
	create_alias(a, tmpa);
	print_list(*a, *tmpa, len);
	// sort_3_num(a);
	// int  i = get_max(*a);
	// int j = get_min(*a);
	// int k = get_pos(*a, 12);
	// printf("max = %d\n min = %d\n pos = %d\n", i, j, k);
	// print_list(*a, *tmpa, len);
	// sa(a);
	// sb(tmpa);
	// ss(a, tmpa);
	// del_first_node(a);
	// del_first_node(tmpa);
	// pb(a, tmpa);
	// ra(a);
	// rb(tmpa);
	// rr(a, tmpa);
	// rra(a);
	// rrb(tmpa);
	// rrr(a, tmpa);
	// sort_4_num(a, b);
	// sort_3_num(a);
	sort_more(a, b);
	print_list(*a, *tmpa, len);
}

/**
 * @brief check if the list is sorted
 * 
 * @param node 
 * @return int 
 */
int	is_sorted(t_node *node)
{
	int	i;
	int size;
	t_node	*tmp;
	
	tmp = node;
	size = lst_size(node);
	i = 0;
	while (i < lst_size(node))
	{
		if (tmp->data > tmp->next->data)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i + 1 < lst_size(node))
		return (0);
	else
		return (1);
	return (0);
}

/**
 * @brief initial start of sort call function.
 * split into two parts -- norminette.
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
		return(0);
	}
	sort_list(a, b, tmpa);
	ft_free(a);
	ft_free(tmpa);
	return (1);
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
