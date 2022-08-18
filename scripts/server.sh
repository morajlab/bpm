#!/usr/bin/env bash

TMP_PATH=$(mktemp -d)
PORT=8000
LOCAL_PACKAGES=

while [ "$#" -gt 0 ]; do
  case "${1^^}" in
    "--PORT" | "-P")
      PORT=$2

      shift
      shift
    ;;
    "--LOCAL-PACKAGES" | "-LP")
      if [ ! -d "$2" ]; then
        echo ">>> ERROR  :: path '$2' doesn't exist."
        exit 1
      fi

      LOCAL_PACKAGES="$2"

      shift
      shift
    ;;
    *)
      shift
    ;;
  esac
done

download_bash_modules() {
  if [ -z "$LOCAL_PACKAGES" ]; then
    git clone https://github.com/morajlab/bash-scripts.git $TMP_PATH
  else
    cp -rf "$LOCAL_PACKAGES" "$TMP_PATH"
  fi
}

serve() {
  python3 -m http.server -d $TMP_PATH/packages $PORT
}

download_bash_modules
serve
