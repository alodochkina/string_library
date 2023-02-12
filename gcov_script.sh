#!/bin/bash

make gcov_report >> report.txt
echo "report.txt"
coverage_lines=$(awk '/lines/' "$report.txt" | awk '{print $2}')
echo "$coverage_lines"
echo"THISISHER"
coverage_functions=$(awk '/functions/' "$report.txt" | awk '{print $2}')
echo "HER"
echo "$coverage_functions"
if [ "$coverage_lines" -gt 80 ] && [ "$coverage_functions" -gt 80 ]
then return 0
else return 1
fi