#!/bin/sh

#cc -Wall -Wextra -Werror -o rush-01 *.c
cc -Wall -Wextra -Werror -fsanitize=address,undefined -g3 -o rush-01 *.c
