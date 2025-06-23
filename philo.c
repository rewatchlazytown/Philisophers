/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:50:47 by apylypen          #+#    #+#             */
/*   Updated: 2024/03/18 20:50:49 by apylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_check(void *vd_philo)
{
	t_philo	*philo;

	philo = (t_philo *)vd_philo;
	while (!(philo->data->run))
		;
	if (philo->index % 2)
		usleep(30 * 1000);
	else
		usleep(60 * 1000);
	while (philo->run && philo->data->run)
	{
		if (!ft_check_dead(philo))
			break ;
		usleep(2 * 1000);
	}
	return (0);
}

void	*ft_routine(void *vd_philo)
{
	t_philo	*philo;

	philo = (t_philo *)vd_philo;
	while (!(philo->data->run))
		;
	philo->run = 1;
	philo->time = ft_get_time(philo->tv);
	if (!(philo->index % 2))
		usleep(30 * 1000);
	if (philo->data->n_philos == 1)
	{
		ft_print(philo, "took a fork");
		while (philo->run)
			;
		return (0);
	}
	while (philo->run && philo->data->run)
	{
		ft_eat(philo);
		ft_print(philo, "is sleeping");
		ft_usleep(philo, philo->data->time_to_sleep);
		ft_print(philo, "is thinking");
	}
	return (0);
}

int	ft_create_philos(t_data *data)
{
	int	i;

	if (!data->n_philos)
		return (printf("Error\n[number_of_philos] should be > 0\n") * 0);
	data->philos = (t_philo *) malloc (data->n_philos * sizeof(t_philo));
	if (!data->philos)
		return (printf("Error\nMalloc failed") * 0);
	i = -1;
	while (++i < data->n_philos)
	{
		data->philos[i].data = data;
		data->philos[i].index = i + 1;
		data->philos[i].prev_id = ft_mod(i - 1, data->n_philos);
		data->philos[i].id = ft_itoa(i + 1);
		data->philos[i].eat = data->eat_times;
		pthread_mutex_init(&data->philos[i].fork, 0);
		pthread_mutex_init(&data->philos[i].check, 0);
		pthread_create(&data->philos[i].philo, 0,
			&ft_routine, (void *)&data->philos[i]);
		pthread_create(&data->philos[i].monitor, 0,
			&ft_check, (void *)&data->philos[i]);
		pthread_detach(data->philos[i].monitor);
	}
	data->start_time = ft_get_time(data->philos[0].tv);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!ft_check_input(ac, av))
		return (0);
	data.n_philos = ft_atoi(av[1]);
	data.time_to_die = ft_atoi(av[2]);
	data.time_to_eat = ft_atoi(av[3]);
	data.time_to_sleep = ft_atoi(av[4]);
	data.eat_times = -1;
	data.run = 0;
	if (ac == 6)
		data.eat_times = ft_atoi(av[5]);
	if (!ft_create_philos(&data))
		return (0);
	data.run = 1;
	ft_end(&data);
	return (0);
}
