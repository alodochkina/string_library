#!/bin/bash

make style >> test_style
cat ./test_style
if [ -n "$(cat ./test_style)" ]
then
  exit 1
  else exit 0
fi
