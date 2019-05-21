/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smondesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:35:01 by smondesi          #+#    #+#             */
/*   Updated: 2018/11/14 15:53:08 by smondesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int fd;
	char *line;
	int p;

	fd = 569;
//	get_next_line(fd, &line);
	while ((p = get_next_line(fd, &line)) == 1)
	{
		write(1, line, strlen(line));
		write(1, "\n", 1);
//		printf("%d", p);
	}
//	write(1, line, strlen(line));
	//	printf("\n%d", p);

	return (0);
}
