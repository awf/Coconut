CC=clang++
OPTFLAG=-O3
CFLAGS=-std=c++14 -stdlib=libc++
LIBS=-std=c++14 -stdlib=libc++ 
FILES=benchmark_ba.cpp usecases_ba.cpp stdafx.cpp

compile:
	$(CC) $(OPTFLAG) $(CFLAGS) $(LIBS) $(FILES) -o ba_cpp.exe;
	$(CC) $(OPTFLAG) $(CFLAGS) $(LIBS) $(FILES) -DEIGEN -I /usr/local/include/eigen3 -o ba_eigen_cpp.exe;