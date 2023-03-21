#ifndef PRECISION_HPP
#define PRECISION_HPP
namespace cyclone {
	#ifdef CY_DOUBLE_PRECISION
		typedef double real;
		#define real_sqrt sqrt
		#define real_pow pow
		#define real_abs fabsf
	#else
		typedef float real;
		#define real_sqrt sqrtf
		#define real_pow powf
		#define real_abs fabs
	#endif
}
#endif
