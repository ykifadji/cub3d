/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 07:46:30 by ykifadji          #+#    #+#             */
/*   Updated: 2024/03/14 11:56:31 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (ft_strlen(s) < (int)start)
		return (0);
	if ((int)len <= ft_strlen(s))
		str = malloc(sizeof(char) * (len + 1));
	else
		str = malloc(sizeof(char) * (ft_strlen(s) - start));
	if (!str)
		return (0);
	while (s[start] && (int)start < ft_strlen(s) && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
