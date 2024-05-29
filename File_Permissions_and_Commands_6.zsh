#!/bin/zsh
for file in *(.); do
  echo "$file: $(stat -c %s "$file") bytes"
done
