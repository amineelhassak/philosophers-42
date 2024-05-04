/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 01:52:42 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/24 01:04:01 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

long	ft_atoi(const char *str)
{
	long	r;
	int		i;
	int		len;

	(1 == 1) && (i = 0, r = 0, len = 0);
	while (str[i] == '0')
		i++;
	while (str[i++])
		len++;
	if (len > 11)
		exit(write(2, "ERROR @\n", 7));
	i = 0;
	if (*(str + i) == '+')
		i++;
	while ((*(str + i) >= '0' && *(str + i) <= '9') && *(str + i))
	{
		r = r * 10 + str[i] - '0';
		if (r > INT_MAX)
			exit(write(2, "ERROR @\n", 7));
		i++;
	}
	return (r);
}

bool	check_input(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (!str[i][0])
			return (false);
		while (str[i][j])
		{
			if (str[i][j] == '+')
				j++;
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

t_philos	*c_philos(char **str)
{
	t_philos	*new_philos;

	new_philos = malloc(sizeof(t_philos));
	if (!new_philos)
		return (0);
	new_philos->number_philos = ft_atoi(str[0]);
	if (!new_philos->number_philos)
		return (0);
	new_philos->top = NULL;
	new_philos->bottom = NULL;
	return (new_philos);
}

t_philo	*c_philo(int val, t_data *data)
{
	t_philo	*new_philo;

	new_philo = malloc(sizeof(t_philo));
	if (!new_philo)
		return (0);
	new_philo->id = val;
	new_philo->data = data;
	new_philo->next = NULL;
	new_philo->count_eat = 0;
	new_philo->last_time_eat = 0;
	new_philo->is_die = 0;
	return (new_philo);
}
