/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorceac <dgorceac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:44:38 by dgorceac          #+#    #+#             */
/*   Updated: 2025/10/06 09:16:34 by dgorceac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char character)
{
	int				i;

	i = 8;
	while (i > 0)
	{
		i--;
		if ((character >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	pid_t		server_pid;
	const char	*message;
	int			i;

	ft_printf("pid :%d\n", getpid());
	if (argc != 3)
	{
		ft_printf("Try: ./client <pid> <message>\n", argv[0]);
		exit (0);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Attention: Please ensure you are using the correct PID");
		exit (0);
	}
	message = argv[2];
	i = 0;
	while (message[i])
		send_signal(server_pid, message[i++]);
	send_signal(server_pid, '\0');
	return (0);
}
