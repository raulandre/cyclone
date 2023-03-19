#include <assert.h>
#include "cyclone/core.hpp"
#include "cyclone/particle.hpp"
#include "cyclone/pfgen.hpp"
#include "cyclone/precision.hpp"

void cyclone::Particle::integrate(real duration) {
	#ifndef CY_RELEASE
	assert(duration > 0);	
	#endif

	position.addScaledVector(velocity, duration);

	auto acc = acceleration;
	acc.addScaledVector(forceAccum, inverseMass);

	velocity.addScaledVector(acc, duration);

	velocity *= real_pow(damping, duration);
	clearAccumulator();
}

void cyclone::Particle::clearAccumulator() {
	forceAccum = Vec3();
}

void cyclone::Particle::applyForce(Vec3 force) {
	forceAccum += force;
}

void cyclone::Particle::applyForceScaled(Vec3 force, real scale) {
	forceAccum.addScaledVector(force, scale);
}