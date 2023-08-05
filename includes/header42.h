/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:08:08 by nsainton          #+#    #+#             */
/*   Updated: 2023/08/05 11:17:04 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER42_H
# define HEADER42_H
/*
	In last vim command. set binary is to enable binary mode (to allow the
	command noeol to work). set noeol is to prevent vim from adding a newline
	to the end of file (which would mess with the norm after because we need
	to continue writing the prototypes).
	However, here is recalled the definition of the line in the POSIX
	standard :
	"3.206 Line
	A sequence of zero or more non- <newline> characters plus a terminating
	<newline> character"
	So don't get tempted to add it in your vimrc, because it could mess with
	some over projects you're building after.
*/
# define HEADER_SCRIPT "#!/bin/sh\n" \
						"plugin_dir=\"$HOME/.vim/plugin\"\n" \
						"plugin_name=\"stdheader.vim\"\n" \
						"plugin_path=\"$plugin_dir/$plugin_name\"\n" \
						"refused_install=\"/tmp/.no_plugin_install_42dynamicheader\"\n" \
						"filename=\"$1\"\n" \
						"vim_path=\"$(whereis vim | "\
						"awk -F ':' '{print $2}')\"\n\n" \
						"install_script() {\n" \
						"\tif [ -f $refused_install ]\n" \
						"\tthen\n" \
						"\t\techo $refused_install found\n" \
						"\t\techo No script will be installed\n" \
						"\t\texit 5\n" \
						"\tfi\n" \
						"\techo \"No stdheader plugin found\"\n" \
						"\techo -n \"Would you like to install stdheader.vim plugin ? [y/n]\"\n" \
						"\tread -n1 reply\n" \
						"\tuntil [[ $reply = [yYnN] ]]\n" \
						"\tdo\n" \
						"\t\techo \"Unrecognized character, try again\"\n" \
						"\t\techo -n \"Would you like to install stdheader.vim plugin ? [y/n]\"\n" \
						"\t\tread -n1 reply\n" \
						"\tdone\n" \
						"\tcase \"$reply\" in\n" \
						"\t[yY] )\n" \
						"\t\techo \"Script will be installed at $plugin_path\" ;;\n" \
						"\t[nN] )\n" \
						"\t\tcat <<-NO_INSTALL\n" \
						"\t\tNo script will be installed\n" \
						"\t\tIf you wish to change your choice you can either install it \n" \
						"yourself or remove the file $refused_install\n" \
						"\t\tNO_INSTALL\n" \
						"\t\ttouch $refused_install\n" \
						"\t\texit 5 ;;\n" \
						"\tesac\n" \
						"}\n\n" \
						"if [ \"$vim_path\" = \"\" ]\n" \
						"then\n" \
						"\tcat <<-VIM\n" \
						"\t\tvim command is not installed, you need vim to " \
						"use the dynamic header\n" \
						"\t\tyou can install vim by running : \\`sudo apt " \
						"install vim\\`\n" \
						"\t\tVIM\n" \
						"\texit 3\n" \
						"fi\n\n" \
						"if [ ! -f $plugin_path ]\n" \
						"then\n" \
						"\tinstall_script\n" \
						"\tmkdir -p $plugin_dir\n" \
						"\tif [ $(( $? )) -ne 0 ]\n" \
						"\tthen\n" \
						"\t\texit 4\n" \
						"\tfi\n" \
						"\tcurl -fsSL https://raw.githubusercontent.com/" \
						"42Paris/42header/master/plugin/stdheader.vim -o \"" \
						"$plugin_path\"\n" \
						"\tif [ ! -f $plugin_path ]\n" \
						"\tthen\n" \
						"\t\techo \"Couldn't get plugin file\"\n" \
						"\t\texit 1\n" \
						"\telse\n" \
						"\t\tcat <<-INSTRUCTIONS\n" \
						"\t\t\t$plugin_name installed at $plugin_path\n" \
						"\t\t\tDon't forget to add lines :\n" \
						"\t\t\tlet g:user42 = your_username\n" \
						"\t\t\tlet g:mail42 = your_email\n" \
						"\t\t\tto your $HOME/.vimrc file if not already done" \
						" or to create one \\\n" \
						"with those two lines if you don't use vim\n" \
						"\t\t\tINSTRUCTIONS\n" \
						"\tfi\n" \
						"fi\n\n" \
						"if [ \"$filename\" = \"\" ]\n" \
						"then\n" \
						"\techo \"No filename provided\"\n" \
						"\texit 2\n" \
						"fi\n\n" \
						"vim \"+set binary\" \"+set noeol\" \"+Stdheader\" " \
						"\"+wq\" $filename\n" \
						"exit 0\n"
#endif
