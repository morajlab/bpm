#!/usr/bin/env bash

INSTALL_PATH=$HOME/.bpm

is_installed() {
  if command -v bpm &> /dev/null; then
    exit 0
  fi

  if [ -d "$INSTALL_PATH" ]; then
    exit 0
  fi

  exit 1
}

install() {
  local TMP_PATH=$(mktemp -d)

  cd $TMP_PATH
  curl -#LO https://github.com/morajlab/bpm/releases/download/v0.0.1-alpha.4/bpm-v0.0.1-alpha.5.zip
  unzip bpm-v0.0.1-alpha.4.zip
  mkdir -p $INSTALL_PATH
  cp -r bpm $INSTALL_PATH/
  rm -rf $TMP_PATH
  cat <<- EOF >> $HOME/.bashrc

# bpm
export PATH=\$PATH:$INSTALL_PATH
EOF
}

if $(is_installed); then
  echo ">>> INFO   :: bpm already installed."
else
  (install) && \
  echo ">>> SUCCESS:: bpm installed."
fi
