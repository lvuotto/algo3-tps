#!/bin/bash

BINDIR=../bin/

# Colors
red='\e[0;31m'
green='\e[0;32m'
NC='\e[0m' # No Color

for ej in 1 2 3 ; do
  ERROR=0
  echo "Testeando ejercicio $ej:"
  for test in $(find ./ -maxdepth 1 -name "ej$ej\.test\.*") ; do
    $BINDIR/ej$ej < $test | diff - $(sed s/test/solucion/ <<< $test) > /dev/null
    if [ $? -ne 0 ] ; then
      ERROR=1
      echo -e "\t${red}Error en test $test${NC}"
    fi
  done
  if [ $ERROR -eq 0 ] ; then
    CANT_TESTS=$(find ./ -maxdepth 1 -name "ej$ej\.test\.*" | wc -l)
    echo -e "\t${green}$CANT_TESTS tests ok${NC}"
  else
    echo -e "\t${red}Hay errores${NC}"
  fi
done
