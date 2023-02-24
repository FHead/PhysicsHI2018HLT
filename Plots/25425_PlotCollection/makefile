

default: RunAll

RunAll: Execute
	bash RunAll.sh

TestRun: Execute
	./Execute --Input pA8TeV_HM_L1_115120.csv --Output pA8TeV_HM_L1_115120.root --Name pA8TeV_HM_L1_115120
	./Execute --Input pA8TeV_HM_L1_145150.csv --Output pA8TeV_HM_L1_145150.root --Name pA8TeV_HM_L1_145150

Execute: CSVToPlot.cpp
	CompileRootMacro CSVToPlot.cpp Execute
