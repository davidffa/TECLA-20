#!/bin/sh

if [ -z "$1" ]; then
  echo "Uso: $0 <Letra do exercício>"
  exit 1
fi

set -xe

CC=g++
CFLAGS="-Wall -Wextra -Wshadow -pedantic -std=c++14"

cd $1 && $CC $CFLAGS -o $1 $1.cpp && ./$1 && cd ..