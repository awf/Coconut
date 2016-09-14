@echo off
setLocal EnableDelayedExpansion

:: test.exe

set argfile="../data/ba_instances/benchmark_list.txt"
:: Reset argfile if supplied.
if "%~1" neq "" set argfile="%~1"
:: Remove quotes
set argfile=!argfile:"=!
set runs=5

for /f "tokens=*" %%G in (%argfile%) do (
  call echo Running Memory Benchmark of %%G
  for %%R in (ba ba_s ba_bump ba_s_bump fsharpo) do (
    call echo Memory Benchmark of %%R
    for /L %%i in (1,1,%runs%) do (
      call runapp.exe %%R "../data/ba_instances/%%G" >> ../results/mem.txt
    )
    call echo Runtime Performance of %%R
    call echo %%G, %%R >> ../results/time.txt
    for /L %%i in (1,1,%runs%) do (
      call %%R "../data/ba_instances/%%G" >> ../results/time.txt
    )
  )
)
