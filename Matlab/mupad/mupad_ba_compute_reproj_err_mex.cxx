#line 2 "au_autodiff_generate_template.cpp"
#include <math.h>

#include "au_mex.h"

// Autogenerated by au_ccode
// FROM: f
// au_autodiff_template.cpp - outline code for au_autodiff*
// awf@microsoft.com, Dec 13

void mlx_function(mlx_inputs& ins, mlx_outputs& outs)
{
    mlx_array<mlx_double> in(ins[0]);
    mlx_array<mlx_double> data(ins[1]);
    mlx_array<mlx_logical> jacobian(ins[2]);
    bool do_jacobian = jacobian[0];

    mlx_assert(in.cols == data.cols);
    mlx_assert(in.rows == 15);
    mlx_assert(data.rows == 2);

    mwSize out_rows = 1 + (do_jacobian ? 15 : 0);
    mwSize out_cols = 2 * in.cols;
    mlx_make_array<mlx_double> out(out_rows, out_cols);

    double const* in_ptr = in.data;
    double const* data_ptr = data.data;
    double* out_ptr = out.data;

    if (do_jacobian) {
        // const mwSize out_rows = 15 + 1;
        const mwSize out_step = (15 + 1) * 2;
        for(mwSize c_in = 0; c_in < in.cols; ++c_in,
                in_ptr += in.rows,
                data_ptr += data.rows,
                out_ptr += out_step) {
              /* inner loop do_jac=1 */
    double x1 = in_ptr[0];
    double x2 = in_ptr[1];
    double x3 = in_ptr[2];
    double x4 = in_ptr[3];
    double x5 = in_ptr[4];
    double x6 = in_ptr[5];
    double x7 = in_ptr[6];
    double x8 = in_ptr[7];
    double x9 = in_ptr[8];
    double x10 = in_ptr[9];
    double x11 = in_ptr[10];
    double x12 = in_ptr[11];
    double x13 = in_ptr[12];
    double x14 = in_ptr[13];
    double x15 = in_ptr[14];
    double data1 = data_ptr[0];
    double data2 = data_ptr[1];
    double t2 = x5-x13;
    double t3 = x10*x10;
    double t4 = x11*x11;
    double t5 = t3+t4;
    double t6 = x4-x12;
    double t7 = t2*x1;
    double t11 = t6*x2;
    double t8 = t7-t11+x6-x14;
    double t9 = 1.0/t8;
    double t10 = x6-x14;
    double t12 = t10*x2;
    double t22 = t2*x3;
    double t13 = t12-t22+x4-x12;
    double t14 = t5*t9*t13;
    double t15 = t5*t5;
    double t16 = t6*x3;
    double t20 = t10*x1;
    double t17 = t16-t20+x5-x13;
    double t18 = t9*t15*t17;
    double t19 = t14+t18+1.0;
    double t21 = 1.0/(t8*t8);
    double t23 = t9*t10*t15;
    double t24 = t2*t15*t17*t21;
    double t25 = t2*t5*t13*t21;
    double t26 = t23+t24+t25;
    double t27 = t5*t9*t10;
    double t28 = t6*t15*t17*t21;
    double t29 = t5*t6*t13*t21;
    double t30 = t27+t28+t29;
    double t31 = t2*t5*t9;
    double t32 = t31-t6*t9*t15;
    double t33 = t5*t9;
    double t34 = t9*t15*x3;
    double t35 = t15*t17*t21*x2;
    double t36 = t5*t13*t21*x2;
    double t37 = t33+t34+t35+t36;
    double t38 = t5*t9*x3;
    double t39 = t15*t17*t21*x1;
    double t40 = t5*t13*t21*x1;
    double t55 = t9*t15;
    double t41 = t38+t39+t40-t55;
    double t42 = t5*t13*t21;
    double t43 = t9*t15*x1;
    double t44 = t15*t17*t21;
    double t56 = t5*t9*x2;
    double t45 = t42+t43+t44-t56;
    double t46 = t9*t13*x10*2.0;
    double t47 = t5*t9*t17*x10*4.0;
    double t48 = t46+t47;
    double t49 = t19*x7;
    double t50 = t9*t13*x11*2.0;
    double t51 = t5*t9*t17*x11*4.0;
    double t52 = t50+t51;
    double t53 = t37*x7*x10*x15;
    double t54 = t37*x7*x11*x15;
    double t57 = t19*x7*x10;
    double t58 = -data1+t57+x8;
    double t59 = t19*x7*x11;
    double t60 = -data2+t59+x9;
  out_ptr[0] = t58*x15;
  out_ptr[1 * out_rows + 0] = t60*x15;
  out_ptr[1] = -t26*x7*x10*x15;
  out_ptr[1 * out_rows + 1] = -t26*x7*x11*x15;
  out_ptr[2] = t30*x7*x10*x15;
  out_ptr[1 * out_rows + 2] = t30*x7*x11*x15;
  out_ptr[3] = -t32*x7*x10*x15;
  out_ptr[1 * out_rows + 3] = -t32*x7*x11*x15;
  out_ptr[4] = t53;
  out_ptr[1 * out_rows + 4] = t54;
  out_ptr[5] = -t41*x7*x10*x15;
  out_ptr[1 * out_rows + 5] = -t41*x7*x11*x15;
  out_ptr[6] = -t45*x7*x10*x15;
  out_ptr[1 * out_rows + 6] = -t45*x7*x11*x15;
  out_ptr[7] = t19*x10*x15;
  out_ptr[1 * out_rows + 7] = t19*x11*x15;
  out_ptr[8] = x15;
  out_ptr[1 * out_rows + 9] = x15;
  out_ptr[10] = x15*(t49+t48*x7*x10);
  out_ptr[1 * out_rows + 10] = t48*x7*x11*x15;
  out_ptr[11] = t52*x7*x10*x15;
  out_ptr[1 * out_rows + 11] = x15*(t49+t52*x7*x11);
  out_ptr[12] = -t53;
  out_ptr[1 * out_rows + 12] = -t54;
  out_ptr[13] = t41*x7*x10*x15;
  out_ptr[1 * out_rows + 13] = t41*x7*x11*x15;
  out_ptr[14] = t45*x7*x10*x15;
  out_ptr[1 * out_rows + 14] = t45*x7*x11*x15;
  out_ptr[15] = t58;
  out_ptr[1 * out_rows + 15] = t60;

#line 39 "au_autodiff_generate_template.cpp"
        }
    } else {
        const mwSize out_step = 2;
        for(mwSize c_in = 0; c_in < in.cols; ++c_in,
                in_ptr += in.rows,
                data_ptr += data.rows,
                out_ptr += out_step) {
              /* inner loop do_jac=0 */
    double x1 = in_ptr[0];
    double x2 = in_ptr[1];
    double x3 = in_ptr[2];
    double x4 = in_ptr[3];
    double x5 = in_ptr[4];
    double x6 = in_ptr[5];
    double x7 = in_ptr[6];
    double x8 = in_ptr[7];
    double x9 = in_ptr[8];
    double x10 = in_ptr[9];
    double x11 = in_ptr[10];
    double x12 = in_ptr[11];
    double x13 = in_ptr[12];
    double x14 = in_ptr[13];
    double x15 = in_ptr[14];
    double data1 = data_ptr[0];
    double data2 = data_ptr[1];
    double t2 = x5-x13;
    double t3 = x10*x10;
    double t4 = x11*x11;
    double t5 = t3+t4;
    double t6 = x4-x12;
    double t7 = t2*x1;
    double t11 = t6*x2;
    double t8 = t7-t11+x6-x14;
    double t9 = 1.0/t8;
    double t10 = x6-x14;
    double t12 = t10*x2;
    double t13 = t12+x4-x12-t2*x3;
    double t14 = t5*t9*t13;
    double t15 = t5*t5;
    double t16 = t6*x3;
    double t17 = t16+x5-x13-t10*x1;
    double t18 = t9*t15*t17;
    double t19 = t14+t18+1.0;
  out_ptr[0] = x15*(-data1+x8+t19*x7*x10);
  out_ptr[1] = x15*(-data2+x9+t19*x7*x11);

#line 48 "au_autodiff_generate_template.cpp"
        }
    }
    
    outs[0] = out;
}