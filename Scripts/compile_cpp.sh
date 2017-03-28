echo "Compiling CPP files ..."
cd ../Examples/CPPUsecases; 
cd benchmark_gmm; make
cd ..; cd benchmark_ba; make
cd ..; cd benchmark_ht; make
cd ..; cd benchmark_micro; make