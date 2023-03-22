#include "cyclone/particle.hpp"
#include "cyclone/precision.hpp"
#include <cyclone/forceGenerators/particleSpring.hpp>

void cyclone::ParticleSpring::updateForce(cyclone::Particle *particle, real duration) {
	Vec3 force = particle->position;
	force -= other->position;

	real magnitude = force.magnitude();
	magnitude = real_abs(magnitude - restLength);
	magnitude *= springConstant;

	force.normalize();
	force *= -magnitude;
	particle->applyForce(force);
}

void cyclone::ParticleAnchoredSpring::updateForce(Particle *particle, real duration) {
	Vec3 force = particle->position;
	force -= *anchor;
	
	real magnitude = force.magnitude();
	magnitude = real_abs(magnitude - restLength);
	magnitude *= springConstant;

	force.normalize();
	force *= -magnitude;
	particle->applyForce(force);
}
