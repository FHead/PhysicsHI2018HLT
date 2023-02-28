#!/bin/bash

FileLineAppend $1 $2 Temp1
FileLineAppend Temp1 $3 Temp2
FileLineAppend Temp2 $4 Temp1
FileLineAppend Temp1 $5 Temp2
FileLineAppend Temp2 $6 Temp1

sed "s/[,};]//g" < Temp1 > $7

rm -f Temp1 Temp2
