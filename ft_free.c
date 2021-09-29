/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:26:41 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/29 17:41:41 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_free_philos(t_philo	**philos)
{
	free(philos[0]->data->forks);
	philos[0]->data->forks = NULL;
	free(philos[0]->data);
	philos[0]->data = NULL;
	free(philos[0]);
	philos[0] = NULL;
	return (NULL);
}
