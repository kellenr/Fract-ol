/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:12:38 by keramos-          #+#    #+#             */
/*   Updated: 2024/05/20 14:03:36 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Julia options.
	give some initialization number, so you can try diferents julias  */
void	julia_opt(void)
{
	ft_printf(P_P \
	"\n\n\t             🌸 Julia options  \n" RT \
	"🐾\t   Some options for a nice Juial Fractol could be\n" \
	"🐾\t           " P_M" ./fractol j 0.285 0.01\n" \
	"🐾\t            ./fractol j -0.8 0.156 \n" \
	"🐾\t            ./fractol j -0.4 0.6 \n" \
	"🐾\t            ./fractol j -0.75 0.11 \n" \
	"🐾\t            ./fractol j 0.37 -0.1\n" \
	"🐾\t            ./fractol j -0.70167 -0.3842\n" \
	"🐾\t            ./fractol j -0.835 -0.2321\n\n" RT);
}
