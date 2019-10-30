/*
** EPITECH PROJECT, 2018
** 101pong_2018
** File description:
** pong
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>

typedef struct pos_P {
    int x;
    int y;
}t_pos;

int fs_open_file(char const *filepath);
int my_printf(char const *s, ...);
void fs_print_first_line(char const *filepath);
void mouv_p(char **buf, t_pos *pos, int ch);
t_pos *my_down(t_pos *pos, char **buf);
t_pos *my_up(t_pos *pos, char **buf);
t_pos *my_right(t_pos *pos, char **buf);
t_pos *my_left(t_pos *pos, char **buf);
int My_x(char const *filepath);
int My_y(char const *filepath);
char **my_map(char *buffer, int taille_map_y, int taille_map_x, t_pos *pos);
void my_display(char **buf);
int my_strlen(char const *str);
int my_popup(char **buf, t_pos *pos, char const *fd);
int my_strcmp(char const *s1, char const *s2);
void fs_print_first_line(char const *filepath);
int main(int ac, char **av);
void my_putstr(char const *str);
void my_putchar(char c);
t_pos *coord_of_p(int i, int j, t_pos *pos);

#endif /* !SOKOBAN_H_ */
