/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:50:19 by mjafari           #+#    #+#             */
/*   Updated: 2021/10/14 12:59:09 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"

int main()
{
    char *c;
    c = ft_printf("this is a char: c", "hi my name is mojtaba", "i'm in 2nd class", "i love you");
    printf("%s\n", c);
    c = ft_printf("this is a char: b", "hi my name is sajjad", "i'm in 3rd class", "i hate you");
    printf("%s\n", c);
    return 0;
}