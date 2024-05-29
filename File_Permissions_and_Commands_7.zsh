#!/bin/zsh

for file in *.tmp(.); do
  echo "Deleting $file"
  rm "$file"
done
echo "All .tmp files have been deleted."
