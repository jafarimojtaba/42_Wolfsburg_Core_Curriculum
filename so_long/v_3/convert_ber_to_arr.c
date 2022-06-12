/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ber_to_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:06:02 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/07 10:19:33 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int row;

char **read_rows(int fd)
{
    char **arr;
    char *tmp;
        
    tmp = get_next_line(fd);
    while (tmp)
    {
        row++;
        free(tmp);
        tmp = get_next_line(fd);
    }
    close(fd);
    arr = (char **)malloc((row) * sizeof(char *));
    return arr;
}

void map_to_arr(int fd, char **arr)
{
    int i;

    i = 0;
    while (i < row)
    {
        arr[i] = get_next_line(fd);
        i++;
    }
    close(fd);
}

char **convert_ber_to_arr(char *file)
{
    char **arr;
    int fd;
    fd = open(file, O_RDONLY);
    arr = read_rows(fd);
    fd = open(file, O_RDONLY);
    map_to_arr(fd, arr);
    // printf("row=%d col =%d\n", row, col);
    // for (int i = 0; i < row - 1; i++)
    // {
    //     for (int j = 0; j < col - 1; j++)
    //     {
    //         printf("%c ", arr[i][j]);
    //     }
    //     printf("\n");
    // }
    return (arr);
}