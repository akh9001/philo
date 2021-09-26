/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:06:11 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/26 10:45:31 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_fill_struct(char **argv, t_global *src)
{
	int	num;

	num = ft_atoi(*argv);
	src->num_philos = num;
	src->time_die = ft_atoi(*argv + 1) * 1000;
	src->time_eat = ft_atoi(*argv + 2) * 1000;
	src->time_sleep = ft_atoi(*argv + 3) * 1000;
	if (*argv + 4)
		src->max_eat = ft_atoi(*argv + 4);
	src->fork_tab = (p_mutex_t *)malloc(num * sizeof(p_mutex_t));
	src->philo_tab = (pthread_t *)malloc(num * sizeof(pthread_t));
	src->philo = (t_philo *)malloc(num * sizeof(t_philo));
}

void	ft_initiaze_mutex(p_mutex_t *mutex, int num_philos, p_mutex_t *print)
{
	int	i;

	i = 1;
	while (i <= num_philos)
	{
		pthread_mutex_init(mutex + i, NULL);
		i++;
	}
	pthread_mutex_init(print);
}

void	ft_print_philo_status(t_philo philo, int fork)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	if (fork)
		printf("* %lu : %d is \n",tv.tv_sec * 1000, philo.num);
	if (philo.state == EAT)
		printf("* %lu : %d is eating\n",tv.tv_sec * 1000, philo.num);
	else if (philo.state == THINK)
		printf("* %lu : %d is thinking\n",tv.tv_sec * 1000, philo.num);
	else if (philo.state == SLEEP)
		printf("* %lu : %d is sleeping\n",tv.tv_sec * 1000, philo.num);	
}

void	*ft_pick_up_forks(void	*var)
{
	t_global	*src;
	int			i;

	src = (t_global *)var;
	if ((src->philo[i].num % 2) && !src->philo[i].eat_num)
	{
		//Here you should print that the philo X is thinking!
		src->philo[i].state = THINK;
		// pthread_mutex_lock(&(src->print));
		ft_print_philo_status(src->philo[i], 0);
		// pthread_mutex_unlock(&(src->print));
		usleep(500);
	}
	pthread_mutex_lock(src->fork_tab + src->philo[i].num - 1);
	pthread_mutex_lock(src->fork_tab + src->philo[i].num);
	src->philo[i].state = EAT;
	ft_print_philo_status(src->philo[i], 1);
	usleep(src->time_eat);
	(src->philo[i].eat_num)++;
	pthread_mutex_unlock(src->fork_tab + src->philo[i].num - 1);
	pthread_mutex_unlock(src->fork_tab + src->philo[i].num);
	src->philo[i].state = SLEEP;
	ft_print_philo_status(src->philo[i], 1);
	usleep(src->time_sleep);
}

void	ft_create_threads(t_global	*src)
{
	int			i;
	pthread_t	*t;

	i = 0;
	while (i < src->num_philos)
	{
		t = (src->philo_tab) + i;
		src->philo[i].num = i + 1;
		src->philo[i].philo = t;
		src->philo[i].eat_num = 0;
		src->philo[i].state = THINK;
		src->philo[i].time_last_eat = 0;
		if (pthread_create(t, NULL, &ft_pick_up_forks, (void *)src))
			return (-1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_global	src;

	if (!(argc == 5 || argc == 6))
	{
		ft_putendl_fd("Error : number of args is incorrect!", 2);
		return (-1);
	}
	ft_fill_struct(argv + 1, &src);
	ft_initiaze_mutex(src.fork_tab, src.num_philos, &src.print);
	ft_create_threads(&src);
	return (0);
}
