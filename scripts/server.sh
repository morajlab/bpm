#!/usr/bin/env bash

TMP_PATH=$(mktemp -d)
PORT=8000

while [ "$#" -gt 0 ]; do
  case "${1^^}" in
    "--PORT" | "-P")
      PORT=$2

      shift
      shift
    ;;
    *)
      shift
    ;;
  esac
done

download_bash_modules() {
  git clone https://github.com/morajlab/bash-scripts.git $TMP_PATH 1> /dev/null
}

serve() {
  python3 -m http.server -d $TMP_PATH/packages $PORT
}

download_bash_modules
serve
