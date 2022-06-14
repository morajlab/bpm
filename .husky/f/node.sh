#!/bin/sh

root_path=$(realpath $(dirname $(dirname $(dirname "$0"))))

if [ "$MJL_MONOREPO" = "1" ]; then
  current_path=$(pwd)
  is_root=false

  while ! $is_root; do
    if [ $current_path = / ]; then
      echo 'ERROR:: This repository is not in a monorepo workspace.'
      echo "Please don't set 'MJL_MONOREPO' environment variable."
      exit 1
    fi

    if [ -f "$current_path/.mjlroot" ]; then
      root_path="$current_path"
      is_root=true
    fi

    current_path=$(dirname $current_path)
  done
fi

node_path=$root_path/node_modules

if [ ! -d $node_path ]; then
  echo "ERROR:: path '$node_path' doesn't exist."
  exit 1
fi
