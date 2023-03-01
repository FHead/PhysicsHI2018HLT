#!/bin/bash

Qualifier="Preliminary"

# HM L1 plot
./Execute \
	--label "Tower count > 115/120","Tower count > 145/150" \
	--file Combined.root \
	--curve pPb8TeV_HM_L1_115120_O,pPb8TeV_HM_L1_145150_O \
   --hline 1 --vline 185,250 \
   --xtitle "N_{trk}^{offline}" --ytitle "L1 Trigger Efficiency" --xmin 0 --xmax 400 --ymin 0.0 --ymax 1.05 \
   --system "pPb 8.16 TeV" --qualifier $Qualifier \
	--legendx 0.02 --legendy 0.785 --output Plots/pPb8TeV_HM_L1.pdf
	# --legendx 0.60 --legendy 0.05 --output Plots/pPb8TeV_HM_L1.pdf

# HM HLT plot
./Execute \
	--label "N_{ch}^{online} > 120","N_{ch}^{online} > 150","N_{ch}^{online} > 185","N_{ch}^{online} > 250","N_{ch}^{online} > 280" \
	--file Combined.root \
	--curve pPb8TeV_HM_HLT_120_O,pPb8TeV_HM_HLT_150_O,pPb8TeV_HM_HLT_185_O,pPb8TeV_HM_HLT_250_O,pPb8TeV_HM_HLT_280_O \
   --hline 1 --vline 120,150,185,250,280 \
   --xtitle "N_{trk}^{offline}" --ytitle "High-Level Trigger Efficiency" --xmin 0 --xmax 400 --ymin 0.0 --ymax 1.05 \
   --system "pPb 8.16 TeV" --qualifier $Qualifier \
	--legendx 0.025 --legendy 0.525 --output Plots/pPb8TeV_HM_HLT.pdf

# PAL3Mu12 efficiency
./Execute \
   --label "MC Powheg","Data" \
   --file Combined.root \
   --curve pPb8TeV_L3Mu_L1HLT_12_PT_MC_O,pPb8TeV_L3Mu_L1HLT_12_PT_Data_O \
   --xtitle "p_{T}^{#mu} (GeV)" --ytitle "Muon efficiency" --xmin 0 --xmax 200 --ymin 0.87 --ymax 1.00 \
   --system "pPb 8.16 TeV" --qualifier $Qualifier \
   --ratio true --rtitle "Data/MC" --rmin 0.9 --rmax 1.09 --rfile Combined.root --rcurve pPb8TeV_L3Mu_L1HLT_12_PT_Ratio_O \
   --legendx 0.6 --legendy 0.1 --output Plots/pPb8TeV_L3Mu12.pdf \
   --text 0.08,0.12,"|#eta^{#mu}| < 2.4&comma; p_{T}^{#mu} > 15 GeV",0.08,0.20,"HLT_PAL3Mu12 Efficiency"

# PbPb L1DoubleMu0 efficiency
./Execute \
   --label "MC Pythia","Data" \
   --file Combined.root \
   --curve PbPb5TeV_DoubleMu_L1HLT_0_PT_MC_O,PbPb5TeV_DoubleMu_L1HLT_0_PT_Data_O \
   --xtitle "p_{T}^{#mu} (GeV)" --ytitle "Muon efficiency" --xmin 0 --xmax 30 --ymin 0.52 --ymax 1.00 \
   --system "PbPb 5.02 TeV" --qualifier $Qualifier \
   --ratio true --rtitle "Data/MC" --rmin 0.7 --rmax 1.5 --rfile Combined.root --rcurve PbPb5TeV_DoubleMu_L1HLT_0_PT_Ratio_O \
   --legendx 0.6 --legendy 0.1 --output Plots/PbPb5TeV_L1DoubleMu0.pdf \
   --text 0.5,0.42,"|#eta^{#mu}| < 2.4&comma; p_{T}^{#mu} > 1.8 GeV",0.5,0.50,"HLT_HIL1DoubleMu0 Efficiency"

# MB efficiency
./Execute \
	--label "40-50%","50-60%","60-70%","70-80%","80-100%" \
	--file Combined.root \
	--curve PbPb5TeV_MB_L1HLT_4050_O,PbPb5TeV_MB_L1HLT_5060_O,PbPb5TeV_MB_L1HLT_6070_O,PbPb5TeV_MB_L1HLT_7080_O,PbPb5TeV_MB_L1HLT_80100_O \
   --hline 1 --vline 15.5 \
   --xtitle "HF threshold (ADC)" --ytitle "Efficiency" --xmin 0 --xmax 40 --ymin 0.0 --ymax 1.2 \
   --system "PbPb 5.02 TeV" --qualifier $Qualifier \
   --text 0.45,0.91,"HLT_ZeroBias_SinglePixelTrack_AND",0.05,0.45,"Centrality" \
   --box 15,0,16,1.2 \
	--legendx 0.04 --legendy 0.04 --output Plots/PbPb5TeV_MB.pdf

# D0 pp efficiency
./Execute \
   --label "HLT D meson p_{T} #geq 8 GeV","HLT D meson p_{T} #geq 15 GeV","HLT D meson p_{T} #geq 20 GeV" \
   --file Combined.root \
   --curve pp5TeV_D_HLT_8,pp5TeV_D_HLT_15,pp5TeV_D_HLT_20 \
   --hline 1 \
   --xtitle "p_{T} (D^{0}) (GeV)" --ytitle "HLT Efficiency" --xmin 0 --xmax 50 --ymin 0 --ymax 1.05 \
   --system "pp 5.02 TeV" --qualifier $Qualifier \
   --legendx 0.5 --legendy 0.15 --output Plots/pp5TeV_D0.pdf

# D0 PbPb efficiency
./Execute \
   --label "HLT D meson p_{T} #geq 20 GeV","HLT D meson p_{T} #geq 40 GeV","HLT D meson p_{T} #geq 60 GeV" \
   --file Combined.root \
   --curve PbPb5TeV_D_HLT_20,PbPb5TeV_D_HLT_40,PbPb5TeV_D_HLT_60 \
   --hline 1 \
   --xtitle "p_{T} (D^{0}) (GeV)" --ytitle "HLT Efficiency" --xmin 10 --xmax 100 --ymin 0 --ymax 1.05 \
   --system "PbPb 5.02 TeV" --qualifier $Qualifier \
   --legendx 0.15 --legendy 0.35 --output Plots/PbPb5TeV_D0.pdf

# Photon
./Execute \
   --label "HLT SinglePhoton 40","HLT SinglePhoton 50","HLT SinglePhoton 60" \
   --file Combined.root \
   --curve PbPb5TeV_Photon_HLT_40_O,PbPb5TeV_Photon_HLT_50_O,PbPb5TeV_Photon_HLT_60_O \
   --hline 1 \
   --xtitle "p_{T}^{#gamma} (GeV)" --ytitle "L1+HLT Efficiency" --xmin 20 --xmax 110 --ymin 0 --ymax 1.05 \
   --system "PbPb 5.02 TeV" --qualifier $Qualifier \
   --text 0.55,0.4,"|#eta_{#gamma}| < 1.44" \
   --legendx 0.55 --legendy 0.1 --output Plots/PbPb5TeV_Photon.pdf

# Electron barrel
./Execute \
   --label "MC Pythia + Hydjet (0.9636^{+0.000}_{-0.000})","Data (0.9652^{+0.012}_{-0.013})" \
   --file Combined.root \
   --curve PbPb5TeV_Electron_L1HLT_20_MCBarrel,PbPb5TeV_Electron_L1HLT_20_DataBarrel \
   --xtitle "p_{T}^{e} (GeV)" --ytitle "Single electron efficiency" --xmin 15 --xmax 150 --ymin 0.81 --ymax 1.05 \
   --system "PbPb 5.02 TeV" --qualifier $Qualifier \
   --ratio true --rtitle "Scale factor" --rmin 0.9 --rmax 1.1 --rfile Combined.root --rcurve PbPb5TeV_Electron_L1HLT_20_RatioBarrel \
   --legendx 0.4 --legendy 0.1 --output Plots/PbPb5TeV_ElectronBarrel.pdf \
   --text 0.4,0.42,"|#eta^{#mu}| #in [0.0&comma; 1.4]&comma; p_{T}^{e} > 20.0 GeV",0.5,0.50,"L1+HLT Efficiency"

# Electron endcap
./Execute \
   --label "MC Pythia + Hydjet (0.9668^{+0.000}_{-0.000})","Data (0.9592^{+0.018}_{-0.024})" \
   --file Combined.root \
   --curve PbPb5TeV_Electron_L1HLT_20_MCEndcap,PbPb5TeV_Electron_L1HLT_20_DataEndcap \
   --xtitle "p_{T}^{e} (GeV)" --ytitle "Single electron efficiency" --xmin 15 --xmax 150 --ymin 0.81 --ymax 1.05 \
   --system "PbPb 5.02 TeV" --qualifier $Qualifier \
   --ratio true --rtitle "Scale factor" --rmin 0.9 --rmax 1.1 --rfile Combined.root --rcurve PbPb5TeV_Electron_L1HLT_20_RatioEndcap \
   --legendx 0.4 --legendy 0.1 --output Plots/PbPb5TeV_ElectronEndcap.pdf \
   --text 0.4,0.42,"|#eta^{#mu}| #in [1.6&comma; 2.0]&comma; p_{T}^{e} > 20.0 GeV",0.5,0.50,"L1+HLT Efficiency"

# Jet
./Execute \
   --label "HLT SingleJet 40","HLT SingleJet 60","HLT SingleJet 80","HLT SingleJet 100" \
   --file Combined.root \
   --curve PbPb5TeV_Jet_HLT_40,PbPb5TeV_Jet_HLT_60,PbPb5TeV_Jet_HLT_80,PbPb5TeV_Jet_HLT_100 \
   --hline 1 \
   --xtitle "p_{T}^{jet} (GeV)" --ytitle "L1+HLT Efficiency" --xmin 25 --xmax 180 --ymin 0 --ymax 1.05 \
   --system "PbPb 5.02 TeV" --qualifier $Qualifier \
   --text 0.55,0.45,"|#eta_{jet}| < 2.0",0.55,0.52,"anti-k_{t} R = 0.4" \
   --legendx 0.55 --legendy 0.1 --output Plots/PbPb5TeV_Jet.pdf

# L1EG barrel
./Execute \
   --label "MC Starlight (0.9781^{+0.002}_{-0.002})","Data (0.9790^{+0.004}_{-0.004})" \
   --file Combined.root \
   --curve PbPb5TeV_EG_L1_2_MCBarrel,PbPb5TeV_EG_L1_2_DataBarrel \
   --hline 1 \
   --xtitle "SC E_{T} (GeV)" --ytitle "Single electron efficiency" --xmin 0 --xmax 20 --ymin 0.31 --ymax 1.05 \
   --system "PbPb 5.02 TeV" --qualifier $Qualifier \
   --ratio true --rtitle "Data / MC" --rmin 0.5 --rmax 1.6 --rfile Combined.root --rcurve PbPb5TeV_EG_L1_2_RatioBarrel \
   --legendx 0.4 --legendy 0.1 --output Plots/PbPb5TeV_L1EGBarrel.pdf \
   --text 0.4,0.42,"|#eta^{#mu}| #in [0.0&comma; 1.5]&comma; SC E_{T} > 2.0 (GeV)",0.48,0.50,"L1 EG2 trigger Efficiency"

# L1EG endcap 
./Execute \
   --label "MC Starlight (0.9248^{+0.007}_{-0.008})","Data (0.8763^{+0.018}_{-0.019})" \
   --file Combined.root \
   --curve PbPb5TeV_EG_L1_2_MCEndcap,PbPb5TeV_EG_L1_2_DataEndcap \
   --hline 1 \
   --xtitle "SC E_{T} (GeV)" --ytitle "Single electron efficiency" --xmin 0 --xmax 20 --ymin 0.31 --ymax 1.05 \
   --system "PbPb 5.02 TeV" --qualifier $Qualifier \
   --ratio true --rtitle "Data / MC" --rmin 0.5 --rmax 1.6 --rfile Combined.root --rcurve PbPb5TeV_EG_L1_2_RatioEndcap \
   --legendx 0.4 --legendy 0.1 --output Plots/PbPb5TeV_L1EGEndcap.pdf \
   --text 0.4,0.42,"|#eta^{#mu}| #in [1.5&comma; 2.4]&comma; SC E_{T} > 2.0 GeV",0.48,0.50,"L1 EG2 trigger Efficiency"

# Yellow plots 2015
./Execute \
   --label "L1 double muon inclusive" \
   --file Combined.root \
   --curve PbPb5TeV_2015_L1DoubleMu_Spectrum_O \
   --color -2 \
   --histogram true \
   --xtitle "M_{#mu#mu} (GeV)" --ytitle "Events/GeV" --xmin 2 --xmax 199 --ymin 0.1 --ymax 300000 \
   --logx true --logy true \
   --system "PbPb 5.02 TeV (2015)" --qualifier $Qualifier \
   --text 0.07,0.92,"J/#psi",0.275,0.83,"#varUpsilon(1&comma;2&comma;3S)",0.82,0.54,"Z",0.5,0.9,"Trigger selecton:",0.10,0.10,"p_{T}^{#mu} > 4 GeV" \
   --legendx 0.5 --legendy 0.8 --output Plots/PbPb5TeV_MMuMu_2015.pdf

# Yellow plots 2018
./Execute \
   --label "L1 double muon inclusive","J/#psi region","#varUpsilon + high masses" \
   --file Combined.root \
   --curve PbPb5TeV_2018_L1DoubleMu_Spectrum_O,PbPb5TeV_2018_JPsi_Spectrum_O,PbPb5TeV_2018_UpsilonZ_Spectrum_O \
   --color -2,-3,-1 \
   --histogram true \
   --xtitle "M_{#mu#mu} (GeV)" --ytitle "Events/GeV" --xmin 0.5 --xmax 199 --ymin 0.1 --ymax 80000000 \
   --logx true --logy true \
   --system "PbPb 5.02 TeV (2018)" --qualifier $Qualifier \
   --text 0.28,0.7,"J/#psi",0.43,0.64,"#varUpsilon(1&comma;2&comma;3S)",0.86,0.43,"Z",0.27,0.91,"Trigger selecton:",0.10,0.10,"p_{T}^{#mu} > 4 GeV" \
   --legendx 0.52 --legendy 0.73 --output Plots/PbPb5TeV_MMuMu_2018.pdf


