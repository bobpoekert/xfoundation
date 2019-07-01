#!/bin/bash

clang -o $OUT_FILENAME -L`ocamlopt -where` -lunix -lasmrun ./lib/*.o ./lib/*/*.o ../generic/lib/*.o $@

