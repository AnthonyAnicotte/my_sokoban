/*
** EPITECH PROJECT, 2023
** PSU_my_sokoban_2018
** File description:
** Created by anthonyanicotte,
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../include/function.h"

int movement_arrow(struct_t *soko)
{
    while (check_the_win(soko) == 1) {
        switch (getch()) {
        case KEY_UP:
            key_up_case(soko);
            break;
        case KEY_DOWN:
            key_down_case(soko);
            break;
        case KEY_LEFT:
            key_left_case(soko);
            break;
        case KEY_RIGHT:
            key_right_case(soko);
            break;
        case ' ':
            space_bar(soko);
            break;
        }
    }
    return (0);
}

int start_ncurse(struct_t *soko)
{
    initscr();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    noecho();
    printw(soko->buffer);
    refresh();
    movement_arrow(soko);
    endwin();
    return (0);
}

void count_X(struct_t *soko)
{
    int i = 0;

    soko->position_p_bis = soko->position_p;
    soko->buffer_bis = malloc(sizeof(char) * 50000);
    for (i = 0; soko->buffer[i] != '\0'; i++)
        soko->buffer_bis[i] = soko->buffer[i];
    soko->buffer_bis[i] = '\0';
}

void count_lines_columns(struct_t *soko)
{
    int i = 0;
    int j = 0;
    int k = 0;
    soko->columns = 0;
    soko->lines = 0;

    while (soko->buffer[k] != 'P')
        k++;
    soko->position_p = k;
    while (soko->buffer[i] != '\0')
        i++;
    while (soko->buffer[j] != '\n') {
        soko->columns++;
        j++;
    }
    soko->columns += 1;
    soko->map_size = i;
    soko->lines = (i / soko->columns) + 1;
    count_X(soko);
}

int main(int ac, char **av)
{
    struct_t *soko = malloc(sizeof(struct_t));
    soko->storage_pos = malloc(sizeof(int) * 20);

    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        help_display();
        return (0);
    }
    if (open_file(soko, av[1]) == 1)
        return (84);
    if (storage_boxes(soko) == 1)
        return (84);
    count_lines_columns(soko);
    if (error_handling(soko) != 0)
        return (84);
    if (start_ncurse(soko) == 0)
        return (0);
    return (0);
}