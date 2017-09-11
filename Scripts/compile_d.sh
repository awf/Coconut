cd ../Examples; 
cd Micro;
echo "Compiling test ..."
clang test_d.c -O3 -o test_d.exe
cd ..;
cd GMM;
echo "Compiling GMM ..."
clang gmm_d.c -O3 -o gmm_d.exe
clang gmm_d.c -O3 -DFUSED -o gmm_opt_d.exe
cd ..;
cd BundleAdjustment;
echo "Compiling BA ..."
clang ba_d.c -O3 -DBUMP -o ba_d.exe
clang ba_d.c -O3 -DFUSED -DBUMP -o ba_opt_d.exe
clang ba_d.c -O3 -DFUSED -DBUMP -DDPS -DHOIST -o ba_opt_dps_d.exe
cd ../Micro;
echo "Compiling Micro Benchmarks ..."
echo "Compiling dot product ..."
clang micro_d.c -O3 -DDOT -o micro_dot_d.exe
clang micro_d.c -O3 -DFUSED -DDOT -o micro_dot_opt_d.exe