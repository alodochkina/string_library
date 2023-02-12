#!/bin/bash

report=$(make gcov_report)
echo "$report"
coverage_lines=$(awk '/lines:/' "$report" | awk '{print $2}')
echo "$coverage_lines"
coverage_functions=$(awk '/functions:/' "$report" | awk '{print $2}')
echo "$coverage_functions"
if [ "$coverage_lines" -gt 80 ] && [ "$coverage_functions" -gt 80 ]
then return 0
else return 1
fi