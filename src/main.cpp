#include <cyclone/core.hpp>
#include <cyclone/particle.hpp>
#include <cyclone/pfgen.hpp>
#include <cyclone/particleIntegrator.hpp>
#include <cyclone/forceGenerators/particleGravity.hpp>
#include <cyclone/forceGenerators/particleDrag.hpp>
#include <raylib.h>
#include <sstream>

using namespace std;
using namespace cyclone;

int main(int argc, char *argv[]) {
	InitWindow(1366, 768, "Physics Engine");
	SetTargetFPS(60);

	Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 20.0f, 50.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type	

	Particle p1, p2, p3;
	p1.setMass(10);
	p1.position = Vec3(10, 40, 0);
	p1.setDamping(1);
	p2.setMass(20);
	p2.position = Vec3(-10, 40, 0);
	p2.setDamping(1);
	p3.setMass(30);
	p3.position = Vec3(-5, 40, 0);
	p3.setDamping(1);

	ParticleForceRegistry registry;	  
	ParticleIntegrator integrator;

	ParticleGravity pg(Vec3(0.0, -10.0, 0.0));
	ParticleDrag pd(1.0, 1.0);

	registry.add(&pg, &p1, &p2, &p3);
	registry.add(&pd, &p1, &p2, &p3);

	integrator.add(&p1, &p2, &p3);

 	DisableCursor();
	while(!WindowShouldClose()) {
          UpdateCamera(&camera, CAMERA_FREE);
          std::stringstream ss;
          ss << "FPS: " << GetFPS();
		  registry.updateForces(GetFrameTime());

          BeginDrawing();
          ClearBackground(BLACK);
          BeginMode3D(camera);
          DrawCube(p1.position, 2, 2, 2,PINK);
          DrawCube(p2.position, 2, 2, 2, YELLOW);
          DrawCube(p3.position, 2, 2, 2, SKYBLUE);
          DrawGrid(100, 1.0f);
          EndMode3D();
          DrawText(ss.str().c_str(), 10, 10, 28, RED);
          EndDrawing();

		integrator.integrate(GetFrameTime());
	}

	CloseWindow();
    return 0;
}
