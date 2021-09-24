/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:06:11 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/24 19:57:33 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_initiaze_mutex(pthread_mutex_t *mutex, int num_philos)
{
	int	i;

	i = 1;
	while (i <= num_philos)
	{
		pthread_mutex_init(mutex + i, NULL);
		i++;
	}
}

void	ft_fill_struct(char **argv, t_global *src)
{
	int	num;

	num = ft_atoi(*argv);
	src->num_philos = num;
	src->time_die = ft_atoi(*argv + 1);
	src->time_eat = ft_atoi(*argv + 2);
	src->time_sleep = ft_atoi(*argv + 3);
	if (*argv + 4)
		src->max_eat = ft_atoi(*argv + 4);
	src->fork_tab = (pthread_mutex_t *)malloc(num * sizeof(pthread_mutex_t));
}

int main(int argc, char **argv)
{
	t_global	src;
	if (!(argc == 5 || argc == 6))
	{
		ft_putendl_fd("Error : number of args is incorrect!", 2);
		return (-1);
	}
	ft_fill_struct(argv + 1, &src);
	ft_initiaze_mutex(src.fork_tab,);
	return (0);
}