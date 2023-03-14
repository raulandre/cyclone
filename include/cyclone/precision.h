#ifndef PRECISION_H
#define PRECISION_H
namespace cyclone {
	#ifdef CY_DOUBLE_PRECISION
		typedef double real;
		#define real_sqrt sqrt
	#else
		typedef float real;
		#define real_sqrt sqrtf
	#endif
}
#endif
