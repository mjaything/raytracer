/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 18:47:14 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/13 18:47:16 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi_base(char *str, int str_base)
{
	int		i;
	int		sign;
	int		number;

	i = 0;
	number = 0;
	sign = 1;
	if (!str || (str_base < 2 || str_base > 16))
		return 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] != '\0')
	{
		if (ft_tolower(str[i]) >= 'a' && ft_tolower(str[i]) <= 'f')
			number = (number * str_base) + (ft_tolower(str[i]) - 'a' + 10);
		else
			number = (number * str_base) + (ft_tolower(str[i]) - '0');
		i++;
	}
	return sign * number;
}
