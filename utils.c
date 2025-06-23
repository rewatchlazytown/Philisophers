/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:51:03 by apylypen          #+#    #+#             */
/*   Updated: 2024/03/18 20:51:04 by apylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_end(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
		pthread_join(data->philos[i].philo, 0);
	i = -1;
	while (++i < data->n_philos)
	{
		pthread_mutex_destroy(&data->philos[i].fork);
		pthread_mutex_destroy(&data->philos[i].check);
		free(data->philos[i].id);
	}
	pthread_mutex_destroy(&data->print);
	free(data->philos);
}

int	ft_get_time(struct timeval tv)
{
	gettimeofday(&tv, 0);
	return (tv.tv_sec % 100000 * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(t_philo *philo, int ms)
{
	int	start;

	start = ft_get_time(philo->tv);
	while (ft_get_time(philo->tv) - start < ms)
		;
}

void	ft_print(t_philo *philo, char *str)
{
	if (!philo->data->run || !philo->run)
		return ;
	pthread_mutex_lock(&philo->data->print);
	printf("%d %s %s\n", ft_get_time(philo->tv) - philo->data->start_time,
		philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}

int	ft_mod(int n, int m)
{
	if (!n || n == m || m == 0)
		return (0);
	while (n < 0)
		n += m;
	while (n > m)
		n -= m;
	return (n);
}
