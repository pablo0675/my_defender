/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my_defender.h"
#include "my.h"

void print_help(void)
{
    my_printf("USAGE:  ./my_defender\nFlags     -h for help\nINGAME:"
        "\n key escape for menu\n click on the tower on the upper left then"
        " click on the grey square on the map to place turret\n");
}

int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    if (env[0] == NULL) {
        my_printf("can't run csfml without env\n");
        return 84;
    }
    if (av[1] != NULL)
        if (av[1][0] == '-' && av[1][1] == 'h') {
            print_help();
            return 0;
        }
    return create_window();
}
