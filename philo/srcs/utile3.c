/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:32:33 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/24 21:00:00 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	less_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_lock(&philo->data->lock);
	printf("%llu %d is sleeping\n",
		(get_time_new() - philo->data->time_start), philo->id);
	pthread_mutex_unlock(&philo->data->lock);
	new_sleep(philo->data->time_sleep);
	pthread_mutex_lock(&philo->data->lock);
	printf("%llu %d is thinking\n",
		get_time_new() - philo->data->time_start, philo->id);
	pthread_mutex_unlock(&philo->data->lock);
}

static int	cheack_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->data->is_died)
		return (0);
	pthread_mutex_unlock(&philo->data->mutex);
	pthread_mutex_lock(philo->fork_r);
	return (1);
}

static void	_eat_sleep(t_philo *philo)
{
	if (!cheack_eat(philo))
		return ;
	pthread_mutex_lock(&philo->data->lock);
	printf("%llu %d has taken a fork\n",
		(get_time_new() - philo->data->time_start), philo->id);
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_lock(philo->fork_l);
	pthread_mutex_lock(&philo->data->lock);
	printf("%llu %d has taken a fork\n",
		(get_time_new() - philo->data->time_start), philo->id);
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_lock(&philo->data->lock);
	printf("%llu %d is eating\n",
		(get_time_new() - philo->data->time_start), philo->id);
	pthread_mutex_unlock(&philo->data->lock);
	new_sleep(philo->data->time_eat);
	pthread_mutex_lock(&philo->data->mutex);
	philo->num_eat++;
	if (philo->num_eat == philo->data->time_m_eat)
		philo->data->count++;
	pthread_mutex_unlock(&philo->data->mutex);
	pthread_mutex_lock(&philo->data->mutex);
	philo->last_time_eat = get_time_new();
	pthread_mutex_unlock(&philo->data->mutex);
	less_fork(philo);
}

static void	*routaine(void *philo)
{
	if (((t_philo *)philo)->num_eat == ((t_philo *)philo)->data->time_m_eat)
		return (0);
	if (((t_philo *)philo)->id % 2 == 0)
		usleep(100);
	while (1)
	{
		_eat_sleep(philo);
		usleep(300);
	}
	return (0);
}

int	init_thread(t_philos *philos, t_data *data)
{
	t_philo	*tmp;
	int		i;

	i = -1;
	tmp = philos->top;
	data->time_start = get_time_new();
	while (++i < philos->number_philos)
	{
		if (pthread_create(&philos->thread[i], NULL, &routaine, tmp))
			return (0);
		if (pthread_detach(philos->thread[i]))
			return (0);
		tmp = tmp->next;
	}
	monitor(philos);
	return (1);
}
