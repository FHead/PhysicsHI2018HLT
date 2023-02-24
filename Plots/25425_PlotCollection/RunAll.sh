#!/bin/bash

for i in Individual/*csv
do
   echo "Running $i"
   ./Execute --Input $i --Output ${i/.csv/.root} --Name `basename ${i/.csv/}`
done

hadd -f Combined.root Individual/*root
