/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:21:42 by mjafari           #+#    #+#             */
/*   Updated: 2021/08/08 11:43:36 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"

int main(void)
{
    char *str;
    int fd = open("test2.txt", O_RDWR);
    for (size_t i = 0; i < 2; i++)
    {
        /* code */
        str = get_next_line(fd);
        printf("%s", str);
		free(str);
    }
    return 0;
}