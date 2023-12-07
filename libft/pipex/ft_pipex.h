/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/13 01:49:27 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "../libft.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef enum e_execve_error
{
	EXCV_NO_ERROR,
	EXCV_CMD_ERROR,
	EXCV_FORK_ERROR,
	EXCV_OTHER_ERROR
}	t_execve_error;

typedef struct s_pipe
{
	int	in[2];
	int	out[2];
}	t_pipe;

typedef struct s_exec
{
	char	*cmd_path;
	char	**argv;
	char	**envp;
}	t_exec;

#endif
