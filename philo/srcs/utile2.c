/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:32:42 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/24 23:47:35 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init_data(int c, char **str, t_data *data)
{
	int	x;

	x = 0;
	data->time_die = ft_atoi(str[1], &x);
	data->time_eat = ft_atoi(str[2], &x);
	data->time_sleep = ft_atoi(str[3], &x);
	if (c == 6)
		data->time_m_eat = ft_atoi(str[4], &x);
	else
		data->time_m_eat = -1;
	data->time_start = get_time_new();
	data->number_philos = ft_atoi(str[0], &x);
	pthread_mutex_init(&data->mutex, NULL);
	pthread_mutex_init(&data->lock, NULL);
	data->is_died = 0;
	data->count = 0;
	if (x == 1)
		return (0);
	return (1);
}

static int	allocate(t_philos *philos)
{
	philos->fork = malloc(sizeof(pthread_mutex_t) * philos->number_philos);
	if (!philos->fork)
		return (0);
	philos->thread = malloc(sizeof(pthread_t) * philos->number_philos);
	if (!philos->thread)
		return (0);
	return (1);
}

static int	init_forks(t_philos *philos)
{
	int		i;
	t_philo	*tmp;

	i = -1;
	tmp = philos->top;
	while (++i < philos->number_philos)
	{
		if (pthread_mutex_init(&philos->fork[i], NULL))
			return (0);
	}
	i = 0;
	tmp->fork_r = &philos->fork[i];
	tmp->fork_l = &philos->fork[philos->number_philos - 1];
	tmp = tmp->next;
	i++;
	while (i < philos->number_philos)
	{
		tmp->fork_r = &philos->fork[i];
		tmp->fork_l = &philos->fork[i - 1];
		i++;
		tmp = tmp->next;
	}
	return (1);
}

static bool	oxe_fun(t_philos *philos, t_data *data)
{
	if (!allocate(philos))
		return (ft_free(philos->top), free(philos), free(data), 0);
	if (!init_forks(philos))
		return (free(philos->thread), free(philos->fork),
			ft_free(philos->top), free(philos), free(data), 0);
	if (!init_thread(philos, data))
		return (free(philos->thread), free(philos->fork),
			ft_free(philos->top), free(philos), free(data), 0);
	return (1);
}

int	algo(int c, char **str)
{
	t_philo		*tmp;
	t_data		*data;
	t_philos	*philos;
	int			i;

	i = -1;
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (!init_data (c, str, data))
		return (0);
	philos = c_philos(str);
	if (!philos)
		return (free(data), 0);
	while (++i < philos->number_philos)
	{
		tmp = c_philo(i + 1, data);
		if (!tmp)
			return (ft_free(philos->top), free(philos), free(data), 0);
		add_back(philos, tmp);
	}
	philos->bottom->next = philos->top;
	if (!oxe_fun(philos, data))
		return (0);
	return (1);
}
