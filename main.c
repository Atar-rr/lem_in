//
// Created by Вика on 24.03.2020.
//

#include "lem_in.h"

void	add_room(t_lemin *lemin, t_room *room)
{
	t_room	*help;

	ft_printf(1, "%s, status - %d, x - %d, y - %d\n", room->name, room->rooms_status, room->x, room->y);
	if (lemin->rooms == NULL)
		lemin->rooms = room;
	else
	{
		help = lemin->rooms;
		lemin->rooms = room;
		room->next = help;
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
		else
			ft_printf(1, "123\n");
		//else if (ft_count_word(line, ' ') == 1)
			//create_;
		free(line);
	}
	close (fd);
}

t_lemin		*initialization()
{
	t_lemin		*lemin;

	if (!(lemin = (t_lemin *)malloc(sizeof(t_lemin))))
		return (NULL);
	lemin->ants_count = 0;
	lemin->rooms_count = 0;
	lemin->rooms = NULL;
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
