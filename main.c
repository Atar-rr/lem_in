//
// Created by Вика on 24.03.2020.
//

#include "lem_in.h"

void 	create_graph(t_lemin *lemin)
{
	

}

t_lemin		*initialization()
{
	t_lemin		*lemin;

	if (!(lemin = (t_lemin *)malloc(sizeof(t_lemin))))
		return (NULL);
	lemin->ants_count = 0;
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
		create_graph(lemin);

	}
	return (0);
}
