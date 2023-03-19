#ifndef PARTICLE_INTEGRATOR_HPP
#define PARTICLE_INTEGRATOR_HPP
#include "cyclone/particle.hpp"
#include <cyclone/core.hpp>
#include <vector>

namespace cyclone {
class ParticleIntegrator {
  typedef std::vector<Particle*> Registry;
  Registry registry;

public:
  ParticleIntegrator() {}
  void add() {}
  template <typename F, typename... P> void add(F particle, P... params) {
    registry.emplace_back(particle);
    add(params...);
  }
  void integrate(real duration) {
    for(auto &particle : registry) {
        particle->integrate(duration);
    }
  }
};
}


#endif