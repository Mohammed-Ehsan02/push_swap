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

/**
 * @brief Checks if only one sign apprears for a number. Either '+' || '-'
 * 
 * @param argv 
 * @return int 
 * Returns 1 if more than one sign or invalid input.
 * Returns 0 if valid input with only one sign.
 */

int	is_more_sign(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief To check if any alphabets are inputed.
 * 
 * @param argv 
 * @return int 
 * returns 1 if alphabets found oherwise 0.
 */

int	is_alpha(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isalpha(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief Checks if any duplicates present.
 * 
 * @param argv 
 * @return int 
 * returns 1 if duplicates found otherwise 0.
 */

int	is_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief Check for valid format and valid arguments.
 * 
 * @param argc 
 * @param argv 
 */

void	ft_error(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc >= 2)
	{
		if (argc > 2)
		{
			if (is_more_sign(argv) || is_alpha(argv) || is_duplicate(argv))
			{
				write (2, "Error\n", 6);
				exit(0);
			}
		}
		else if (argc == 2)
		{
			// fix here
			while(argv[1][i] == ' ')
			{
				i++;
				if (argv[1][i] == '\0')
				{
					write (2, "Error\n", 6);
					exit(0);
				}
			}// till here
			ft_error_continues(argv);
		}
	}
}
