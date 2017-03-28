cd ../Examples/CUsecases; 
echo "Compiling tests ..."
clang test.c -O3 -o test.exe
clang test_storaged.c -O3 -o test_dps.exe

echo "Running test.exe"
./test.exe
echo "Running test_dps.exe"
./test_dps.exe