/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:53:31 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/10 20:31:10 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* -------------------------------------------------------------------------- */

volatile sig_atomic_t	g_isrunning = 1;

/* -------------------------------------------------------------------------- */

void	p_err(void)
{
	write(2, RED, 9);
	write(2, "\nERROR\t", 7);
	write(2, NC, 7);
	write(2, BLD, 4);
	write(2, "Something's wrong, please try again.\n", 37);
	write(2, NC, 7);
}

/* -------------------------------------------------------------------------- */

int	ckeck_pid_arg(char *ascii_pid)
{
	int	i;
	int	str_len;

	i = 0;
	str_len = ft_strlen(ascii_pid);
	while (ft_isdigit(ascii_pid[i]))
		++i;
	if (i != str_len)
		return (-1);
	return (0);
}

/* -------------------------------------------------------------------------- */

int	send_msg(int pid, char *msg)
{
	short	i;
	short	j;
	char	c;

	i = 0;
	while (msg[i])
	{
		c = msg[i++];
		j = -1;
		while (++j < 8)
		{
			if (c & (1 << j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
		}
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

int	main(int argc, char **argv)
{
	if (argc != 3 || ckeck_pid_arg(argv[1]) != 0)
		return (p_err(), -1);
	send_msg(ft_atoi(argv[1]), argv[2]);
	return (0);
}

/* -------------------------------------------------------------------------- */
