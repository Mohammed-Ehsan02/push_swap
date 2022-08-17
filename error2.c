/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:08:30 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/17 14:30:41 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Check if character is alphabet.
 * 
 * @param c 
 * @return int 
 */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/**
 * @brief Checks if only one sign apprears for a number. Either '+' || '-'.
 * This is to read thourgh the string if the input parameters are just two.
 * 
 * @param argv 
 * @return int 
 * Returns 1 if more than one sign or invalid input.
 * Returns 0 if valid input with only one sign.
 */
int	is_more_sign_str(char **argv)
{
	int	i;
	int	j;

	i = 0;
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
 * This is to read thourgh the string if the input parameters are just two.
 * 
 * @param argv 
 * @return int 
 * returns 1 if alphabets found oherwise 0.
 */

int	is_alpha_str(char **argv)
{
	int	i;
	int	j;

	i = 0;
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
 * This is to read thourgh the string if the input parameters are just two.
 * 
 * @param argv 
 * @return int 
 * returns 1 if duplicates found otherwise 0.
 */

int	is_duplicate_str(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoil(argv, argv[i]) == ft_atoil(argv, argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief Continuation of error detection.
 * This function focuses mainly on the string input.
 * 
 * @param argv 
 */

void	ft_error_continues(char **argv)
{
	int		i;
	char	**tab;

	i = 0;
	if (*argv[1] == 0)
		exit(0);
	tab = ft_split(argv[1], ' ');
	if (is_more_sign_str(tab) || is_alpha_str(tab) || is_duplicate_str(tab))
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		write (2, "Error\n", 6);
		exit(0);
	}
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
