/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:54:00 by mjafari           #+#    #+#             */
/*   Updated: 2021/08/10 07:32:38 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "get_next_line_bonus.c"
#include "get_next_line_utils_bonus.c"

int main(void)
{
    char *str;
    // int fd = open("test.txt", O_RDWR);
    int fd2 = open("test.txt", O_RDWR);
    for (size_t i = 0; i < 1; i++)
    {
        /* code */
        str = get_next_line(fd2);
        printf("%s", str);
		free(str);
        // str = get_next_line(256);
        // printf("%s", str);
		// free(str);
    }
    return 0;
}