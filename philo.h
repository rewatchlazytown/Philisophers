/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:50:55 by apylypen          #+#    #+#             */
/*   Updated: 2024/03/18 20:50:57 by apylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

struct	s_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		philo;
	pthread_t		monitor;
	pthread_mutex_t	fork;
	pthread_mutex_t	check;
	struct timeval	tv;
	int				time;
	char			*id;
	int				index;
	int				prev_id;
	int				eat;
	int				run;
}	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	pthread_mutex_t	print;
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times;
	int				run;
	int				start_time;
}	t_data;

/* philo */
void	*ft_routine(void *vd_philo);
void	*ft_check(void *vd_philo);
int		ft_create_philos(t_data *data);
/* utils */
void	ft_end(t_data *data);
void	ft_print(t_philo *philo, char *str);
int		ft_get_time(struct timeval tv);
int		ft_mod(int n, int m);
void	ft_usleep(t_philo *philo, int ms);
/* help */
int		ft_check_dead(t_philo *philo);
void	ft_eat(t_philo *philo);
/* check */
int		ft_check_input(int ac, char **av);
/* itoa */
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_intlen(int n);
int		ft_abs(int n);

#endif
