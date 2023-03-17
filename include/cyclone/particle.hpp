#ifndef PARTICLE_H
#define PARTICLE_H
#include "core.hpp"

namespace cyclone {
	class Particle {
		public:
		Vec3 position;
		Vec3 velocity;
		Vec3 acceleration;
		Vec3 forceAccum;

		protected:
		real inverseMass;
		real damping;

		public:
		real getMass() const { return inverseMass; }
		void setMass(real mass) { inverseMass = real(1) / mass; }
		void setInverseMass(const real inverseMass) { this->inverseMass = inverseMass; }

		real getDamping() const { return damping; }
		void setDamping(const real damping) { this->damping = damping; }

		void integrate(real duration);
	};
}

#endif
