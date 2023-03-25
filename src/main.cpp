#include <cyclone/core.hpp>
#include <cyclone/particle.hpp>
#include <cyclone/pfgen.hpp>
#include <cyclone/particleIntegrator.hpp>
#include <cyclone/forceGenerators/particleGravity.hpp>
#include <cyclone/forceGenerators/particleDrag.hpp>
#include <cyclone/forceGenerators/particleSpring.hpp>
#include <raylib.h>
#include <sstream>
#include <iostream>

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

	Particle p1;
	p1.setMass(2);
	p1.position = Vec3(0, 45, 0);
	p1.setDamping(0.994);

	Vec3 anchor(0.0, 50.0, 0.0);

	ParticleForceRegistry registry;
	ParticleIntegrator integrator;

	ParticleGravity pg(Vec3(0.0, -10.0, 0.0));
	ParticleDrag pd(0.3, 0.4);
	ParticleAnchoredSpring pas(&anchor, 1.0, 2.0);

	registry.add(&pg, &p1);
	registry.add(&pd, &p1);
	registry.add(&pas, &p1);

	integrator.add(&p1);

	Ray r;
	RayCollision rcol;

 	DisableCursor();

	real lastX = GetMouseX();
	real lastY = GetMouseY();
	while(!WindowShouldClose()) {
       	  UpdateCamera(&camera, CAMERA_CUSTOM);

          std::stringstream ss;
          ss << "FPS: " << GetFPS();

		  registry.updateForces(GetFrameTime());
          BeginDrawing();
          ClearBackground(BLACK);
          BeginMode3D(camera);
		  DrawLine3D(p1.position, anchor, PINK);
		  DrawSphereEx(p1.position, 2, 100, 100, SKYBLUE);
		  DrawCube(anchor, 8, 1, 8, YELLOW);
          DrawGrid(100, 1.0f);
          EndMode3D();
          DrawText(ss.str().c_str(), 10, 10, 28, RED);
          EndDrawing();

		integrator.integrate(GetFrameTime());
		lastX = GetMouseX();
		lastY = GetMouseY();
	}

	CloseWindow();
    return 0;
}
