@echo off
setLocal EnableDelayedExpansion

for /L %%i in (0,1,10) do (
  call echo "Running upto Level %%i"
  call ba_opt_%%i.exe "..\data\ba_instances\ba14.txt" >> results\time_opt.txt
)