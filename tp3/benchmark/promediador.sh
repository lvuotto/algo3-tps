#!/bin/bash

for dat in *.dat; do
  echo $dat
  ./promediador.rb < $dat > "$dat.promedio"
done
