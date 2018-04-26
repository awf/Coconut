CC=clang++
OPTFLAG=-O3
CFLAGS=-std=c++14 -stdlib=libc++
LIBS=-std=c++14 -stdlib=libc++ 
FILES=benchmark_gmm.cpp usecases_gmm.cpp stdafx.cpp

compile:
	$(CC) $(OPTFLAG) $(CFLAGS) $(LIBS) $(FILES) -o gmm_fixed_cpp.exe;
	$(CC) $(OPTFLAG) $(CFLAGS) $(LIBS) $(FILES) -DEIGEN -I /usr/local/include/eigen3 -o gmm_eigen_cpp.exe;