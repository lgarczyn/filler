/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_colors.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 17:03:14 by lgarczyn          #+#    #+#             */
/*   Updated: 2016/09/03 17:03:17 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TCOLORS_H
# define _TCOLORS_H

# define T_NONE					"\e[0m"

# define TCO_DEFAULT			"\e[39m"
# define TCO_BLACK				"\e[30m"
# define TCO_RED				"\e[31m"
# define TCO_GREEN				"\e[32m"
# define TCO_YELLOW				"\e[33m"
# define TCO_BLUE				"\e[34m"
# define TCO_MAGENTA			"\e[35m"
# define TCO_CYAN				"\e[36m"
# define TCO_LIGHT_GRAY			"\e[37m"
# define TCO_DARK_GRAY			"\e[90m"
# define TCO_LIGHT_RED			"\e[91m"
# define TCO_LIGHT_GREEN		"\e[92m"
# define TCO_LIGHT_YELLOW		"\e[93m"
# define TCO_LIGHT_BLUE			"\e[94m"
# define TCO_LIGHT_MAGENTA		"\e[95m"
# define TCO_LIGHT_CYAN			"\e[96m"
# define TCO_WHITE				"\e[97m"

# define TBG_DEFAULT			"\e[49m"
# define TBG_BLACK				"\e[40m"
# define TBG_RED				"\e[41m"
# define TBG_GREEN				"\e[42m"
# define TBG_YELLOW				"\e[43m"
# define TBG_BLUE				"\e[44m"
# define TBG_MAGENTA			"\e[45m"
# define TBG_CYAN				"\e[46m"
# define TBG_LIGHT_GRAY			"\e[47m"
# define TBG_DARK_GRAY			"\e[100m"
# define TBG_LIGHT_RED			"\e[101m"
# define TBG_LIGHT_GREEN		"\e[102m"
# define TBG_LIGHT_YELLOW		"\e[103m"
# define TBG_LIGHT_BLUE			"\e[104m"
# define TBG_LIGHT_MAGENTA		"\e[105m"
# define TBG_LIGHT_CYAN			"\e[106m"
# define TBG_WHITE				"\e[107m"

# define S_DEFAULT(S)			(TCO_DEFAULT S T_NONE)
# define S_BLACK(S)				(TCO_BLACK S T_NONE)
# define S_RED(S)				(TCO_RED S T_NONE)
# define S_GREEN(S)				(TCO_GREEN S T_NONE)
# define S_YELLOW(S)			(TCO_YELLOW S T_NONE)
# define S_BLUE(S)				(TCO_BLUE S T_NONE)
# define S_MAGENTA(S)			(TCO_MAGENTA S T_NONE)
# define S_CYAN(S)				(TCO_CYAN S T_NONE)
# define S_LIGHT_GRAY(S)		(TCO_LIGHT_GRAY S T_NONE)
# define S_DARK_GRAY(S)			(TCO_DARK_GRAY S T_NONE)
# define S_LIGHT_RED(S)			(TCO_LIGHT_RED S T_NONE)
# define S_LIGHT_GREEN(S)		(TCO_LIGHT_GREEN S T_NONE)
# define S_LIGHT_YELLOW(S)		(TCO_LIGHT_YELLOW S T_NONE)
# define S_LIGHT_BLUE(S)		(TCO_LIGHT_BLUE S T_NONE)
# define S_LIGHT_MAGENTA(S)		(TCO_LIGHT_MAGENTA S T_NONE)
# define S_LIGHT_CYAN(S)		(TCO_LIGHT_CYAN S T_NONE)
# define S_WHITE(S)				(TCO_WHITE S T_NONE)

# define B_DEFAULT(S)			(TBG_DEFAULT S T_NONE)
# define B_BLACK(S)				(TBG_BLACK S T_NONE)
# define B_RED(S)				(TBG_RED S T_NONE)
# define B_GREEN(S)				(TBG_GREEN S T_NONE)
# define B_YELLOW(S)			(TBG_YELLOW S T_NONE)
# define B_BLUE(S)				(TBG_BLUE S T_NONE)
# define B_MAGENTA(S)			(TBG_MAGENTA S T_NONE)
# define B_CYAN(S)				(TBG_CYAN S T_NONE)
# define B_LIGHT_GRAY(S)		(TBG_LIGHT_GRAY S T_NONE)
# define B_DARK_GRAY(S)			(TBG_DARK_GRAY S T_NONE)
# define B_LIGHT_RED(S)			(TBG_LIGHT_RED S T_NONE)
# define B_LIGHT_GREEN(S)		(TBG_LIGHT_GREEN S T_NONE)
# define B_LIGHT_YELLOW(S)		(TBG_LIGHT_YELLOW S T_NONE)
# define B_LIGHT_BLUE(S)		(TBG_LIGHT_BLUE S T_NONE)
# define B_LIGHT_MAGENTA(S)		(TBG_LIGHT_MAGENTA S T_NONE)
# define B_LIGHT_CYAN(S)		(TBG_LIGHT_CYAN S T_NONE)
# define B_WHITE(S)				(TBG_WHITE S T_NONE)

#endif
