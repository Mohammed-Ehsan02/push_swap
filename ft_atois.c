/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atois.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:31:35 by mkhan             #+#    #+#             */
/*   Updated: 2022/08/12 10:30:51 by mkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi_continues(unsigned long result, int sign)
{
	if (result > 2147483647 && sign == 1)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (result > 2147483648 && sign == -1)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

int	ft_atoi(char *str)
{
	unsigned long	result;
	unsigned long	temp_result;
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
	ft_atoi_continues(result, sign);
	return (result * sign);
}

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

void	ft_atoil_continues(unsigned long result, int sign, char **tab)
{
	if (result > 2147483647 && sign == 1)
	{
		free_lst(tab);
		exit(0);
	}
	if (result > 2147483648 && sign == -1)
	{
		free_lst(tab);
		exit(0);
	}
}

int	ft_atoil(char **tab, char *str)
{
	unsigned long	result;
	unsigned long	temp_result;
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
	ft_atoil_continues(result, sign, tab);
	return (result * sign);
}