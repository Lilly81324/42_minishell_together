/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:01:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/03 23:01:19 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_child(pid_t pid, int sleeptime, int exit_code, char *str)
{
	if (pid != 0)
		return ;
	sleep(sleeptime);
	free(str);
	exit (exit_code);
}

int	sex_with_rina(void)
{
	pid_t	pid;
	pid_t	died;
	int		status;
	int		count;
	int		exit_code;
	char	*str;

	str = (char *)malloc(3*sizeof(char));
	str[0] = 'A';
	str[1] = 'B';
	str[2] = '\0';
	status = 0;
	count = -1;
	// Make first child
	pid = fork();
	if (pid == 0)
		st_child(pid, 1, 1, str);
	printf("Pid:%i\n", pid);
	// Make second child
	pid = fork();
	if (pid == 0)
		st_child(pid, 3, 2, str);
	printf("Pid:%i\n", pid);
	// Make third and last child, the chosen one
	pid = fork();
	if (pid == 0)
		st_child(pid, 2, 3, str);
	printf("Pid:%i\n", pid);
	// Wait until all created children have terminated
	while (++count < 3)
	{
		died = waitpid(-1, &status, 0);
		printf("Died: %i\n", died);
	 // If the process that just terminated has the same pid as the last created child:
		if (died == pid)
			exit_code = WEXITSTATUS(status);
	}
	printf("Exit Code of last process: %i\n", exit_code);
	printf("%s\n", str);
	free(str);
	return (exit_code);
}

int	main(void)
{
	sex_with_rina();
	return (0);
}

// fork process and remember pid
// in process do whatever and then exit with exit code
// in parent loop waitpid