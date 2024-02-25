/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:32:35 by amel-has          #+#    #+#             */
/*   Updated: 2024/01/24 23:41:02 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (ft_putstr_fd("Error 1", 2), 1);
	if (!check_input(argv))
		return (ft_putstr_fd("Error 2", 2), 1);
	if (!algo(argc, argv))
		return (ft_putstr_fd("Error 3", 2), 1);
	return (0);
}
