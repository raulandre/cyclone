#include <cyclone/forceGenerators/particleDrag.hpp>

void cyclone::ParticleDrag::updateForce(Particle *particle, real duration) {
    Vec3 force = particle->velocity;

    real dragCoeff = force.magnitude();
    dragCoeff = k1 * dragCoeff + k2 * dragCoeff * dragCoeff;

    force.normalize();
    force *= -dragCoeff;
    particle->applyForce(force);
}