#include <assert.h>
#include "cyclone/particle.hpp"
#include "cyclone/precision.hpp"

void cyclone::Particle::integrate(real duration) {
	assert(duration > 0);	

	position.addScaledVector(velocity, duration);

	auto acc = acceleration;
	acc.addScaledVector(forceAccum, inverseMass);

	velocity.addScaledVector(acc, duration);

	velocity *= real_pow(damping, duration);
}
