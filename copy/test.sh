#!/bin/bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE="$1" *.c && ./a.out > res && diff res exp