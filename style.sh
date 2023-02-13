#!/bin/bash

make style >> test_style
cat ./test_style
if [ -n "$(cat ./test_style)" ]
then
  exit 0
  else exit 1
fi
