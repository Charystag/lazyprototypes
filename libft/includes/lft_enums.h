/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_enums.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:35:26 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/01 05:36:44 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_ENUMS_H
# define LFT_ENUMS_H

typedef enum e_pflags
{
	SHARP = 1 << 0,
	SPACE = 1 << 1,
	PLUS = 1 << 2,
	DASH = 1 << 3,
	ZERO = 1 << 4,
	DOT = 1 << 5
}				t_pflags;

#endif
