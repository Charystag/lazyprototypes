# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 11:32:59 by nsainton          #+#    #+#              #
#    Updated: 2023/05/08 17:13:56 by nsainton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= header

PROG:= $(NAME).c

SRCS_DIR:= sources

SRCS_SUBDIRS:= $(shell find $(SRCS_DIR) -type d)

SRCS_NAMES:= $(subst $(SRCS_DIR)/,, $(foreach dir, $(SRCS_SUBDIRS), $(wildcard $(dir)/*.c)))

SRCS:= $(addprefix $(SRCS_DIR)/, $(SRCS_NAMES))

INCS_DIR:= includes

OBJS_DIR:= objects

OBJS_NAMES:= $(SRCS_NAMES:.c=.o)

OBJS:= $(addprefix $(OBJS_DIR)/, $(OBJS_NAMES))

DEPS_DIR:= dependencies

DEPS:= $(patsubst %.c, $(DEPS_DIR)/%.d, $(SRCS_NAMES) $(PROG))

CC= cc

CFLAGS= -Wall -Wextra -Werror

GITADD= --all

LIBS := libs

LIBS_DIR ?= $(addprefix $(shell pwd)/, $(LIBS))

LFT_DIR:= $(LIBS_DIR)/libft

LFT_URL:= "git@github.com:nsainton/libft.git"

ARCHITECTURE= $(shell uname)

export LIBS_DIR
export C_INCLUDE_PATH= $(INCS_DIR):$(LFT_DIR)/$(INCS_DIR)
export LIBRARY_PATH= $(LFT_DIR)

#Color codes for pretty printing
BEGIN=\033[
BLACK=30
RED=31
GREEN=32
BROWN=33
BLUE=34
PURPLE=35
CYAN=36
NORMAL=0
BOLD=1
UNDERLINED=4
BLINKING=5
REVERSE=7
END=\033[0m

#Here is the definition of an ascii code
#double backslash at the end of lines to ensure that it is not interpreted
#as line continuation. One could also have added a space after the backslash
#The export directive makes the header available to each submake
#Font used is Isometric1
define header_header
 __     __     ______     __     ______   ______      
/\ \  _ \ \   /\  == \   /\ \   /\__  _\ /\  ___\     
\ \ \/ ".\ \  \ \  __<   \ \ \  \/_/\ \/ \ \  __\     
 \ \__/".~\_\  \ \_\ \_\  \ \_\    \ \_\  \ \_____\   
  \/_/   \/_/   \/_/ /_/   \/_/     \/_/   \/_____/   
                                                      
 ______   __  __     ______     __    __              
/\__  _\ /\ \_\ \   /\  ___\   /\ "-./  \             
\/_/\ \/ \ \  __ \  \ \  __\   \ \ \-./\ \            
   \ \_\  \ \_\ \_\  \ \_____\  \ \_\ \ \_\           
    \/_/   \/_/\/_/   \/_____/   \/_/  \/_/           
                                                      
 ______   __  __     __   __     ______     ______    
/\  ___\ /\ \/\ \   /\ "-.\ \   /\  ___\   /\  ___\   
\ \  __\ \ \ \_\ \  \ \ \-.  \  \ \ \____  \ \___  \  
 \ \_\    \ \_____\  \ \_\\"\_\   \ \_____\  \/\_____\ 
  \/_/     \/_____/   \/_/ \/_/   \/_____/   \/_____/ 
                                                      
endef
export header_header

.PHONY: all

.SILENT:

.DEFAULT_GOAL := all

makedebug:
	@echo $(DEPS)

all: | $(LFT_DIR)
	$(MAKE) -C $(LFT_DIR)
	$(MAKE) $(NAME)
	echo "$(BEGIN)$(CYAN)m"
	echo "$$header_header"
	echo "$(END)"

$(NAME): $(OBJS) | $(DEPS_DIR)
	$(CC) $(CFLAGS) $(OPT) $(GG) $(OBJS) $(PROG) -MD -MF $(DEPS_DIR)/$(PROG:.c=.d) -lft -o $(NAME)

$(DEPS_DIR):
	mkdir $(DEPS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c Makefile
	[ -d $(@D) ] || mkdir -p $(@D)
	arg="$$(dirname $(DEPS_DIR)/$*)"; \
	[ -d $$arg ] || mkdir -p $$arg
	$(CC) $(CFLAGS) $(OPT) $(GG) -MD -MF $(DEPS_DIR)/$*.d -c $< -o $@

$(LFT_DIR):
	git clone $(LFT_URL) $(LFT_DIR)
.PHONY: clean
clean:
	$(RM) -r $(DEPS_DIR)
	$(RM) -r $(OBJS_DIR)
	[ "$(ARCHITECTURE)" = "Darwin" ] && $(RM) -r *.dSYM || true

.PHONY: oclean
oclean:
	$(RM) $(NAME)

.PHONY: lclean
lclean:
	$(RM) -r $(LIBS_DIR)

.PHONY: fclean
fclean:
	$(MAKE) clean
	$(MAKE) oclean
	$(MAKE) lclean

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: debug
debug:
	$(MAKE) fclean
	$(MAKE) CC=gcc GG=-g3 OPT=-O0

.PHONY: git
git:
	git add $(GITADD)
	git commit
	git push

-include $(DEPS)
