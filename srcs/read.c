/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smondesi <smondesi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:23:07 by smondesi          #+#    #+#             */
/*   Updated: 2019/10/07 17:30:59 by smondesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static t_row	*get_row(char *str, int *min_height, int *max_height)
{
	char	**split;
	int		i;
	t_row	*row;

	if (!(row = (t_row *)ft_memalloc(sizeof(t_row))))
		exit(1);
	i = -1;
	row->len = 0;
	if (!(split = ft_strsplit(str, ' ')))
		exit(1);
	while (split[row->len] != 0)
		row->len++;
	if (!(row->content = (int *)malloc(sizeof(int) * (row->len))))
		exit(-1);
	while (split[++i] != NULL)
	{
		row->content[i] = ft_atoi(split[i]);
		if (row->content[i] > *max_height)
			*max_height = row->content[i];
		if (row->content[i] < *min_height)
			*min_height = row->content[i];
	}
	i = -1;
	ft_free_tab(split);
	return (row);
}

t_row			*push_back_list(t_row *li, t_row *data)
{
	t_row	*element;
	t_row	*temp;

	element = data;
	element->next = NULL;
	if (li == NULL)
		return (element);
	temp = li;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = element;
	return (li);
}

t_map			*read_map(char *fp)
{
	char	*line;
	t_map	*map;
	t_row	*row;
	int		fd;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		exit(1);
	map->height = 0;
	map->max_height = 0;
	map->min_height = 0;
	row = NULL;
	if ((fd = open(fp, O_RDONLY)) == -1)
	{
		ft_putendl_fd("error", 2);
		exit(0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		row = push_back_list(row, get_row(line, &map->min_height,
			&map->max_height));
		ft_strdel(&line);
		map->height++;
	}
	map->row = row;
	return (map);
}
