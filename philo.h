/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:06:41 by akhalidy          #+#    #+#             */
/*   Updated: 2021/10/01 16:35:06 by akhalidy         ###   ########.fr       */
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

typedef pthread_mutex_t	t_mutex;

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
	pthread_mutex_t	is_eating;
	unsigned long	last_eat;
}					t_philo;

typedef struct s_supervisor
{
	int				i;
	int				n;
	int				score;
	int				max_eat;
	unsigned long	time_die;
	unsigned long	now;	
}				t_supervisor;

/*
**	help functions
*/

void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);

/*
**	fill structure & free it
*/
int		ft_check_args(char **argv, int argc);
int		ft_check_range_arg(t_data *data, char **args);
/*
**	fill structure & free it
*/
t_philo	*ft_fill_struct(char **argv);
void	*ft_free_philos(t_philo	**philos);

/*
**	Modified system function : usleep & gettimeofday
*/

void	ft_sleep(unsigned long time);
void	ft_get_time_ms(unsigned long *time, t_philo philo);
void	ft_print_philo_status(t_philo philo, int fork, int die);

/*
** Mutex & threads functions
*/

void	*ft_pick_up_forks(void	*var);
int		ft_create_threads(t_philo *philo);
void	ft_initiaze_mutex(t_data *data, t_philo *philo);
#endif