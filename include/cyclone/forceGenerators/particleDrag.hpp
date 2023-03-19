#ifndef PARTICLE_DRAG_HPP
#define PARTICLE_DRAG_HPP
#include <cyclone/pfgen.hpp>

namespace cyclone {
    class ParticleDrag : public ParticleForceGenerator {
        real k1, k2;
    public:
        ParticleDrag(real k1, real k2) : k1(k1), k2(k2) {}
        virtual void updateForce(Particle *particle, real duration);
    };
}

#endif