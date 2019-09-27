#include "../incl/fdf.h"

static t_row	*get_row(char *str, int *min_height, int *max_height)
{
	char 	**split;
	int 	i;
	t_row 	*row;


	row = (t_row *)ft_memalloc(sizeof(t_row));
	i = 0;
	row->len = 0;
	split = ft_strsplit(str, ' ');
	while (split[row->len] != 0)
		row->len++;
	row->content = (int *)malloc(sizeof(int) * (row->len));
	while (split[i] != NULL)
	{
		row->content[i] = ft_atoi(split[i]);
		if (row->content[i] > *max_height)
			*max_height = row->content[i];
		if (row->content[i] < *min_height)
			*min_height = row->content[i];
		i++;
	}
	return (row);
}

t_row		*push_back_list(t_row *li, t_row *data)
{
    t_row *element;
    t_row *temp;

    if (!(element = (t_row *)malloc(sizeof(t_row))))
        return (NULL);
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

t_map	*read_map(char *fp)
{
	char 	*line;
	t_map 	*map;
	t_row 	*row;
	int		fd;

	map = (t_map *)malloc(sizeof(t_map));
	map->height = 0;
	map->max_height = 0;
	map->min_height = 0;
	row = NULL;
	if ((fd = open(fp, O_RDONLY)) == -1)
	{
		ft_putendl("error");
		exit(0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		row = push_back_list(row, get_row(line,&map->min_height, &map->max_height));
		ft_strdel(&line);
		map->height++;
	}
	printf("min_height : %d Max_height : %d\n", map->min_height, map->max_height);
	map->row = row;
	return (map);
}
