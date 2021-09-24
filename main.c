/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 12:20:22 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/21 13:31:42 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "pthread.h"

pthread_mutex_t	mutex;

void	ft_create_threads(int num_philo, pthread_t *philo)
{
	for (int i = 0; i < num_philo; i ++)
	{
		if (pthread_create(philo + i, NULL, &routine, (void *)&num))
			return (-1);
	}
}

void	*routine(void *num)
{
	int				*var;

	var = (int *)num;
	for (int i = 0; i < 100000; i++)
	{
		pthread_mutex_lock(&mutex);
		(*var)++;
		pthread_mutex_unlock(&mutex);
	}
	printf("Test from threads, var = %d\n", *var);
	sleep(2);
	printf("Ending thread %d, n = %d\n", getpid(), *var); 
	return (NULL);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;
	int			num;

	num = 0;
	//initialze the mutex
	pthread_mutex_init(&mutex, NULL);
	//initialize a thread:
	if (pthread_create(&t1, NULL, &routine, (void *)&num))
		return(-1);
	if (pthread_create(&t2, NULL, &routine, (void *)&num))
		return(-1);
	//wait for the thread to finish its execution!
	if (pthread_join(t1, NULL))
		return (-2);
	if (pthread_join(t2, NULL))
		return (-2);
	pthread_mutex_destroy(&mutex);
	printf("Ending process %d, n = %d\n", getpid(), num);
	return (0);
}