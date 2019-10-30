/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** sokoban
*/

#include "../include/sokoban.h"

t_pos *my_left(t_pos *pos, char **buf)
{
    if (buf[pos->y][pos->x - 1] == ' '){
        buf[pos->y][pos->x - 1] = 'P';
        buf[pos->y][pos->x] = ' ';
        pos->x -= 1;
    }if (buf[pos->y][pos->x - 1] == 'X' && buf[pos->y][pos->x - 2] == ' ') {
        buf[pos->y][pos->x - 2] = 'X';
        buf[pos->y][pos->x - 1] = 'P';
        buf[pos->y][pos->x] = ' ';
        pos->x -= 1;
    }else if (buf[pos->y][pos->x - 1] == 'X' && buf[pos->y][pos->x - 2] == 'O'){
        buf[pos->y][pos->x - 2] = '0';
        buf[pos->y][pos->x - 1] = 'P';
        buf[pos->y][pos->x] = ' ';
        pos->x -= 1;
    }if (buf[pos->y][pos->x - 1] == 'O') {
        buf[pos->y][pos->x - 1] = 'P';
        buf[pos->y][pos->x] = ' ';
        pos->x -= 1;
    }
    return (pos);
}

t_pos *my_right(t_pos *pos, char **buf)
{
    if (buf[pos->y][pos->x + 1] == ' '){
        buf[pos->y][pos->x + 1] = 'P';
        buf[pos->y][pos->x] = ' ';
        pos->x += 1;
    }if (buf[pos->y][pos->x + 1] == 'X' && buf[pos->y][pos->x + 2] == ' ') {
        buf[pos->y][pos->x + 2] = 'X';
        buf[pos->y][pos->x + 1] = 'P';
        buf[pos->y][pos->x] = ' ';
        pos->x += 1;
    }else if (buf[pos->y][pos->x + 1] == 'X' && buf[pos->y][pos->x + 2] == 'O'){
        buf[pos->y][pos->x + 2] = '0';
        buf[pos->y][pos->x + 1] = 'P';
        buf[pos->y][pos->x] = ' ';
        pos->x += 1;
    }if (buf[pos->y][pos->x + 1] == 'O') {
        buf[pos->y][pos->x + 1] = 'P';
        buf[pos->y][pos->x] = ' ';
        pos->x += 1;
    }
    return (pos);
}

t_pos *my_up(t_pos *pos, char **buf)
{
    if (buf[pos->y - 1][pos->x] == ' '){
        buf[pos->y - 1][pos->x] = 'P';
        buf[pos->y][pos->x] = ' ';
        pos->y -= 1;
    }if (buf[pos->y - 1][pos->x] == 'X' && buf[pos->y - 2][pos->x] == ' ') {
        buf[pos->y - 2][pos->x] = 'X';
        buf[pos->y - 1][pos->x] = 'P';
        buf[pos->y][pos->x] = ' ';
        pos->y -= 1;
    }else if (buf[pos->y - 1][pos->x] == 'X' && buf[pos->y - 2][pos->x] == 'O'){
        buf[pos->y - 2][pos->x] = '0';
        buf[pos->y - 1][pos->x] = 'P';
        buf[pos->y][pos->x] = ' ';
        pos->y -= 1;
    }if (buf[pos->y - 1][pos->x] == 'O') {
        buf[pos->y - 1][pos->x] = 'P';
        buf[pos->y][pos->x] = ' ';
        pos->y -= 1;
    }
    return (pos);
}

t_pos *my_down(t_pos *pos, char **buf)
{
    if (buf[pos->y + 1][pos->x] == ' '){
        buf[pos->y + 1][pos->x] = 'P';
        buf[pos->y][pos->x] = ' ';
        pos->y += 1;
    }if (buf[pos->y + 1][pos->x] == 'X' && buf[pos->y + 2][pos->x] == ' ') {
        buf[pos->y + 2][pos->x] = 'X';
        buf[pos->y + 1][pos->x] = 'P';
        buf[pos->y][pos->x] = ' ';
        pos->y += 1;
    }else if (buf[pos->y + 1][pos->x] == 'X' && buf[pos->y + 2][pos->x] == 'O'){
        buf[pos->y + 2][pos->x] = '0';
        buf[pos->y + 1][pos->x] = 'P';
        buf[pos->y][pos->x] = ' ';
        pos->y += 1;
    }if (buf[pos->y + 1][pos->x] == 'O') {
        buf[pos->y + 1][pos->x] = 'P';
        buf[pos->y][pos->x] = ' ';
        pos->y += 1;
    }
    return (pos);
}

void mouv_p(char **buf, t_pos *pos, int ch)
{
    if (ch == KEY_LEFT)
        my_left(pos, buf);
    else if (ch == KEY_RIGHT)
        my_right(pos, buf);
    else if (ch == KEY_DOWN)
        my_down(pos, buf);
    else if (ch == KEY_UP)
        my_up(pos, buf);
}
