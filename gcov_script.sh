#!/bin/bash

make gcov_report >> report
cat ./report
coverage_lines=$(awk '/lines/' report | awk '{print $2}')
IFS=%
for coverage in $coverage_lines
do
  coverage_lines=$(printf %.0f $(echo "$coverage" | bc))
done
echo "$coverage_lines"
echo "THISISHER"
coverage_functions=$(awk '/functions/' report | awk '{print $2}')
echo "HER"
echo "$coverage_functions"
if [ "$coverage_lines" -gt 80 ] && [ "$coverage_functions" -gt 80 ]
then return 0
else return 1
fi