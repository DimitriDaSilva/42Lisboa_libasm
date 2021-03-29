/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:50:26 by dda-silv          #+#    #+#             */
/*   Updated: 2021/03/29 15:28:57 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_atoi_base_test(void)
{
	print_header("ft_atoi_base");

	check(ft_atoi_base("    +++12", 0) == 0);
	check(ft_atoi_base("    +++12", "") == 0);
	check(ft_atoi_base("    +++12", "1") == 0);
}