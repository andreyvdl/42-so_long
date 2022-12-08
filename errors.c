/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:56:04 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/08 15:04:15 by adantas-         ###   ########.fr       */
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
		ft_printf("Error\n❌Map isn't valid. RTFM or call dev!❌\n");
		exit(59);
	}
	ft_printf("%s: %s\n", local, strerror(n));
	exit(n);
}
