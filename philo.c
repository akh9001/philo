/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:46:21 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/28 19:36:17 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_pick_up_forks(void	*var)
{
	t_philo		*philo;
	int			first_fork;
	int			second_fork;

	philo = (t_philo *)var;
	if (philo->id % 2)
		usleep(500);
	while (1)
	{
		first_fork = philo->id - 1;
		second_fork = first_fork - 1;
		if (second_fork < 0)
			second_fork = philo->data->num_philos - 1;
		/*
		** Lock fork 1:
		*/
		pthread_mutex_lock(philo->data->forks + first_fork);
		ft_print_philo_status(*philo, 1, 0);
		/*
		** Lock fork 2;
		*/
		pthread_mutex_lock(philo->data->forks + second_fork);
		ft_print_philo_status(*philo, 1, 0);
		/*
		** Philo is eating
		*/
		philo->state = EAT;
		ft_get_time_ms(&philo->last_eat, *philo);
		ft_print_philo_status(*philo, 0, 0);
		ft_sleep(philo->data->time_eat);
		(philo->eat_num)++;
		/*
		** Unlock mutex
		*/
		pthread_mutex_unlock(philo->data->forks + first_fork);
		pthread_mutex_unlock(philo->data->forks + second_fork);
		/*
		** Philo is sleeping
		*/
		philo->state = SLEEP;
		ft_print_philo_status(*philo, 0, 0);
		ft_sleep(philo->data->time_sleep);
		/*
		** Philo is thinking
		*/
		philo->state = THINK;
		ft_print_philo_status(*philo, 0, 0);
	}
	return (NULL);
}

int	ft_supervisor(t_philo **philo)
{
	t_supervisor	x;

	x.n = philo[0][0].data->num_philos;
	x.max_eat = philo[0][0].data->max_eat;
	x.time_die = philo[0][0].data->time_die;
	while (1)
	{
		x.i = 0;
		x.score = 0;
		while (i < n)
		{
			if (x.max_eat != -181)
				if (philo[0][x.i].eat_num >= x.max_eat)
					x.score++;
			ft_get_time_ms(&x.now, philo[0][x.i]);
			if ((x.now - philo[0][x.i].last_eat) >= (x.time_die / 1000))
			{
				philo[0][x.i].state = DIE;
				ft_print_philo_status(philo[0][x.i], 0, 1);
				ft_free_philos(philo);
				return (10);
			}
			x.i++;
		}
		if (x.score == x.n)
		{
			ft_free_philos(philo);
			return (500);
		}
		usleep(100);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (!(argc == 5 || argc == 6))
	{
		ft_putendl_fd("Error : number of args is incorrect!", 2);
		return (-1);
	}
	philo = ft_fill_struct(argv + 1);
	ft_initiaze_mutex(philo->data->forks, philo->data->num_philos,
		&philo->data->print);
	ft_create_threads(philo);
	return (ft_supervisor(&philo));
}
