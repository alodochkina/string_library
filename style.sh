#!/bin/bash

value=$(make style)
#echo "$value"
if [ -z "$value" ]
then
  exit 0
else exit 1
fi
