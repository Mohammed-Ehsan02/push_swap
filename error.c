/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:16:14 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/17 14:29:56 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Check if int is a digit.
 * 
 * @param c 
 * @return int 
 */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		i++;
		s++;
	}
	s -= i;
	return (i);
}

bool	arg_checker(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j] && argv[i][j] == ' ')
		{
			j++;
			if (argv[i][j] == '\0')
			{
				write(1, "Error\n", 6);
				return (false);
			}
		}
		i++;
	}
	return (true);
}

/**
 * @brief Check for valid format and valid arguments.
 * 
 * @param argc 
 * @param argv 
 */

void	ft_error(char *args)
{
	int	i;

	i = 0;
	while (args[i] == ' ')
	{
		i++;
		if (args[i] == '\0')
		{
			write (2, "Error\n", 6);
			free(args);
			exit(0);
		}
	}
	ft_error_continues(args);
}
