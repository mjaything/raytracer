/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 11:47:55 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/13 11:48:01 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	int     i;
	double	number;
	int	    sign;
    double  n;

	i = 0;
	number = 0;
	sign = 1;
    n = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
    str[i] == '-' ? sign = -1 : 1;
    str[i] == '-' || str[i] == '+' ? i++ : 0;
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + str[i++] - '0';
    if (str[i] == '.')
    {
        i++;
        while (str[i] >= '0' && str[i] <= '9')
            number += (str[i++] - '0') / (n *= 10)
    }
	return (sign * number);
}
