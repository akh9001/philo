/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:46:21 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/26 15:44:31 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *ft_fill_struct(char **argv)
{
	int				num;
    t_philo			*philo;
    t_data			*data;
	struct timeval	tv;

	num = ft_atoi(*argv);
    philo = (t_philo *)malloc(num * sizeof(t_philo));
    data = (t_data *)malloc(sizeof(t_data));
	data->num_philos = num;
	data->time_die = ft_atoi(*argv + 1) * 1000;
	data->time_eat = ft_atoi(*argv + 2) * 1000;
	data->time_sleep = ft_atoi(*argv + 3) * 1000;
	if (*argv + 4)
		data->max_eat = ft_atoi(*argv + 4);
	data->forks = (p_mutex_t *)malloc(num * sizeof(p_mutex_t));
	gettimeofday(&tv, NULL);
	data->now = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    while (num-- > 0)
        philo[num].data = data;
    return (philo);
}

void	ft_initiaze_mutex(p_mutex_t *mutex, int num_philos, p_mutex_t *print)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_init(mutex + i, NULL);
		i++;
	}
	pthread_mutex_init(print, NULL);
}

void	ft_print_philo_status(t_philo philo, int fork)
{
	struct timeval	tv;
	unsigned long	time;

	pthread_mutex_lock(&(philo.data->print));
	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000 - philo.data->now;
	if (fork)
		printf("* %lu : %d has taken a fork \n",time, philo.id);
	else if (philo.state == EAT)
		printf("* %lu : %d is eating\n",time, philo.id);
	else if (philo.state == THINK)
		printf("* %lu : %d is thinking\n",time, philo.id);
	else if (philo.state == SLEEP)
		printf("* %lu : %d is sleeping\n",time, philo.id);	
	pthread_mutex_unlock(&(philo.data->print));
}

void	*ft_pick_up_forks(void	*var)
{
	t_philo		*philo;
	int			first_fork;
	int			second_fork;

	philo = (t_philo *)var;
	// if ((src->philo[i].num % 2) && !src->philo[i].eat_num)
	// {
	// 	//Here you should print that the philo X is thinking!
	// 	src->philo[i].state = THINK;
	// 	// pthread_mutex_lock(&(src->print));
	// 	ft_print_philo_status(src->philo[i], 0);
	// 	// pthread_mutex_unlock(&(src->print));
	// 	usleep(500);
	// }
	if (philo->id % 2)
		usleep(200);	
	while (1)
	{
		first_fork = philo->id - 1;
		//second_fork = philo->data->num_philos - (-(first_fork - 1) % philo->data->num_philos);
		second_fork = first_fork - 1;
		if (second_fork < 0)
			second_fork = philo->data->num_philos - 1;
		//lock fork 1:
		pthread_mutex_lock(philo->data->forks + first_fork);
		//printf("0  from philo %d  fork n = %d %p\n",philo->id, first_fork, philo->data->forks + first_fork);
		ft_print_philo_status(*philo, 1);
		//lock fork 2;
		pthread_mutex_lock(philo->data->forks + second_fork);
		//printf("1  from philo %d  fork n = %d %p\n",philo->id, second_fork, philo->data->forks + second_fork);
		ft_print_philo_status(*philo, 1);
		philo->state = EAT;
		ft_print_philo_status(*philo, 0);
		usleep(philo->data->time_eat);
		//printf("jhdfjhdjhhjghggjhdgvhjgdfjggggdhjgvjg\n");
		(philo->eat_num)++;
		pthread_mutex_unlock(philo->data->forks + first_fork);
		pthread_mutex_unlock(philo->data->forks + second_fork);
		philo->state = SLEEP;
		ft_print_philo_status(*philo, 0);
		usleep(philo->data->time_sleep);
	}
	return (NULL);
}

int	ft_create_threads(t_philo *philo)
{
	int			i;
	int			n;
	pthread_t	*t;

	i = 0;
	n = philo->data->num_philos;
	while (i < n)
	{
		t = &philo[i].philo;
		philo[i].id = i + 1;
		philo[i].eat_num = 0;
		philo[i].state = THINK;
		philo[i].last_eat = 0;
		if (pthread_create(t, NULL, &ft_pick_up_forks, (void *)(philo + i)))
			return (-1);
		i++;
		// if (i % 2)
		// 	usleep(200);
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
	while (1);
	return (0);
}
