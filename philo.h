/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:06:41 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/24 19:10:18 by akhalidy         ###   ########.fr       */
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

typedef struct s_philo
{
	int			num;
	int			state;
	pthread_t	*philo;
	int			eat_num;
	int			time_last_eat;
}				t_philo;

typedef struct s_global
{
	int					max_eat;
	int					time_die;
	int					time_eat;
	int					num_philos;
	int					time_sleep;
	pthread_t			*philo_tab;
	pthread_mutex_t		*fork_tab;
}						t_global;

/*
**	help functions
*/

void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
#endif