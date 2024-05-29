#!/bin/zsh
backup_directory() {
  local source_dir=$1
  local backup_dir="${source_dir}_backup_$(date +%Y%m%d_%H%M%S)"
  if [[ -d "$source_dir" ]]; then
    cp -a "$source_dir" "$backup_dir"
    echo "Backup of '$source_dir' created at '$backup_dir'"
  else
    echo "Error: Source directory '$source_dir' does not exist."
    return 1
  fi
}
backup_directory "/path/to/your/directory"
