/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_isdata.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:15:22 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/12 20:35:54 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/* -------------------------------------------------------------------------- */

int	ft_isflag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (c);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	ft_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' \
		|| c == 'p' || c == 'x' || c == 'X' || c == 'u')
		return (c);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	ft_isdot(char **c)
{
	if (**c == '.')
	{
		(*c) += 1;
		return (1);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

int	ft_will_be_valid(char *s)
{
	while (*s && (*s == '-' || *s == '0' || *s == '+' \
		|| *s == '#' || *s == ' '))
		s++;
	while (*s >= '0' && *s <= '9')
		s++;
	if (*s == '.')
		s++;
	while (*s >= '0' && *s <= '9')
		s++;
	if (*s == 'c' || *s == 's' || *s == 'd' || *s == 'i' \
		|| *s == 'p' || *s == 'x' || *s == 'X' || *s == 'u')
		return (1);
	return (0);
}

/* -------------------------------------------------------------------------- */