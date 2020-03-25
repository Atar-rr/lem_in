//
// Created by Вика on 24.03.2020.
//

#ifndef LEM_IN_H
# define LEM_IN_H
# include "./libftprintf/includes/libft.h"
# include "./libftprintf/includes/get_next_line.h"
# include "./libftprintf/includes/ft_printf.h"
# define START 1
# define END 2
# define USUAL 0

typedef struct	s_room
{
	char 			*name; 			//название комнаты
	int				ant; 			// 0 - если в комнате нет муравья, число - порядковый номер муравья
	int				rooms_status; 	//START, END, USUAL
	int				x; 				// координата для визуализации
	int				y; 				// координата для визуализации
	struct t_room	*links; 		// cписок связей с другими комнатами
	struct t_room	*next;			//используется при считывание
}				t_room;

typedef struct	s_lemin 			// общая структура
{
	int			ants_count; 		//количество муравьев
	int 		rooms_count;
	t_room		*rooms; 			//указатель на старт

}				t_lemin;

#endif
