#include <cyclone/forceGenerators/particleGravity.hpp>

void cyclone::ParticleGravity::updateForce(Particle *particle, real duration) {
    particle->applyForce(gravity * particle->getMass());
}