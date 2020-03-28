//
// Created by Вика on 24.03.2020.
//

#include "lem_in.h"

void	print_array(int *array, int size)
{
	int i = 0;

	while (i < size)
	{
		ft_printf(1, "%-5d", array[i]);
		i++;
	}
}

void	print_element(t_room *rooms, int index)
{
	t_room *help = rooms;

	while(help->index != index)
		help = help->next;
	ft_printf(1, "%-5s", help->name);
}

void	print_matrix(t_lemin *lemin)
{
	int i = 0;
	t_room		*help;

	ft_printf(1, "     ");
	while (i < lemin->rooms_count)
	{
		print_element(lemin->rooms, i);
		i++;

	}
	ft_printf(1, "\n\n");
	i = 0;
	while (i < lemin->rooms_count)
	{
		print_element(lemin->rooms, i);
		print_array(lemin->matrix[i], lemin->rooms_count);
		i++;
		ft_printf(1, "\n");
	}

}

void	print_double_array(int **array, int size)
{
	int i;
	int k;

	i = 0;
	while (i < size)
	{
		k = 0;
		while (k < size)
		{
			ft_printf(1, "%d  ", array[i][k]);
			k++;
		}
		ft_printf(1, "\n");
		i++;
	}
}

int	**create_double_array(int size)
{
	int	i;
	int	k;
	int	**array;

	i = 0;
	array = (int **)malloc(sizeof(int *) * size);
	while (i < size)
	{
		k = 0;
		array[i] = (int *)malloc(sizeof(int) * size);
		while (k < size)
		{
			array[i][k] = 0;
			k++;
		}
		i++;		
	}
	return (array);
}

void	print_rooms(t_lemin *lemin)
{
	t_room	*help;

	ft_printf(1, "Ant's count %d\n", lemin->ants_count);
	ft_printf(1, "Room's count %d\n", lemin->rooms_count);
	help = lemin->rooms;
	while (help)
	{
		ft_printf(1, "name - %s, status - %d, index - %d, x - %d, y - %d\n", help->name, help->rooms_status, help->index, help->x, help->y);
		help = help->next;
	}
}

void	add_room(t_lemin *lemin, t_room *room)
{
	t_room	*help;

	if (lemin->rooms == NULL)
		lemin->rooms = room;
	else
	{
		help = lemin->rooms;
		while (help->next)
			help = help->next;
		help->next = room;

		//lemin->rooms = room;
		//room->next = help;
	}
}

void	create_room(t_lemin *lemin, char *line, int flag)
{
	t_room	*room;
	int 	i;

	i = ft_len_word(line, ' ');
	room = (t_room *)malloc(sizeof(t_room));
	room->name = ft_strsub(line, 0, i);
	i++;
	room->x = ft_atoi(line + i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	i++;
	room->y = ft_atoi(line + i);
	room->rooms_status = flag;
	room->ant = 0;
	room->links = NULL;
	room->next = NULL;
	lemin->rooms_count++;
	add_room(lemin, room);
}

void	assign_indexes(t_lemin *lemin)
{
	t_room	*help;
	int	i;

	i = 1;
	help = lemin->rooms;
	while(help)
	{
		if (help->rooms_status == START)
			help->index = 0;
		else if (help->rooms_status == END)
			help->index = lemin->rooms_count - 1;
		else
		{
			help->index = i;
			i++;
		}
		help = help->next;
	}
}

t_room	*find_room(t_room *rooms, char *name)
{
	t_room	*help;

	help = rooms;
	while (ft_strcmp(help->name, name) != 0)
		help = help->next;
	return (help);

}

void	create_links(t_lemin *lemin, char *line)
{
	char	**names;
	t_room	*from_room;
	t_room	*to_room;

	if (lemin->matrix == NULL)
	{
		lemin->matrix = create_double_array(lemin->rooms_count);
		assign_indexes(lemin);
		//print_rooms(lemin);
		//print_matrix(lemin);
		//print_double_array(lemin->matrix, lemin->rooms_count);
	}
	names = ft_strsplit(line, '-');
	from_room = find_room(lemin->rooms, names[0]);
	to_room = find_room(lemin->rooms, names[1]);
	lemin->matrix[from_room->index][to_room->index] = 1;
	lemin->matrix[to_room->index][from_room->index] = 1;
}

void 	create_graph(t_lemin *lemin, char *file) //сделать потом интовой, чтобы возвращала 0 в случае ошибки
{
	int 	fd;
	int 	gnl;
	int 	flag;
	char	*line;

	flag = USUAL;
	fd = open(file, O_RDONLY);
	gnl = get_next_line(fd, &line);
	lemin->ants_count = ft_atoi(line);
	free(line);
	while ((gnl = get_next_line(fd, &line)))
	{
		if (ft_strcmp(line, "##start") == 0)
			flag = START;
		else if (ft_strcmp(line, "##end") == 0)
			flag = END;
		else if (ft_count_word(line, ' ') == 3)
		{
			create_room(lemin, line, flag);
			flag = USUAL;
		}
		else if (ft_count_word(line, ' ') == 1)
			create_links(lemin, line);
		free(line);
	}
	close (fd);
	print_rooms(lemin);
	print_matrix(lemin);
}

t_lemin		*initialization()
{
	t_lemin		*lemin;

	if (!(lemin = (t_lemin *)malloc(sizeof(t_lemin))))
		return (NULL);
	lemin->ants_count = 0;
	lemin->rooms_count = 0;
	lemin->rooms = NULL;
	lemin->matrix = NULL;
	return (lemin);
}

int			main(int argc, char **argv)
{
	t_lemin *lemin;

	if (argc > 1)
	{
		if (!(lemin = initialization()))
			return (0);
		create_graph(lemin, argv[1]);
	}
	return (0);
}
