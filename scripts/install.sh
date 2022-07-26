#!/usr/bin/env bash

shopt -s expand_aliases

ROOT_PATH=$(dirname $(realpath $(dirname $0)))

alias bpm=$ROOT_PATH/packages/cli/bpm

# Install bash modules
bpm install log color

# Install node modules
npm i

npx --no-install husky install
