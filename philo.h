/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:06:41 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/27 18:43:19 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define DIE 0
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
	int					num_philos;
	unsigned long		now;
	unsigned long		time_die;
	unsigned long		time_eat;
	unsigned long		time_sleep;
	pthread_mutex_t		print;
	pthread_mutex_t		*forks;
}						t_data;

typedef struct s_philo
{
	int				id;
	int				state;
	int				eat_num;
	t_data			*data;
	pthread_t		philo;
	unsigned long	last_eat;
}					t_philo;

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
t_philo *ft_fill_struct(char **argv);

/*
**	Modified system function : usleep & gettimeofday
*/

void	ft_sleep(unsigned long time);
void	ft_print_philo_status(t_philo philo, int fork);
void	ft_get_time_ms(unsigned long *time, t_philo philo);

/*
** Mutex & threads functions
*/

void	*ft_pick_up_forks(void	*var);
int		ft_create_threads(t_philo *philo);
void	ft_initiaze_mutex(p_mutex_t *mutex, int num_philos, p_mutex_t *print);
#endif