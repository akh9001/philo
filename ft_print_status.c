/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:58:01 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/27 19:18:29 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_philo_status(t_philo philo, int fork)
{
	unsigned long	time;

	pthread_mutex_lock(&(philo.data->print));
	ft_get_time_ms(&time, philo);
	if (fork)
		printf("* %lu : %d has taken a fork \n",time, philo.id);
	else if (philo.state == EAT)
		printf("* %lu : %d is eating %lu\n",time, philo.id, philo.last_eat);
	else if (philo.state == THINK)
		printf("* %lu : %d is thinking\n",time, philo.id);
	else if (philo.state == SLEEP)
		printf("* %lu : %d is sleeping\n",time, philo.id);
	else if (philo.state == DIE)
		printf("* %lu : %d died\n",time, philo.id);
	if (philo.state != DIE)
		pthread_mutex_unlock(&(philo.data->print));
}
