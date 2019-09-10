#include "../incl/fdf.h"

static t_row	*get_row(char *str)
{
	char 	**split;
	int 	i;
	t_row 	*row;

	row = malloc(sizeof(row));
	i = 0;
	row->len = 0;
	split = ft_strsplit(str, ' ');
	while (split[row->len] != NULL)
		row->len++;
	row->content = (int *)malloc(sizeof(int) * row->len);
	while (split[i] != NULL)
	{
		row->content[i] = ft_atoi(split[i]);
		i++;
	}
	return (row);
}

t_map            *push_back_list(t_map *li, t_row *data)
{
    t_map *element;
    t_map *temp;

    if (!(element = malloc(sizeof(*element))))
        return (NULL);
    element->row = *data;
    element->next = NULL;
    if (li == NULL)
        return (element);
    temp = li;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = element;
    return (li);
}

t_map	*read_map(char *fp)
{
	char 	*line;
	t_map 	*map;
	int		fd;

	map = NULL;
	if ((fd = open(fp, O_RDONLY)) == -1)
	{
		ft_putendl("error");
		exit(0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		map = push_back_list(map, get_row(line));
		ft_strdel(&line);
	}
	return (map);
}
