/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 05:16:47 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/24 00:52:12 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <semaphore.h>
# include <sys/time.h>
# include <signal.h>
# include <pthread.h>
# include <limits.h>
# include "structs_bonus.h"

void		new_sleep(uint64_t time);
void		init_data(int c, char **str, t_data *data, t_philos *philos);
void		*monitor_bonus(void *philoss);
uint64_t	get_time_new(void);
int			algo(int c, char **str);
long		ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
bool		check_input(char **str);
t_philos	*c_philos(char **str);
t_philo		*c_philo(int val, t_data *data);
void		ft_free(t_philo *top);
void		routine(t_philo *philo);
void		add_back(t_philos *philos, t_philo *philo);
#endif