/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:15:57 by mkhan             #+#    #+#             */
/*   Updated: 2022/09/17 14:02:41 by mkhan            ###   ########.fr       */
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
		sort_large_chunk(tmpa, b);
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

char	*ft_strjoin(char *s1, char *s2, bool flag)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[i] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	if (flag)
		free (s1);
	return (str);
}

static void	push_swap(int argc, char *args)
{
	t_node	*a;
	t_node	*b;
	t_node	*tmpa;

	a = NULL;
	b = NULL;
	tmpa = NULL;
	if (argc >= 2)
	{
		ft_init_s(&a, args);
		free(args);
		start_sort(&a, &b, &tmpa);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*args;
	bool	flag;

	i = 1;
	args = "";
	flag = false;
	if (argc >= 2)
	{
		if (arg_checker(argv) == false)
			return (1);
		i = 1;
		while (argv[i])
		{
			args = ft_strjoin(args, " ", flag);
			flag = true;
			args = ft_strjoin(args, argv[i], flag);
			i++;
		}
		ft_error(args);
		push_swap(argc, args);
	}
	return (0);
}
