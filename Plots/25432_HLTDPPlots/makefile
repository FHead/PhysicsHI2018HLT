default: RunAll Deploy

TestRun: Execute
	./Execute \
		--label "MC","Data" \
		--file Combined.root,Combined.root \
		--curve pPb8TeV_L3Mu_L1HLT_12_Eta_MC_O,pPb8TeV_L3Mu_L1HLT_12_Eta_Data_O \
		--title ";#eta;Efficiency" --xmin -2.5 --xmax 2.5 --ymin 0.8 --ymax 1.05 \
		--legendx 0.45 --legendy 0.50 --output Plots/Test.pdf

RunAll: Execute
	bash RunAll.sh

Execute: MakePlot.cpp
	CompileRootMacro MakePlot.cpp Execute

Deploy:
	cp Plots/*pdf ~/WindowsHome/Dropbox/Temp/Meow2/
