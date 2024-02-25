/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:50:50 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/24 16:23:12 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include "structs.h"
# include <sys/time.h>
# include <limits.h>

void		add_back(t_philos *philos, t_philo *philo);
void		monitor(t_philos *philos);
void		ft_free(t_philo *top);
void		ft_putstr_fd(char *s, int fd);
long		ft_atoi(const char *str, int *x);
bool		check_input(char **str);
t_philos	*c_philos(char **str);
int			algo(int c, char **str);
t_philo		*c_philo(int val, t_data *data);
int			init_thread(t_philos *philos, t_data *data);
uint64_t	get_time_new(void);
void		new_sleep(uint64_t time);
#endif