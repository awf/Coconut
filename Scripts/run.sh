ExFolder="../Examples"

declare -a files=(
	"BundleAdjustment/ba.exe" "BundleAdjustment/ba_gc.exe" "BundleAdjustment/ba_opt.exe" "BundleAdjustment/ba_dps.exe" "BundleAdjustment/ba_opt_dps.exe" "BundleAdjustment/ba_opt_dps_hoist.exe" "BundleAdjustment/ba_opt_dps_hoist_bump.exe"
	"BundleAdjustment/CPP/ba_cpp.exe" "BundleAdjustment/CPP/ba_eigen_cpp.exe"

	"GMM/gmm.exe" "GMM/gmm_gc.exe" "GMM/gmm_opt.exe" "GMM/gmm_dps.exe" "GMM/gmm_opt_dps.exe" "GMM/gmm_opt_dps_hoist.exe" "GMM/gmm_opt_dps_hoist_bump.exe"
	"GMM/CPP/gmm_fixed_cpp.exe" "GMM/CPP/gmm_eigen_cpp.exe"

	"HandTracking/ht.exe" "HandTracking/ht_gc.exe" "HandTracking/ht_opt.exe" "HandTracking/ht_dps.exe" "HandTracking/ht_opt_dps.exe" "HandTracking/ht_opt_dps_hoist.exe" "HandTracking/ht_opt_dps_hoist_bump.exe"
	"HandTracking/CPP/ht_cpp.exe"
	)

echo "=== Run time Usage ==="

for i in "${files[@]}"
do
   echo "$i"
   eval "./$ExFolder/$i"
done

echo "=== Memory Usage ==="

for i in "${files[@]}"
do
   echo "$i"
   eval "./memusg.sh ./$ExFolder/$i"
done