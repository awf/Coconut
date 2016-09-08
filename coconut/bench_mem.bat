@echo off
setLocal EnableDelayedExpansion

:: test.exe

set argfile="../data/ba_instances/benchmark_list.txt"
:: Reset argfile if supplied.
if "%~1" neq "" set argfile="%~1"
:: Remove quotes
set argfile=!argfile:"=!

for /f "tokens=*" %%G in (%argfile%) do (
  call echo "Running %%G"
  for /L %%i in (1,1,5) do (
    call runapp.exe ba.exe "../data/ba_instances/%%G" >> results/mem.txt
  )
  for /L %%i in (1,1,5) do (
    call runapp.exe ba_s.exe "../data/ba_instances/%%G" >> results/mem.txt
  )
  for /L %%i in (1,1,5) do (
    call runapp.exe ba_bump.exe "../data/ba_instances/%%G" >> results/mem.txt
  )
  for /L %%i in (1,1,5) do (
    call runapp.exe ba_s_bump.exe "../data/ba_instances/%%G" >> results/mem.txt
  )
)
