/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:11:05 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/26 19:52:25 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(unsigned long time)
{
	unsigned long	now;
	unsigned long	stop;
	struct timeval	tv;

	// printf("######################\n time %lu \n", time);
	gettimeofday(&tv, NULL);
	now = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	stop = time / 1000 + now;
	usleep(2 * (time / 3));
	while (now < stop)
	{
		gettimeofday(&tv, NULL);
		now = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	}
}
