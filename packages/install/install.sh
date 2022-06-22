#!/usr/bin/env bash

ROOT_PATH=$HOME/.bpm

if ! command -v bpm &>/dev/null; then
  cd $(mktemp -d)
  curl -#LO https://github.com/morajlab/bpm/releases/download/v0.0.1-alpha/bpm-v0.0.1-alpha.zip
  unzip bpm-v0.0.1-alpha.zip
  mkdir $ROOT_PATH
  mv bpm $ROOT_PATH/

  echo 'bpm installed successfully !'
else
  echo 'bpm is installed allready !'
fi
