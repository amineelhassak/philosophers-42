/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:47:16 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/23 22:44:56 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H
//debug in
typedef struct s_data
{
	uint64_t			time_die;//
	uint64_t			time_eat;//
	uint64_t			time_sleep;//
	long long			time_m_eat;//
	int					number_philos;//nombres philos 
	sem_t				*sem;//semaphor
	uint64_t			time_start;
	sem_t				*s;
	struct s_philos		*philos;
	int					count;
	sem_t				*semaphore;
}	t_data;

typedef struct s_philo
{
	struct s_philo		*next;
	unsigned int		id;
	pid_t				pid;
	struct s_data		*data;
	sem_t				*fork;
	uint64_t			last_time_eat;
	int					count_eat;
	pthread_t			thread;
	int					is_die;
}	t_philo;

typedef struct s_philos
{
	pid_t				*fork;
	t_philo				*top;
	t_philo				*bottom;
	int					number_philos;
	sem_t				*s;
}	t_philos;
#endif