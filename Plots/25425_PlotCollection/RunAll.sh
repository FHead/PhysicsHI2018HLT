#!/bin/bash

for i in Individual/*csv
do
   echo "Running $i"
   ./Execute --Input $i --Output ${i/.csv/.root} --Name `basename ${i/.csv/}`
done

for i in IndividualHistogram/*csv
do
   echo "Running $i"
   ./ExecuteHistogram --Input $i --Output ${i/.csv/.root} --Name `basename ${i/.csv/}`
done

hadd -f Combined.root Individual/*root IndividualHistogram/*root
