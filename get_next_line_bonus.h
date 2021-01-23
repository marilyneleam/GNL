/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleam <mleam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:34:57 by mleam             #+#    #+#             */
/*   Updated: 2021/01/23 16:18:13 by mleam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define OPEN_MAX 4096

# include <unistd.h>
# include <stdlib.h>

int		back_line(char *str);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		get_next_line(int fd, char **line);

#endif
