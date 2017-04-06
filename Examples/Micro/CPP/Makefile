CC=clang++
OPTFLAG=-O3
CFLAGS=-std=c++14 -stdlib=libc++
LIBS=-std=c++14 -stdlib=libc++ 
FILES=benchmark_micro.cpp stdafx.cpp

compile:
	$(CC) $(OPTFLAG) $(CFLAGS) $(LIBS) $(FILES) -DADD3 -o micro_add3_cpp.exe;
	$(CC) $(OPTFLAG) $(CFLAGS) $(LIBS) $(FILES) -DADD3 -DEIGEN -I /usr/local/include/eigen3 -o micro_add3_eigen_cpp.exe;
	$(CC) $(OPTFLAG) $(CFLAGS) $(LIBS) $(FILES) -DCROSS -o micro_cross_cpp.exe;
	$(CC) $(OPTFLAG) $(CFLAGS) $(LIBS) $(FILES) -DCROSS -DEIGEN -I /usr/local/include/eigen3 -o micro_cross_eigen_cpp.exe;
	$(CC) $(OPTFLAG) $(CFLAGS) $(LIBS) $(FILES) -DDOT -o micro_dot_cpp.exe;
	$(CC) $(OPTFLAG) $(CFLAGS) $(LIBS) $(FILES) -DDOT -DEIGEN -I /usr/local/include/eigen3 -o micro_dot_eigen_cpp.exe;