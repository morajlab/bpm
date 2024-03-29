#!/usr/bin/env bash

META_FILE_PATH="/tmp/bpm_mock_server_meta"
SILENT=1
PORT=8000
TMP_PATH=
LOG_FILE_PATH=

# Private functions
__get_meta_value() {
  if [ ! -f "$META_FILE_PATH" ]; then
    echo 1
    exit 1
  fi

  while IFS= read -r line; do
    local key=$(echo $line | cut -d '=' -f 1)
    local value=$(echo $line | cut -d '=' -f 2)

    if [ "$1" == "$key" ]; then
      echo "$value"
    fi
  done < <(cat $META_FILE_PATH)
}

# Public functions
start() {
  local local_package=

  while [ "$#" -gt 0 ]; do
    case "${1^^}" in
      "--LOCAL-PACKAGES" | "-LP")
        if [ ! -d "$2" ]; then
          echo ">> ERROR  :: path '$2' doesn't exist."
          exit 1
        fi

        local_package="$2"

        shift
        shift
      ;;
      *)
        shift
      ;;
    esac
  done

  TMP_PATH=$(mktemp -d)
  cat <<- EOF > $META_FILE_PATH
TMP_PATH=$TMP_PATH
PORT=$PORT
EOF
  local _serve_command="python3 -m http.server -d $TMP_PATH/packages $PORT"
  local _clone_command="git clone https://github.com/morajlab/bash-scripts.git $TMP_PATH"

  if [ ! -z "$local_package" ]; then
    _clone_command="cp -rf $local_package $TMP_PATH"
  fi

  if [ "$SILENT" == "0" ]; then
    LOG_FILE_PATH=$(mktemp)

    echo "LOG_FILE_PATH=$LOG_FILE_PATH" >> $META_FILE_PATH
    _clone_command="$_clone_command >> $LOG_FILE_PATH 2>&1"
    _serve_command="$_serve_command >> $LOG_FILE_PATH 2>&1 &"
  fi

  eval "$_clone_command"
  eval "$_serve_command"

  if [ "$SILENT" == "0" ]; then
    echo "PID=$!" >> $META_FILE_PATH
    echo "HTTP server started at http://0.0.0.0:$PORT"
  fi
}

stop() {
  local pid=$(__get_meta_value PID)
  local _TMP_PATH=
  local exit_code=0

  if [ "$pid" == "1" ]; then
    pid=
    _TMP_PATH=1
  fi

  if [ ! -z "$pid" ]; then
    ps -q $pid -o comm= &> /dev/null

    if [ "$?" != "0" ]; then
      pid=
    fi
  fi

  if [ -z "$pid" ]; then
    exit_code=1
  else
    kill $pid
  fi

  if [ -z "$_TMP_PATH" ]; then
    _TMP_PATH=$(__get_meta_value TMP_PATH)
    rm -rf $_TMP_PATH
  fi

  if [ "$exit_code" != "0" ]; then
    echo ">> ERROR  :: server already stopped."
    exit $exit_code
  else
    echo "HTTP server stopped."
  fi
}

status() {
  local pid=$(__get_meta_value PID)
  local status="running"

  if [ "$pid" == "1" ]; then
    echo ">> ERROR  :: server meta file doesn't exist."
    exit 1
  fi

  if [ ! -z "$pid" ]; then
    ps -q $pid -o comm= &> /dev/null

    if [ "$?" != "0" ]; then
      pid=
    fi
  fi

  if [ -z "$pid" ]; then
    status="stopped"
  fi

  local _TMP_PATH=$(__get_meta_value TMP_PATH)
  local _PORT=$(__get_meta_value PORT)

  echo "0.0.0.0|$_PORT|$_TMP_PATH|$status" | \
    column -t -s '|' \-N 'Host,Port,Root,Status' \
    -T 'Root' -W 'Root' -o ' | '
}

log() {
  local log_file_path=$(__get_meta_value LOG_FILE_PATH)

  if [ "$log_file_path" == "1" ]; then
    echo ">> ERROR  :: server meta file doesn't exist."
    exit 1
  fi

  cat $log_file_path
}

if [[ $1 = __* ]] || [ "$(type -t $1)" != 'function' ]; then
  echo ">> ERROR  :: argument '$1' is invalid."
  exit 1
fi

FUNC_NAME=$1

shift

args=()

while [ "$#" -gt 0 ]; do
  case "${1^^}" in
    "--PORT" | "-P")
      PORT=$2

      shift
      shift
    ;;
    "--SILENT" | "-S")
      SILENT=0

      shift
    ;;
    *)
      args+=("$1")

      shift
    ;;
  esac
done

$FUNC_NAME "${args[@]}"
