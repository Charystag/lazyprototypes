/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:08:08 by nsainton          #+#    #+#             */
/*   Updated: 2023/08/05 09:02:32 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER42_H
# define HEADER42_H
# define HEADER_SCRIPT "#!/bin/sh\n" \
						"plugin_dir=\"$HOME/.vim/plugin\"\n" \
						"plugin_name=\"stdheader.vim\"\n" \
						"plugin_path=\"$plugin_dir/$plugin_name\"\n" \
						"filename=\"$1\"\n" \
						"vim_path=\"$(whereis vim | "\
						"awk -F ':' '{print $2}')\"\n\n" \
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
						"\tmkdir -p $plugin_dir\n" \
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
						"vim \"+Stdheader\" \"+wq\" $filename\n" \
						"exit 0\n"
#endif
