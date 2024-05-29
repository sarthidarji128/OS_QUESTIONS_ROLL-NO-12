#!/bin/zsh

for file in *.log(.); do
  echo "Last 20 lines of $file:"
  tail -n 20 "$file"
  echo "--------------------------"
done
