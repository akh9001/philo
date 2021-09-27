/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time_ms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:28:21 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/27 19:41:31 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_get_time_ms(unsigned long *time, t_philo philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (philo.id == 4)
	printf("1 greap %lu\n", *time);
	*time = tv.tv_sec * 1000 + tv.tv_usec / 1000 - philo.data->now;
	if (philo.id == 4)
	printf("2 greap %lu\n", *time);
}
