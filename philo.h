/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:06:41 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/26 19:46:02 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define EAT 1
# define THINK 2
# define SLEEP 3
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "pthread.h"
# include "sys/time.h"

typedef pthread_mutex_t p_mutex_t;

typedef struct s_data
{
	int					max_eat;
	unsigned long		time_die;
	unsigned long		time_eat;
	unsigned long		time_sleep;
	int					num_philos;
	unsigned long		now;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
}						t_data;

typedef struct s_philo
{
	int			id;
	int			state;
	int			eat_num;
	int			last_eat;
	pthread_t	philo;
	t_data		*data;
}				t_philo;

/*
**	help functions
*/

void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);

/*
**
*/

void	ft_sleep(unsigned long time);
#endif