/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:50:27 by apylypen          #+#    #+#             */
/*   Updated: 2024/03/18 20:50:29 by apylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] != '-' && str[i] != '+' && (str[i] > 57 || str[i] < 48))
		return (0);
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
		res = res * 10 + (str[i++] - 48);
	return (res * sign);
}

int	ft_intlen(int n)
{
	int		i;

	i = 1;
	if (n < 0)
		i++;
	else if (n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;

	i = ft_intlen(n);
	ptr = (char *) malloc (i * sizeof (char));
	while (i >= 0)
		ptr[i--] = 0;
	i = ft_intlen(n) - 1;
	if (!ptr)
		return (0);
	if (n < 0)
		ptr[0] = '-';
	else if (n < 10 && n >= 0)
	{
		ptr[0] = n + 48;
		return (ptr);
	}
	while (--i >= 0 && n)
	{
		ptr[i] = ft_abs(n % 10) + 48;
		n /= 10;
	}
	return (ptr);
}
