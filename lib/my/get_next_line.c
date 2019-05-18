/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** get_next_line
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"

char *mymemset(char *str, int i, int nb)
{
    int j = -1;

    while (++j != nb)
        str[j] = i;
    return (str);
}

int myln(char *str, int nb)
{
    static int j = 0;
    int i = 0;

    if (nb == 0){
        while (str[j] != '\n' && str[j] != 0)
            j += 1;
        j += 1;
        return (j);
    }
    else {
        while (str[i] != '\0')
            i += 1;
        return (i);
    }
}

char *file(char *str, int nb)
{
    int i = 0;

    while (i != nb) {
        str[i] = '\0';
        i += 1;
    }
    return (str);
}

char *str_str(char *fusion, char *add)
{
    int j = 0;
    int i = -1;
    char *srt = NULL;
    int nb = myln(fusion, 1) + myln(add, 1);

    if ((srt = malloc(sizeof(char) * (nb + 1))) == NULL)
        return (NULL);
    while (fusion[++i] != '\0')
        srt[i] = fusion[i];
    srt[i] = 0;
    free(fusion);
    j = i;
    i = 0;
    while (add[i] != '\0') {
        srt[j] = add[i];
        i = i + 1;
        j = j + 1;
    }
    srt[j] = 0;
    return (srt);
}

char *get_next_line(int fd)
{
    char *buff = NULL;
    static char *fusion;
    int READ_SIZE = 1;
    int j = READ_SIZE;
    static int i = 0;

    if ((buff = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
        return (NULL);
    buff = mymemset(buff, 0, 2);
    if (i == 0) {
        fusion = malloc(2);
        fusion = mymemset(fusion, 0, 2);
        while (j == READ_SIZE){
            j = read(fd, buff, READ_SIZE);
            buff[j] = '\0';
            fusion = str_str(fusion, buff);
        }
        i = i + 1;
    }
    return (fusion);
}