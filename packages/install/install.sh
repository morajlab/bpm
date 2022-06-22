#!/usr/bin/env bash

ROOT_PATH=$HOME/.bpm

if ! command -v bpm &>/dev/null; then
  cd $(mktemp -d)
  curl -#LO https://github.com/morajlab/bpm/releases/download/v0.0.1-alpha.3/bpm-v0.0.1-alpha.3.zip
  unzip bpm-v0.0.1-alpha.3.zip
  mkdir $ROOT_PATH
  mv bpm $ROOT_PATH/

  echo 'bpm installed successfully !'
else
  echo 'bpm is installed allready !'
fi
