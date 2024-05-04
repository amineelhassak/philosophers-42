/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:09:07 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/24 21:06:22 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	proc_eat(t_philo *philo)
{
	if (philo->is_die == 0)
	{
		sem_wait(philo->data->sem);
		sem_wait(philo->data->s);
		printf("%llu %d has taken a fork\n",
			get_time_new() - philo->data->time_start, philo->id);
		sem_post(philo->data->s);
		sem_wait(philo->data->sem);
		sem_wait(philo->data->s);
		printf("%llu %d has taken a fork\n",
			get_time_new() - philo->data->time_start, philo->id);
		printf("%llu %d is eating\n",
			get_time_new() - philo->data->time_start, philo->id);
		sem_post(philo->data->s);
		new_sleep(philo->data->time_eat);
		philo->last_time_eat = get_time_new();
		sem_post(philo->data->sem);
		sem_post(philo->data->sem);
		philo->count_eat++;
	}
	if (philo->is_die == 0 && philo->count_eat == philo->data->time_m_eat)
	{
		philo->is_die = 1;
		sem_post(philo->data->semaphore);
	}
}

static void	proc_sleep(t_philo *philo)
{
	if (philo->is_die == 0)
	{
		sem_wait(philo->data->s);
		printf("%llu %d is sleeping\n",
			get_time_new() - philo->data->time_start, philo->id);
		sem_post(philo->data->s);
		new_sleep(philo->data->time_sleep);
	}
}

static void	proc_think(t_philo *philo)
{
	if (philo->is_die == 0)
	{
		sem_wait(philo->data->s);
		printf("%llu %d is thinking\n",
			get_time_new() - philo->data->time_start, philo->id);
		sem_post(philo->data->s);
	}
}

void	routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(150);
	pthread_create(&philo->thread, NULL, monitor_bonus, philo);
	pthread_detach(philo->thread);
	while (1)
	{
		proc_eat(philo);
		proc_sleep(philo);
		proc_think(philo);
	}
}

void	init_data(int c, char **str, t_data *data, t_philos *philos)
{
	data->time_die = ft_atoi(str[1]);
	data->time_eat = ft_atoi(str[2]);
	data->time_sleep = ft_atoi(str[3]);
	if (c == 6)
	{
		data->time_m_eat = ft_atoi(str[4]);
		if (data->time_m_eat == 0)
			exit(0);
	}
	else
		data->time_m_eat = -1;
	data->number_philos = ft_atoi(str[0]);
	data->time_start = get_time_new();
	data->philos = philos;
	data->count = 0;
}
