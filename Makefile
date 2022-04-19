##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c						\
		src/window.c					\
		src/title.c						\
		src/game.c						\
		src/create_sound.c				\
		src/create_vector.c				\
		src/create_color.c				\
		src/create_rect.c				\
		src/create_path.c				\
		src/count_checkpoint.c			\
		src/create_path_tile.c			\
		src/create_path_tile_dir.c		\
		src/create_path_tile_utils.c	\
		src/enemy.c						\
		src/get_time_sec.c				\
		src/game_event.c				\
		src/create_game_objects.c		\
		src/button.c					\
		src/start_button.c				\
		src/quit_button.c				\
		src/resume_button.c				\
		src/go_title_button.c			\
		src/collide.c					\
		src/tower.c						\
		src/hp_bar.c					\
		src/apply_game.c				\
		src/projectiles.c				\
		src/normalize_vec.c				\
		src/pause_menu.c				\
		src/damage.c					\
		src/count_tower_place.c			\
		src/create_tower_place.c		\
		src/pause_update_dtime.c		\
		src/move_rect.c					\
		src/enemy_slow.c				\
		src/tower_target.c				\
		src/create_tower.c				\
		src/update_game.c				\
		src/apply_path.c				\
		src/create_enemy.c				\
		src/get_right.c					\
		src/yellow_tower.c

OBJ	=	$(SRC:.c=.o)

CSFML	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

NAME	=	my_defender

CPPFLAGS += -I include

all: Make_drag_drop $(NAME)

lib/libmy.a:
	make -C lib/my

Make_drag_drop:
	make -C src/drag_drop

$(NAME): lib/libmy.a $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CSFML) -L lib -lmy -lm -L src/drag_drop -ldrag_drop

clean:
	make clean -C lib/my
	make clean -C src/drag_drop
	rm -f $(OBJ)

fclean:
	make clean
	make fclean -C lib/my
	make fclean -C src/drag_drop
	rm -f $(NAME)

re:	fclean all

.PHONY:	all	clean fclean re
