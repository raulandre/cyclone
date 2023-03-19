#include <cyclone/pfgen.hpp>
#include <algorithm>

void cyclone::ParticleForceRegistry::updateForces(real duration) {
    for(auto &registry : registrations) {
        registry.fg->updateForce(registry.particle, duration);
    }
}

void cyclone::ParticleForceRegistry::remove(Particle *particle, ParticleForceGenerator *fg) {
    registrations.erase(std::remove_if(
        registrations.begin(), registrations.end(),
        [&](const auto &registration) {
            return registration.particle == particle && registration.fg == fg;
        }), registrations.end());
}

void cyclone::ParticleForceRegistry::clear() {
    registrations.clear();
}