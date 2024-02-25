/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:47:16 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/24 03:22:46 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_data
{
	uint64_t			time_die;
	uint64_t			time_eat;
	uint64_t			time_sleep;
	long long			time_m_eat;
	uint64_t			time_start;
	long long			number_philos;
	pthread_mutex_t		mutex;
	pthread_mutex_t		lock;
	int					is_died;
	int					count;
}	t_data;

typedef struct s_philo
{
	uint64_t			last_time_eat;
	struct s_philo		*next;
	unsigned int		id;
	pthread_mutex_t		*fork_l;
	pthread_mutex_t		*fork_r;
	struct s_data		*data;
	int					num_eat;
}	t_philo;

typedef struct s_philos
{
	int					*is_died;
	pthread_t			*thread;
	pthread_mutex_t		*fork;
	t_philo				*top;
	t_philo				*bottom;
	long long			number_philos;
}	t_philos;
#endif