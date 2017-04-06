CC=clang++
OPTFLAG=-O3
CFLAGS=-std=c++14 -stdlib=libc++
LIBS=-std=c++14 -stdlib=libc++ 
FILES=benchmark_ht.cpp usecases_ht.cpp stdafx.cpp

compile:
	$(CC) $(OPTFLAG) $(CFLAGS) $(LIBS) $(FILES) -o ht_cpp.exe;
	# $(CC) $(OPTFLAG) $(CFLAGS) $(LIBS) $(FILES) -DEIGEN -I /usr/local/include/eigen3 -o ht_eigen_cpp.exe;