#ifndef PARTICLE_GRAVITY_HPP
#define PARTICLE_GRAVITY_HPP
#include <cyclone/pfgen.hpp>

namespace cyclone {
    class ParticleGravity : public ParticleForceGenerator {
        Vec3 gravity;

    public:
        ParticleGravity(const Vec3& gravity) : gravity(gravity) {}
        virtual void updateForce(Particle *particle, real duration);
    };
}
#endif