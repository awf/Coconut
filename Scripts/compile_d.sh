cd ../Examples; 
cd Micro;
echo "Compiling test ..."
clang test_d.c -O3 -o test_d.exe
cd ..;
cd GMM;
echo "Compiling GMM ..."
clang gmm_d.c -O3 -o gmm_d.exe
clang gmm_d.c -O3 -DFUSED -o gmm_opt_d.exe