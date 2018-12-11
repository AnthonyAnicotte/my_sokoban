/*
** EPITECH PROJECT, 2023
** PSU_my_sokoban_2018
** File description:
** Created by anthonyanicotte,
*/

#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../include/struct.h"
#include "../include/function.h"

int open_file(struct_t *soko, char *av)
{
    int size = 50000;
    int fd = open(av, O_RDONLY);

    soko->buffer = malloc(sizeof(char) * 50000);
    if (fd == -1)
        exit(84);
    read(fd, soko->buffer, size - 1);
    return (0);
}

void win_function(void)
{
    clear();
    printw("CONGRATULATIONS, YOU WON !");
    refresh();
    while (1) {
        if (getch() == ' ') {
            endwin();
            exit(0);
        }
    }
}

void check_terminal_size(struct_t *soko)
{
    int y_max;
    int x_max;

    getmaxyx(stdscr, y_max, x_max);
    if (y_max < soko->columns || x_max < soko->lines - 1) {
        write(1, "TERMINAL SI TOO SMALL, INCREASE ITS SIZE\n", 41);
        exit (84);
    }
}

void help_display(void)
{
    write(1, "USAGE\n     ./my_sokoban map\nDESCRIPTION\n     map file", 53);
    write(1, " representing the warehouse map, containing '#' for walls", 57);
    write(1, ",\n         'P' for the player, 'X' for boxes and 'O' for ", 57);
    write(1, "storage locations.\n", 19);
}

void clear_print_and_refresh(struct_t *soko)
{
    clear();
    replace_storage(soko);
    printw(soko->buffer);
    refresh();
}
