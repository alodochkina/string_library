#!/bin/bash

make style > output
cat ./output
if [ -z "$(cat ./output)" ]
then
  exit 0
else exit 1
fi
