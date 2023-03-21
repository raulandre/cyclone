#include <cyclone/core.hpp>
#include <cyclone/particle.hpp>
#include <cyclone/pfgen.hpp>
#include <cyclone/particleIntegrator.hpp>
#include <cyclone/forceGenerators/particleGravity.hpp>
#include <cyclone/forceGenerators/particleDrag.hpp>
#include <cyclone/forceGenerators/particleSpring.hpp>
#include <raylib.h>
#include <sstream>

using namespace std;
using namespace cyclone;

int main(int argc, char *argv[]) {
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(1366, 768, "Physics Engine");
	SetTargetFPS(60);

	Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 20.0f, 50.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type	

	Particle p1, p2;
	p1.setMass(15);
	p1.position = Vec3(0, 45, 0);
	p1.setDamping(0.994);

	p2.setMass(100);
	p2.position = Vec3(0, 50, 0);

	ParticleForceRegistry registry;
	ParticleIntegrator integrator;

	ParticleGravity pg(Vec3(0.0, -10.0, 0.0));
	ParticleDrag pd(0.3, 0.4);
	ParticleSpring ps(&p2, 25.0f, 4.0f);

	registry.add(&pg, &p1);
	registry.add(&pd, &p1);
	registry.add(&ps, &p1, &p2);

	integrator.add(&p1, &p2);

 	DisableCursor();
	while(!WindowShouldClose()) {
		  PollInputEvents();
          UpdateCamera(&camera, CAMERA_CUSTOM);
          std::stringstream ss;
          ss << "FPS: " << GetFPS();
		  registry.updateForces(GetFrameTime());

		  if(IsKeyDown(KEY_J)) {
			p2.position -= Vec3(0, 1, 0);
		  }

		  if(IsKeyDown(KEY_K)) {
			p2.position += Vec3(0, 1, 0);
		  }

          BeginDrawing();
          ClearBackground(BLACK);
          BeginMode3D(camera);
		  DrawLine3D(p1.position, p2.position, PINK);
          DrawCube(p1.position, 2, 2, 2, SKYBLUE);
		  DrawCube(p2.position, 8, 1, 8, YELLOW);
          DrawGrid(100, 1.0f);
          EndMode3D();
          DrawText(ss.str().c_str(), 10, 10, 28, RED);
          EndDrawing();

		integrator.integrate(GetFrameTime());
	}

	CloseWindow();
    return 0;
}
