

default: RunAll

RunAll: Execute ExecuteHistogram
	bash RunAll.sh

TestRun: Execute
	./Execute --Input pA8TeV_HM_L1_115120.csv --Output pA8TeV_HM_L1_115120.root --Name pA8TeV_HM_L1_115120
	./Execute --Input pA8TeV_HM_L1_145150.csv --Output pA8TeV_HM_L1_145150.root --Name pA8TeV_HM_L1_145150

Execute: CSVToPlot.cpp
	CompileRootMacro CSVToPlot.cpp Execute

ExecuteHistogram: CSVToHistogram.cpp
	CompileRootMacro CSVToHistogram.cpp ExecuteHistogram

ExecuteHistogramToCSV: HistogramToCSV.cpp
	CompileRootMacro HistogramToCSV.cpp ExecuteHistogramToCSV

ConvertMuonSpectra: ExecuteHistogramToCSV
	./ExecuteHistogramToCSV --Input Original/Yellow2015.root --Hist L1DoubleMuon --Output IndividualHistogram/PbPb5TeV_2015_L1DoubleMu_O.csv
	./ExecuteHistogramToCSV --Input Original/Yellow2018.root --Hist L1DoubleMuon --Output IndividualHistogram/PbPb5TeV_2018_L1DoubleMu_O.csv
	./ExecuteHistogramToCSV --Input Original/Yellow2018.root --Hist JPsi         --Output IndividualHistogram/PbPb5TeV_2018_JPsi_O.csv
	./ExecuteHistogramToCSV --Input Original/Yellow2018.root --Hist UpsilonZ     --Output IndividualHistogram/PbPb5TeV_2018_UpsilonZ_O.csv

Temp:
	bash Append.sh X1 Y1 EXL1 EXH1 EYL1 EYH1 Individual/pPb8TeV_HM_L1_115120_O.csv
	bash Append.sh X2 Y2 EXL2 EXH2 EYL2 EYH2 Individual/pPb8TeV_HM_L1_145150_O.csv
