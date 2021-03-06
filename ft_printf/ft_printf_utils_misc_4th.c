/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_misc_4th.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:40:46 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/12 23:35:13 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

void	ft_putnbr(int n, int *outpt_len)
{
	if (n >= 0 && n < 10)
		ft_putchar(n + 48, outpt_len);
	else if (n == -2147483648)
		ft_putstr_len("2147483648", 10, outpt_len);
	else if (n < 0 && n > -2147483648)
		ft_putnbr(n * (-1), outpt_len);
	else if (n >= 10)
	{
		ft_putnbr(n / 10, outpt_len);
		ft_putnbr(n % 10, outpt_len);
	}
}

/* -------------------------------------------------------------------------- */

void	ft_putnbr_presign(int n, t_flags *flags, int *outpt_len)
{
	if (n < 0)
		ft_putchar('-', outpt_len);
	else if (flags -> plus && n >= 0)
		ft_putchar('+', outpt_len);
	else if (flags -> space && n >= 0)
		ft_putchar(' ', outpt_len);
}

/* -------------------------------------------------------------------------- */

void	get_unbr_size(unsigned int n, size_t *nbr_size)
{
	if (n <= 9)
		(*nbr_size) += 1;
	else if (n >= 10)
	{
		get_unbr_size(n / 10, nbr_size);
		get_unbr_size(n % 10, nbr_size);
	}
}

/* -------------------------------------------------------------------------- */

void	ft_putunbr(unsigned int n, int *outpt_len)
{
	if (n < 10)
		ft_putchar(n + 48, outpt_len);
	else if (n >= 10)
	{
		ft_putunbr(n / 10, outpt_len);
		ft_putunbr(n % 10, outpt_len);
	}
}

/* -------------------------------------------------------------------------- */

void	handle_error(int *outpt_len)
{
	write(2, "\rINPUT ERROR", 12);
	ft_putnchar(' ', *outpt_len, outpt_len);
	*outpt_len = -1;
}

/* -------------------------------------------------------------------------- */
