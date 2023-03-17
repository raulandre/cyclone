#ifndef PARTICLE_H
#define PARTICLE_H
#include "core.h"

namespace cyclone {
	class Particle {
		public:
		Vec3 position;
		Vec3 velocity;
		Vec3 acceleration;
		real damping;

		protected:
		real inverseMass;

		public:
		real getMass() const { return inverseMass; }
		void setMass(real mass) { inverseMass = 1 / mass; }
		void setInverseMass(real inverseMass) { this->inverseMass = inverseMass; }
	};
}

#endif
