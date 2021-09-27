/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:46:21 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/27 19:53:06 by akhalidy         ###   ########.fr       */
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
		usleep(200);	
	while (1)
	{
		first_fork = philo->id - 1;
		second_fork = first_fork - 1;
		if (second_fork < 0)
			second_fork = philo->data->num_philos - 1;
		//lock fork 1:
		pthread_mutex_lock(philo->data->forks + first_fork);
		ft_print_philo_status(*philo, 1);
		//lock fork 2;
		pthread_mutex_lock(philo->data->forks + second_fork);
		ft_print_philo_status(*philo, 1);
		philo->state = EAT;
		if (philo->id == 4)
			printf("1### %lu##\n",philo->last_eat);
		ft_get_time_ms(&philo->last_eat, *philo);
		ft_print_philo_status(*philo, 0);
		ft_sleep(philo->data->time_eat);
		(philo->eat_num)++;
		pthread_mutex_unlock(philo->data->forks + first_fork);
		pthread_mutex_unlock(philo->data->forks + second_fork);
		philo->state = SLEEP;
		ft_print_philo_status(*philo, 0);
		ft_sleep(philo->data->time_sleep);
		if (philo->id == 4)
			printf("### %lu##\n",philo->last_eat);
	}
	return (NULL);
}

int ft_supervisor(t_philo *philo)
{
	int				i;
	int				n;
	int				score;
	int				max_eat;
	unsigned long	time_die;
	unsigned long	now;

	n = philo->data->num_philos;
	max_eat = philo->data->max_eat;
	time_die = philo->data->time_die;
	while (1)
	{
		i = 0;
		score = 0;
		while (i++ < n)
		{
			ft_get_time_ms(&now, *philo);
			if (max_eat != -181)
				if (philo->eat_num >= max_eat)
					score++;
			// printf("philo %d now : %lu, laast eat: %lu %d\n", i, time_die, now - philo[i].last_eat, philo[i].eat_num);
			if ((now - philo[i].last_eat) >= (time_die / 1000))
			{
				philo[i].state = DIE;
				ft_print_philo_status(philo[i], 0);
				//You should free;
				return (10);
			}
		}
		if (score == n)
			return (100);
		usleep(100);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo *philo;

	if (!(argc == 5 || argc == 6))
	{
		ft_putendl_fd("Error : number of args is incorrect!", 2);
		return (-1);
	}
	philo = ft_fill_struct(argv + 1);
	ft_initiaze_mutex(philo->data->forks, philo->data->num_philos, &philo->data->print);
	ft_create_threads(philo);
	return (ft_supervisor(philo));
	// while (1)
	// 	usleep(5000);
	// pthread_exit(NULL);
	// return (0);
}
