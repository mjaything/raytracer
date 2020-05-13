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

int		ft_atoi_base(char *str, int str_base)
{
    int i;
    int number;
    int sign;

    i = 0;
    number = 0;
    sign = 1;
    sign = (str[i] == '-') ? -1 : 1;
    (str[i] == '-' || str[i] == '+') ? i++ : 0;
    while (i < ft_strlen(str))
    {
        if (str[i] >= '0' && str[i] <= '0' + str_base - 1)
            number += (str[i] - '0') * \
                        ft_pow(str_base, ft_strlen(str) - (i + 1));
        else if (ft_tolower(str[i]) >= 'a' && \
                ft_tolower(str[i]) <= 'a' + str_base - 11)
            number += (ft_tolower(str[i]) - 'a' + 10) * \
                        ft_pow(str_base, ft_strlen(str) - (i + 1));
        i++;
    }
    return sign * number;
}