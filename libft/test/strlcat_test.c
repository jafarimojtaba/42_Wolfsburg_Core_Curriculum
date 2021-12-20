/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 12:01:55 by mjafari           #+#    #+#             */
/*   Updated: 2021/06/05 13:10:12 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main()
{
	char src[15], dest[15], dest2[15];
	strcpy(src, "toto");
	strcpy(dest, "");
	strcpy(dest2, "");
	printf("%d \n", (int)ft_strlcat(dest, src, 0));
	printf("%d \n", (int)strlcat(dest2, src, 0));
	printf("%s \n", dest);
	printf("%s \n", dest2);
	return 0;
}