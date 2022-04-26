# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vector_test.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 21:13:33 by tsantoni          #+#    #+#              #
#    Updated: 2021/06/27 13:13:36 by tsantoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/bash

CONTAINER=$1

C_RED='\033[0;31m'
C_GREEN='\033[0;32m'
C_RES='\033[0m'

if [[ "vector" == $CONTAINER ]]; then
	CONTAINER_VAR=("VECTOR")
fi
if [[ "map" == $CONTAINER ]]; then
	CONTAINER_VAR=("MAP")
fi
if [[ "stack" == $CONTAINER ]]; then
	CONTAINER_VAR=("STACK")
fi
if [[ "" == $CONTAINER ]]; then
	CONTAINER_VAR=("ALL")
fi

clang++ -std=c++98 main.cpp -D NSPACE=0 -D VAR_${CONTAINER_VAR}=1 && ./a.out > main_ft ;
clang++ -std=c++98 main.cpp -D NSPACE=1 -D VAR_${CONTAINER_VAR}=1 && ./a.out > main_std ;
DIFF=$(diff main_ft main_std)
if [ "$DIFF" != "" ]
	then
	  echo -e "main.cpp ($CONTAINER) :${C_RED} KO ${C_RES}"
	else
		echo -e "main.cpp ($CONTAINER) :${C_GREEN} OK ${C_RES}"
fi
