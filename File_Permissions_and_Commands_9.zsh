#!/bin/zsh
for file in *.txt(.); do
  newname="${file%.txt}.bak"
  echo "Renaming $file to $newname"
  mv "$file" "$newname"
done

echo "All .txt files have been renamed to .bak."
