/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:56:04 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/16 14:35:24 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "includes/ft_printf.h"

void	print_error(char *local, int n)
{
	if (n == 22 || n == 53)
	{
		ft_printf("%s: %s\n", local, strerror(n));
		ft_printf("Usage: ./so_long <filename>.ber\n");
		exit(n);
	}
	else if (n == 59)
	{
		ft_printf("Error\n");
		ft_printf("Map isn't valid.❌\nRTFM or call the dev/tech person!📑\n");
		exit(59);
	}
	ft_printf("%s: %s\n", local, strerror(n));
	exit(n);
}
