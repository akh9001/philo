/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:28:15 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/17 18:41:18 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isinteger(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (!str[i + 1])
			return (1);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_int_range(char *str, int *number)
{
	long long	num;

	if (ft_isinteger(str))
		return (1);
	num = ft_atoi(str);
	if (num > 2147483647 || num < -2147483648 || (num == -1 && *str != '-'))
		return (1);
	*number = num;
	return (0);
}
