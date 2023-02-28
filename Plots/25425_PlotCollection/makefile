

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

ExecuteGraphToCSV: GraphToCSV.cpp
	CompileRootMacro GraphToCSV.cpp ExecuteGraphToCSV

ConvertMuonSpectra: ExecuteHistogramToCSV
	./ExecuteHistogramToCSV --Input Original/Yellow2015.root --Hist L1DoubleMuon --Output IndividualHistogram/PbPb5TeV_2015_L1DoubleMu_O.csv
	./ExecuteHistogramToCSV --Input Original/Yellow2018.root --Hist L1DoubleMuon --Output IndividualHistogram/PbPb5TeV_2018_L1DoubleMu_O.csv
	./ExecuteHistogramToCSV --Input Original/Yellow2018.root --Hist JPsi         --Output IndividualHistogram/PbPb5TeV_2018_JPsi_O.csv
	./ExecuteHistogramToCSV --Input Original/Yellow2018.root --Hist UpsilonZ     --Output IndividualHistogram/PbPb5TeV_2018_UpsilonZ_O.csv

ConvertMB: ExecuteGraphToCSV
	./ExecuteGraphToCSV --Input Original/MB.root --Graph G4 --Output Individual/PbPb5TeV_MB_L1HLT_4050_O.csv
	./ExecuteGraphToCSV --Input Original/MB.root --Graph G5 --Output Individual/PbPb5TeV_MB_L1HLT_5060_O.csv
	./ExecuteGraphToCSV --Input Original/MB.root --Graph G6 --Output Individual/PbPb5TeV_MB_L1HLT_6070_O.csv
	./ExecuteGraphToCSV --Input Original/MB.root --Graph G7 --Output Individual/PbPb5TeV_MB_L1HLT_7080_O.csv
	./ExecuteGraphToCSV --Input Original/MB.root --Graph G8 --Output Individual/PbPb5TeV_MB_L1HLT_80100_O.csv

Temp:
	bash Append.sh X1 Y1 EXL1 EXH1 EYL1 EYH1 Individual/PbPb5TeV_DoubleMu_L1HLT_0_MC_O.csv
	bash Append.sh X2 Y2 EXL2 EXH2 EYL2 EYH2 Individual/PbPb5TeV_DoubleMu_L1HLT_0_Data_O.csv
	bash Append.sh X3 Y3 EXL3 EXH3 EYL3 EYH3 Individual/PbPb5TeV_DoubleMu_L1HLT_0_Ratio_O.csv
