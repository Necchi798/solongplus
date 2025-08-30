/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:45:16 by gmezzini           #+#    #+#            */
/*   Updated: 2022/03/16 15:25:48 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASICS_H
# define BASICS_H

# include "libft/libft.h"

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

#endif