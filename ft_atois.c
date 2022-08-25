/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atois.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:31:35 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/25 19:50:40 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Extension of atoi, checks for overflow.
 * 
 * @param result 
 * @param sign 
 */

void	ft_atoi_overflow(size_t result, int sign)
{
	if (result > 1844674407370955169 && sign == 1)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (result > 1844674407370955169 && sign == -1)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

/**
 * @brief Convert the string input to integers when the input is n
 * number of arguments. 
 * 
 * @param str 
 * @return int 
 */

int	ft_atoi(char *str)
{
	size_t	result;
	size_t	temp_result;
	int				sign;
	int				i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp_result = result;
		result = result * 10 + str[i++] - '0';
		if (temp_result > result)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
	}
	ft_atoi_overflow(result, sign);
	return (result * sign);
}

/**
 * @brief Free the list.
 * 
 * @param tab 
 */

void	free_lst(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	write(2, "Error\n", 6);
}

/**
 * @brief Extended function atiol to check for overflows.
 * 
 * @param result 
 * @param sign 
 * @param tab 
 */

void	ft_atoil_overflow(size_t result, int sign, char **tab)
{
	if (result > 1844674407370955169 && sign == 1)
	{
		free_lst(tab);
		exit(0);
	}
	if (result > 1844674407370955169 && sign == -1)
	{
		free_lst(tab);
		exit(0);
	}
}

/**
 * @brief Convert the string input into integers.
 * Checks for 
 * 
 * @param tab 
 * @param str 
 * @return int 
 */

int	ft_atoil(char **tab, char *str)
{
	size_t	result;
	size_t	temp_result;
	int				sign;
	int				i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp_result = result;
		result = result * 10 + str[i++] - '0';
		if (temp_result > result)
		{
			free_lst(tab);
			exit(0);
		}
	}
	ft_atoil_overflow(result, sign, tab);
	return (result * sign);
}
