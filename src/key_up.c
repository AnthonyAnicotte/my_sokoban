/*
** EPITECH PROJECT, 2023
** PSU_my_sokoban_2018
** File description:
** Created by anthonyanicotte,
*/

#include "../include/struct.h"
#include "../include/function.h"

void part_two_up(struct_t *soko, int pos)
{
        soko->buffer[pos] = 'P';
        soko->buffer[soko->position_p] = ' ';
        soko->buffer[pos - soko->columns] = 'X';
        soko->position_p = pos;
    clear_print_and_refresh(soko);
}

void part_one_up(struct_t *soko, int pos)
{
    soko->buffer[pos] = 'P';
    soko->buffer[soko->position_p] = ' ';
    soko->position_p = pos;
    clear_print_and_refresh(soko);
}

int key_up_case(struct_t *soko)
{
    int pos = soko->position_p - soko->columns;

    if (soko->buffer[pos] == ' ' || soko->buffer[pos] == 'O') {
        part_one_up(soko, pos);
        check_terminal_size(soko);
        return (0);
    } else if (soko->buffer[pos] == 'X' &&
        (soko->buffer[pos - soko->columns] == ' ' ||
            soko->buffer[pos - soko->columns] == 'O')) {
        part_two_up(soko, pos);
        check_terminal_size(soko);
        return (0);
    }
    check_terminal_size(soko);
    return (0);
}