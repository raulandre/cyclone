#ifndef PRECISION_H
#define PRECISION_H
namespace cyclone {
	#ifdef CY_DOUBLE_PRECISION
		typedef double real;
		#define real_sqrt sqrt
		#define real_pow pow
	#else
		typedef float real;
		#define real_sqrt sqrtf
		#define real_pow powf
	#endif
}
#endif
