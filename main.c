/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:59:38 by azhuri            #+#    #+#             */
/*   Updated: 2025/09/13 22:59:41 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

/*
 * main:
 * - parse the single argument into 16 clues
 * - call solver which prints solution or "Error\n"
 * - free memory and exit
 */
int	main(int argc, char **argv)
{
	int	*clues;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	clues = parse_clues(argv[1]);
	if (!clues)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!solve_and_print(clues))
	{
		/* solver prints Error if needed */
	}
	free(clues);
	return (0);
}
