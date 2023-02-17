#!/bin/bash

test_output=$(make style)
echo "$test_output"
IFS=$'\n'
for value in $test_output
do
  output=$value
  done
if [ -z "$output" ]
then
  exit 0
else exit 1
fi
