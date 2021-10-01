/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:43:26 by akhalidy          #+#    #+#             */
/*   Updated: 2021/10/01 16:24:04 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_philo *philo)
{
	int			first_fork;
	int			second_fork;

	first_fork = philo->id - 1;
	second_fork = first_fork - 1;
	if (second_fork < 0)
		second_fork = philo->data->num_philos - 1;
	pthread_mutex_lock(philo->data->forks + first_fork);
	ft_print_philo_status(*philo, 1, 0);
	pthread_mutex_lock(philo->data->forks + second_fork);
	pthread_mutex_lock(&philo->is_eating);
	ft_print_philo_status(*philo, 1, 0);
	philo->state = EAT;
	ft_get_time_ms(&philo->last_eat, *philo);
	ft_print_philo_status(*philo, 0, 0);
	ft_sleep(philo->data->time_eat);
	(philo->eat_num)++;
	pthread_mutex_unlock(&philo->is_eating);
	pthread_mutex_unlock(philo->data->forks + first_fork);
	pthread_mutex_unlock(philo->data->forks + second_fork);
}

void	*ft_pick_up_forks(void	*var)
{
	t_philo		*philo;

	philo = (t_philo *)var;
	if (philo->id % 2)
		usleep(500);
	while (1)
	{
		ft_eating(philo);
		philo->state = SLEEP;
		ft_print_philo_status(*philo, 0, 0);
		ft_sleep(philo->data->time_sleep);
		philo->state = THINK;
		ft_print_philo_status(*philo, 0, 0);
	}
	return (NULL);
}
