gcc test_storaged.c -o test_dps.exe
gcc ba_storaged.c -O3 -o ba_dps.exe
gcc ba_storaged.c -O3 -DBUMP -o ba_dps_bump.exe
gcc gmm_storaged.c -O3 -o gmm_dps.exe
gcc ht_storaged.c -O3 -o ht_dps.exe