/*
** EPITECH PROJECT, 2023
** PSU_my_sokoban_2018
** File description:
** Created by anthonyanicotte,
*/
#ifndef PSU_MY_SOKOBAN_2018_FUNCTION_H
#define PSU_MY_SOKOBAN_2018_FUNCTION_H

#include "struct.h"

int check_the_win(struct_t *soko);
int storage_boxes(struct_t *soko);
int check_char(struct_t *soko);
int error_handling_sharp_square(struct_t *soko);
int same_lines(struct_t *soko);
int many_players(struct_t *soko);
void check_terminal_size(struct_t *soko);
void space_bar(struct_t *soko);
int open_file(struct_t *soko, char *av);
void win_function();
void clear_print_and_refresh(struct_t *soko);
void help_display(void);
void part_one_down(struct_t *soko, int pos);
void part_one_left(struct_t *soko, int pos);
void part_one_right(struct_t *soko, int pos);
void part_one_up(struct_t *soko, int pos);
void part_two_down(struct_t *soko, int pos);
void part_two_left(struct_t *soko, int pos);
void part_two_right(struct_t *soko, int pos);
void part_two_up(struct_t *soko, int pos);
int error_handling(struct_t *soko);
int key_up_case(struct_t *soko);
int key_down_case(struct_t *soko);
int key_left_case(struct_t *soko);
int key_right_case(struct_t *soko);
void replace_storage(struct_t *soko);

#endif