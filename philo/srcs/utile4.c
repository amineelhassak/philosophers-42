/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:32:22 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/24 23:13:05 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

uint64_t	get_time_new(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	new_sleep(uint64_t time)
{
	uint64_t	start;

	start = get_time_new();
	while (get_time_new() - start < time)
		usleep(50);
}

void	monitor(t_philos *philos)
{
	t_philo	*tmp;

	tmp = philos->top;
	while (1)
	{
		pthread_mutex_lock(&tmp->data->mutex);
		if ((int)((get_time_new() - tmp->data->time_start)
			- tmp->last_time_eat) >= (int)tmp->data->time_die)
		{
			tmp->data->is_died = 1;
			pthread_mutex_lock(&tmp->data->lock);
			printf("%llu %d die\n",
				(get_time_new() - tmp->data->time_start), tmp->id);
			return (free(philos->thread), free(philos));
		}
		if (tmp->data->count == philos->number_philos)
		{
			pthread_mutex_lock(&tmp->data->lock);
			return (free(philos->thread), free(philos));
		}
		pthread_mutex_unlock(&tmp->data->mutex);
		tmp = tmp->next;
	}
}

void	add_back(t_philos *philos, t_philo *philo)
{
	t_philo	*tmp;

	if (!philos)
		return ;
	if (!philos->top)
	{
		philos->top = philo;
		philos->bottom = philo;
		return ;
	}
	tmp = philos->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = philo;
	philos->bottom = philo;
	philos->bottom->next = 0;
}

void	ft_free(t_philo *top)
{
	t_philo	*tmp;
	int		i;

	tmp = top;
	i = -1;
	if (!top)
		return ;
	while (++i < top->data->number_philos)
	{
		tmp = top;
		top = top->next;
		free(tmp);
		tmp = NULL;
	}
}
