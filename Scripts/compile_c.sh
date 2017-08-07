cd ../Examples; 
cd BundleAdjustment;
echo "Compiling BA ..."
clang ba.c -O3 -o ba.exe
clang ba.c -O3 -DGC -lgc -o ba_gc.exe
clang ba.c -O3 -DFUSED -o ba_opt.exe
clang ba.c -O3 -DDPS -o ba_dps.exe
clang ba.c -O3 -DDPS -DHOIST -o ba_dps_hoist.exe
clang ba.c -O3 -DDPS -DFUSED -o ba_opt_dps.exe
clang ba.c -O3 -DDPS -DFUSED -DHOIST -o ba_opt_dps_hoist.exe
clang ba.c -O3 -DBUMP -DDPS -o ba_dps_bump.exe
clang ba.c -O3 -DBUMP -DFUSED -o ba_opt_bump.exe
clang ba.c -O3 -DBUMP -DDPS -DFUSED -o ba_opt_dps_bump.exe
clang ba.c -O3 -DBUMP -DDPS -DHOIST -DFUSED -o ba_opt_dps_hoist_bump.exe
cd ../GMM;
echo "Compiling GMM ..."
clang gmm.c -O3 -o gmm.exe
clang gmm.c -O3 -DGC -lgc -o gmm_gc.exe
clang gmm.c -O3 -DFUSED -o gmm_opt.exe
clang gmm.c -O3 -DDPS -o gmm_dps.exe
clang gmm.c -O3 -DDPS -DHOIST -o gmm_dps_hoist.exe
clang gmm.c -O3 -DDPS -DFUSED -o gmm_opt_dps.exe
clang gmm.c -O3 -DDPS -DFUSED -DHOIST -o gmm_opt_dps_hoist.exe
clang gmm.c -O3 -DBUMP -DDPS -o gmm_dps_bump.exe
clang gmm.c -O3 -DBUMP -DDPS -DFUSED -o gmm_opt_dps_bump.exe
clang gmm.c -O3 -DBUMP -DDPS -DHOIST -DFUSED -o gmm_opt_dps_hoist_bump.exe
cd ../HandTracking;
echo "Compiling HT ..."
clang ht.c -O3 -o ht.exe
clang ht.c -O3 -DGC -lgc -o ht_gc.exe
clang ht.c -O3 -DFUSED -o ht_opt.exe
clang ht.c -O3 -DDPS -o ht_dps.exe
clang ht.c -O3 -DDPS -DHOIST -o ht_dps_hoist.exe
clang ht.c -O3 -DDPS -DFUSED -o ht_opt_dps.exe
clang ht.c -O3 -DDPS -DFUSED -DHOIST -o ht_opt_dps_hoist.exe
clang ht.c -O3 -DBUMP -DDPS -o ht_dps_bump.exe
clang ht.c -O3 -DBUMP -DDPS -DFUSED -o ht_opt_dps_bump.exe
clang ht.c -O3 -DBUMP -DDPS -DHOIST -DFUSED -o ht_opt_dps_hoist_bump.exe
cd ../Micro;
echo "Compiling Micro Benchmarks ..."
echo "Compiling Add3 ..."
clang micro.c -O3 -DADD3 -o micro_add3.exe
clang micro.c -O3 -DADD3 -DGC -lgc -o micro_add3_gc.exe
clang micro.c -O3 -DADD3 -DFUSED -o micro_add3_opt.exe
clang micro.c -O3 -DADD3 -DDPS -o micro_add3_dps.exe
clang micro.c -O3 -DADD3 -DDPS -DHOIST -o micro_add3_dps_hoist.exe
clang micro.c -O3 -DADD3 -DDPS -DFUSED -o micro_add3_opt_dps.exe
clang micro.c -O3 -DADD3 -DDPS -DFUSED -DHOIST -o micro_add3_opt_dps_hoist.exe
clang micro.c -O3 -DADD3 -DBUMP -DDPS -o micro_add3_dps_bump.exe
clang micro.c -O3 -DADD3 -DBUMP -DDPS -DFUSED -o micro_add3_opt_dps_bump.exe
clang micro.c -O3 -DADD3 -DBUMP -DDPS -DHOIST -DFUSED -o micro_add3_opt_dps_hoist_bump.exe
echo "Compiling Cross ..."
clang micro.c -O3 -DCROSS -o micro_cross.exe
clang micro.c -O3 -DCROSS -DGC -lgc -o micro_cross_gc.exe
clang micro.c -O3 -DCROSS -DFUSED -o micro_cross_opt.exe
clang micro.c -O3 -DCROSS -DDPS -o micro_cross_dps.exe
clang micro.c -O3 -DCROSS -DDPS -DHOIST -o micro_cross_dps_hoist.exe
clang micro.c -O3 -DCROSS -DDPS -DFUSED -o micro_cross_opt_dps.exe
clang micro.c -O3 -DCROSS -DDPS -DFUSED -DHOIST -o micro_cross_opt_dps_hoist.exe
clang micro.c -O3 -DCROSS -DBUMP -DDPS -o micro_cross_dps_bump.exe
clang micro.c -O3 -DCROSS -DBUMP -DDPS -DFUSED -o micro_cross_opt_dps_bump.exe
clang micro.c -O3 -DCROSS -DBUMP -DDPS -DHOIST -DFUSED -o micro_cross_opt_dps_hoist_bump.exe