/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:42:32 by ibaby             #+#    #+#             */
/*   Updated: 2024/08/04 23:31:12 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_AST(t_command *command);

int	main(int ac, char **av, char **env)
{
	(void)av;
	(void)env;
	if (ac != 1)
		return (EXIT_FAILURE);
	init_minishell();
	while (1)
		minishell();
	return (0);
}

void	minishell(void)
{
	t_command	*command;
	char		*str;

	str = readline("\033[0;36mminishell \033[0;33m✗\033[0m ");
	if (ft_strcmp(str, "exit") == 0)
	{
		free(str);
		destroy_garbage(NULL);
		exit(ft_atoi(str + 4));
	}
	add_history(str);
	command = parse(str);
	if (command == NULL)
		return (free(str));
	print_AST(command);
	free(str);
}

int	init_minishell(void)
{
	ft_malloc(0);
	init_aliases();
	init_error_log();
	return (EXIT_SUCCESS);
}
