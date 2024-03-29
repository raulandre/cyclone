#ifndef PARTICLE_SPRING_HPP
#define PARTICLE_SPRING_HPP
#include "cyclone/particle.hpp"
#include <cyclone/core.hpp>
#include <cyclone/pfgen.hpp>

namespace cyclone {
	class ParticleSpring : public ParticleForceGenerator 
	{
		Particle *other;
		real springConstant;
		real restLength;

	public:
		ParticleSpring(Particle *other, real springConstant, real restLength) : other(other), springConstant(springConstant), restLength(restLength) {}
		virtual void updateForce(Particle *particle, real duration);
	};

	class ParticleAnchoredSpring : public ParticleForceGenerator
	{
		Vec3 *anchor;
		real springConstant;
		real restLength;

	public:
		ParticleAnchoredSpring(Vec3 *anchor, real springConstant, real restLength) : anchor(anchor), springConstant(springConstant), restLength(restLength) {}
		virtual void updateForce(Particle *particle, real duration);
	};
}

#endif
