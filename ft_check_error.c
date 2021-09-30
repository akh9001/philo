/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:32:16 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/30 12:22:08 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_number(char *str)
{
	int	i;

	i = 1;
	if (!str)
		return (0);
	if ((!ft_is_digit(*str) && *str != '+') || (*str == '+' && !str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_args(char **argv, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_is_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_range_arg(t_data *data, char **args)
{
	if (data->num_philos <= 0)
		return (0);
	if (data->time_die <= 0 || data->time_eat <= 0 || data->time_sleep <= 0)
		return (0);
	if (args[4])
	{
		if (data->max_eat <= 0)
			return (0);
	}
	return (1);
}
