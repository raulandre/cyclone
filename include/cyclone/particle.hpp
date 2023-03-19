#ifndef PARTICLE_HPP
#define PARTICLE_HPP
#include "core.hpp"

namespace cyclone {
	class Particle {
		public:
		Vec3 position;
		Vec3 velocity;
		Vec3 acceleration;

		protected:
		real mass;
		real inverseMass;
		real damping;
		Vec3 forceAccum;
		bool finiteMass = false;

		public:
		real getInverseMass() const { return inverseMass; }
		real getMass() const { return this->mass; }
		void setMass(real mass) { this->mass = mass; inverseMass = real(1) / mass; finiteMass = true; }
		void setInverseMass(const real inverseMass) { this->inverseMass = inverseMass; }
		bool hasFiniteMass() const { return finiteMass; }

		real getDamping() const { return damping; }
		void setDamping(const real damping) { this->damping = damping; }

		void integrate(real duration);
		void clearAccumulator();
		void applyForce(Vec3 force);
		void applyForceScaled(Vec3 force, real scale);
	};
}

#endif
