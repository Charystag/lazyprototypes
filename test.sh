#!/bin/bash
plugin_dir="$HOME/.vim/plugin"
plugin_name="stdheader.vim"
plugin_path="$plugin_dir"/"$plugin_name"
refused_install="/tmp/.no_plugin_install_42dynamicheader"

install_script() {
	if [ -f $refused_install ]
	echo "No stdheader plugin found"
	echo -n "Would you like to install stdheader.vim plugin ? [y/n]"
	read -n1 reply
	until [ "$reply" = [yYnN] ]
	do
		echo "Unrecognized character, try again"
		echo -n "Would you like to install stdheader.vim plugin ? [y/n]"
		read -n1 reply
	done
	case "$reply" in
	[yY] )
		echo "Script will be installed" ;;
	[nN] )
		cat <<-NO_INSTALL
		No script will be installed
		If you wish to change your choise you can either install it 
yourself or remove the file $refused_install
		NO_INSTALL
		touch $refused_install
		exit 5
}

if [! $plugin_path && ! -f $refused_install ]
then
	install_script
fi
