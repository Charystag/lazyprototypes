#!/bin/bash
plugin_dir="$HOME/.vim/plugin"
plugin_name="stdheader.vim"
plugin_path="$plugin_dir"/"$plugin_name"
refused_install="/tmp/.no_plugin_install_42dynamicheader"

install_script() {
	if [ -f $refused_install ]
	then
		echo $refused_install found
		echo No script will be installed
		exit 5
	fi
	echo "No stdheader plugin found"
	echo -n "Would you like to install stdheader.vim plugin ? [y/n]"
	read -n1 reply
	until [[ $reply = [yYnN] ]]
	do
		echo "Unrecognized character, try again"
		echo -n "Would you like to install stdheader.vim plugin ? [y/n]"
		read -n1 reply
	done
	case "$reply" in
	[yY] )
		echo "Script will be installed at $plugin_path" ;;
	[nN] )
		cat <<-NO_INSTALL
		No script will be installed
		If you wish to change your choice you can either install it 
yourself or remove the file $refused_install
		NO_INSTALL
		touch $refused_install
		exit 5 ;;
	esac
}

if [ ! -f $plugin_path ]
then
	install_script
fi
