CFOLDER="../Examples/CUsecases"

declare -a files=(
   "micro_add3.exe" "micro_add3_gc.exe" "micro_add3_opt.exe" "micro_add3_dps.exe" "micro_add3_opt_dps.exe" "micro_add3_opt_dps_hoist.exe" "micro_add3_opt_dps_hoist_bump.exe"
   "../CPPUsecases/benchmark_micro/micro_add3_cpp.exe" "../CPPUsecases/benchmark_micro/micro_add3_eigen_cpp.exe"
   "micro_cross.exe" "micro_cross_gc.exe" "micro_cross_opt.exe" "micro_cross_dps.exe" "micro_cross_opt_dps.exe" "micro_cross_opt_dps_hoist.exe" "micro_cross_opt_dps_hoist_bump.exe"
   "../CPPUsecases/benchmark_micro/micro_cross_cpp.exe" "../CPPUsecases/benchmark_micro/micro_cross_eigen_cpp.exe"
	)

echo "=== Run time Usage ==="

N=1000000;

for i in "${files[@]}"
do
   l=$(eval "./$CFOLDER/$i $N" | awk '{print $7;}')
   echo "$i,$l"
done

declare -a iters=(1000 10000 100000 1000000 10000000)

echo "=== Memory Usage ==="

for i in "${files[@]}"
do
	for it in "${iters[@]}"
	do
   		l=$(eval "./memusg.sh './$CFOLDER/$i $it'" | awk '{print $1;}')
   		echo "$i,$it,$l"
   	done
done