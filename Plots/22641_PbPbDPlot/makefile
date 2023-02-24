
default: TestRun

TestRun: Execute
	./Execute
	cp *pdf ~/WindowsHome/Downloads/

Execute: MakePlot.cpp
	CompileRootMacro MakePlot.cpp Execute
