// benchmark_ba.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "usecases_ba.h"


int main()
{
    auto cam = vec(
        0.1, 0.1, 0.1,     // ROT_IDX = 0;    
        0.2,0.1,0.3,       // CENTER_IDX = 3;
        1.2,               // FOCAL_IDX = 6;
        0.01, 0.03,        // X0_IDX = 7;
        0.009, 1.2e-4      // RAD_IDX = 9;
        );

    Vec3<Real> X = vec(0.03, 0.11, -0.7);


    // boost::timer::auto_cpu_timer t;
    timer_t t = tic();

    // Debug 150s 
    // Release 1s
    double total = 0;
    int N = 10000000;
#ifdef _DEBUG
    N = N / 100;  // Debug is roughly this much slower than release -- multiply timings.
#endif
    for (int count = 0; count < N; ++count) {
        X[0] = 1.0 / (2.0 + count);
        cam[5] = 1.0 + count * 1e-6;

        total += sumsq(project(cam, X));
    }

    // std::cout << "total =" << total << ", time per call = " << t.elapsed().wall/double(N) << "ns" << std::endl;
    // std::cout << "total =" << total << std::endl;
    auto elapsed = toc(t);
    printf("total =%f, time per call = %f ms\n", total, elapsed / double(N));
    
    return 0;
}
