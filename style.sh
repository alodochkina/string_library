#!/bin/bash

make style >> value
#cat ./value
if [ -z "$value" ]
then
  exit 0
else exit 1
fi
