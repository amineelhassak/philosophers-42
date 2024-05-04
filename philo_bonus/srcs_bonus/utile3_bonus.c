/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:13:35 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/24 23:41:55 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ox_creaction_processus(t_philos *philos)
{
	int			i;
	t_philo		*tmp;

	tmp = philos->top;
	sem_wait(tmp->data->semaphore);
	tmp->data->count++;
	if (tmp->data->count == tmp->data->number_philos)
	{
		i = -1;
		while (++i < philos->number_philos)
		{
			kill(tmp->pid, 0);
			tmp = tmp->next;
		}
		exit(0);
	}
}

static void	creation_processus(t_philos *philos)
{
	int			i;
	t_philo		*tmp;

	(1 == 1) && (i = -1, tmp = philos->top);
	while (++i < philos->number_philos)
	{
		tmp->pid = fork();
		if (tmp->pid == -1)
			exit(EXIT_FAILURE);
		if (tmp->pid == 0)
			routine(tmp);
		tmp = tmp->next;
		usleep(100);
	}
	while (1)
		ox_creaction_processus(philos);
}

void	*monitor_bonus(void *philoo)
{
	t_philo	*philo;
	t_philo	*tmp;
	int		i;

	philo = (t_philo *)philoo;
	tmp = philo->data->philos->top;
	i = -1;
	while (1)
	{
		if ((int)((get_time_new() - philo->data->time_start)
			- philo->last_time_eat) > (int)philo->data->time_die)
		{
			sem_wait(philo->data->s);
			printf("%llu die %d\n", get_time_new()
				- philo->last_time_eat - philo->data->time_start, philo->id);
			while (++i < philo->data->number_philos)
			{
				kill(tmp->pid, SIGINT);
				tmp = tmp->next;
			}
			exit(0);
		}
	}
	return (0);
}

static int	init_semaphore(t_philos *philos, t_data *data)
{
	sem_unlink("/fork");
	sem_unlink("/check");
	sem_unlink("/write");
	data->sem = sem_open("/fork", O_CREAT, S_IRUSR | S_IWUSR,
			philos->number_philos);
	if (data->sem == SEM_FAILED)
		return (0);
	data->s = sem_open("/check", O_CREAT, S_IRUSR | S_IWUSR, 1);
	if (data->s == SEM_FAILED)
		return (0);
	data->semaphore = sem_open("/write", O_CREAT, S_IRUSR | S_IWUSR, 0);
	if (data->semaphore == SEM_FAILED)
		return (0);
	data->time_start = get_time_new();
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
	philos = c_philos(str);
	if (!philos)
		return (free(data), 0);
	init_data (c, str, data, philos);
	while (++i < philos->number_philos)
	{
		tmp = c_philo(i + 1, data);
		if (!tmp)
			return (ft_free(philos->top), free(philos), free(data), 0);
		add_back(philos, tmp);
	}
	philos->bottom->next = philos->top;
	if (!init_semaphore(philos, data))
		exit(EXIT_FAILURE);
	creation_processus(philos);
	return (1);
}
