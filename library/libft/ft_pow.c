/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 00:12:08 by min-kim           #+#    #+#             */
/*   Updated: 2020/05/14 00:12:10 by min-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int base, int exponent)
{
	int number;

	number = 1;
	if (exponent == 0)
		return (1);
	while (exponent > 0)
	{
		number *= base;
		exponent--;
	}
	return (number);
}
