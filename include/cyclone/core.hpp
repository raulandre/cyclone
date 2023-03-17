#ifndef CORE_H
#define CORE_H
#include "cyclone/precision.hpp"
#include <cmath>

namespace cyclone {
	class Vec3 {
		public:
			real x;
			real y;
			real z;
		#ifndef CY_NO_PADDING
		private:
			real pad;
		#endif

		public:
			Vec3() : x(0), y(0), z(0) {}
			Vec3(const real x, const real y, const real z) : x(x), y(y), z(z) {}

			void invert() {
				x = -x;
				y = -y;
				z = -z;
			}

			real magnitude() const {
				return real_sqrt(x*x + y*y + z*z);
			}

			real squareMagnitude() const {
				return x*x + y*y + z*z;
			}

			void normalize() {
				real l = magnitude();
				if(l > 0) {
					*(this) *= ((real)1)/l;
				}
			}
			
			void addScaledVector(const Vec3& vector, real scale) {
				x += vector.x * scale;
				y += vector.y * scale;
				z += vector.z * scale;
			}

			real scalarProduct(const Vec3& vector) const {
				return x * vector.x + y * vector.y + z * vector.z;
			}

			Vec3 componentProduct(const Vec3& other) {
				return Vec3(x * other.x, y * other.y, z * other.z);
			}

			void componentProductUpdate(const Vec3& other) {
				x *= other.x;
				y *= other.y;
				z *= other.z;
			}

			void operator*=(const real scalar) {
				x *= scalar;
				y *= scalar;
				z *= scalar;
			}
			
			void operator+=(const Vec3& other) {
				x += other.x;
				y += other.y;
				z += other.z;
			}

			void operator-=(const Vec3& other) {
				x -= other.x;
				y -= other.y;
				z -= other.z;
			}
			
			Vec3 vectorProduct(const Vec3& vector) const {
				return Vec3(
					y * vector.z - z * vector.y,
					z * vector.x - x * vector.z,
					x * vector.y - y * vector.x
				);
			}

			Vec3 operator*(const real scalar) const {
				return Vec3(x * scalar, y * scalar, z * scalar);
			}

			Vec3 operator+(const Vec3& other) const {
				return Vec3(x + other.x, y + other.y, z + other.z);
			}

			Vec3 operator-(const Vec3& other) const {
				return Vec3(x - other.x, y - other.y, z - other.z);
			}

			real operator*(const Vec3& vector) const {
				return x * vector.x + y * vector.y + z * vector.z;
			}

			Vec3 operator%(const Vec3& vector) const {
				return Vec3(
					y * vector.z - z * vector.y,
					z * vector.x - x * vector.z,
					x * vector.y - y * vector.x
				);
			}

			void operator%=(const Vec3& vector) {
				*this = vectorProduct(vector);
			}
	};
}
#endif
