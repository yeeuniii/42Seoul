/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:10:38 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/16 18:48:40 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h> //memset
# include <sys/time.h>
# include <pthread.h>
# include "data.h"

typedef struct s_philosopher
{
	struct s_data	data;
	pthread_t		thread;
	int				number;
	int				last_time_to_eat;

}	t_philosopher;

typedef struct s_table
{
	struct s_data			data;
	struct s_philosopher	*philos;
	struct s_monitor		monitor;
	pthread_mutex_t			*forks_mutex;
	int						*forks;
}	t_philosopher;

#endif
