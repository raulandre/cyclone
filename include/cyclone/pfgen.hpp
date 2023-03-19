#ifndef PFGEN_HPP
#define PFGEN_HPP
#include <cyclone/particle.hpp>
#include <cyclone/core.hpp>
#include <vector>

namespace cyclone {
    class ParticleForceGenerator {
    public:
        virtual void updateForce(Particle *particle, real duration) = 0;
    };

    class ParticleForceRegistry {
    protected:
        struct ParticleForceRegistration {
            Particle *particle;
            ParticleForceGenerator *fg;
        };

        typedef std::vector<ParticleForceRegistration> Registry;
        Registry registrations;

    public:
        void add(ParticleForceGenerator*) {}
        template <typename F, typename P, typename... R>
        void add(F fg, P particles, R ...params) {
            struct ParticleForceRegistration reg = {.particle = particles,
                                                    .fg = fg};
            registrations.emplace_back(std::move(reg));
            cyclone::ParticleForceRegistry::add(fg, params...);
        }
        void remove(Particle *particle, ParticleForceGenerator *fg);
        void clear();
        void updateForces(real duration);
    };
}

#endif