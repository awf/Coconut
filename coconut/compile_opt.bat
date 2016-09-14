@echo off
setLocal EnableDelayedExpansion

for /L %%i in (0,1,10) do (
  call echo "Compiling upto Level %%i"
  call cl ba_opt.c /Ox /Feba_opt_%%i.exe /DMETHOD=TOP_LEVEL_usecases_ba_reproj_err_%%i /DBA_%%i
)