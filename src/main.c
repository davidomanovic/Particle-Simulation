#define WIN32_LEAN_AND_MEAN // Define only once
#define NOMINMAX            // Define only once to prevent min/max conflicts
#define GLFW_INCLUDE_NONE   // Prevent GLFW from including OpenGL headers

#include <Windows.h>
#include <GL/gl.h>          // Include after Windows.h
#include <GLFW/glfw3.h>

#include "particles.h"


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

ParticleObject particles[N_PARTICLES];

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        return -1;  // If initialization fails, return an error code
    }

    // Create a windowed mode window and OpenGL context
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Particle Simulation", NULL, NULL);
    if (!window) {
        glfwTerminate();  // If window creation fails, terminate GLFW
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize particles
    initializeParticles(particles, N_PARTICLES);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Update particles
        float deltaTime = 0.016f;  // Assume ~60 FPS
        simulateParticles(particles, N_PARTICLES, deltaTime);

        // Render particles
        renderParticles(particles, N_PARTICLES);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup and close window
    glfwDestroyWindow(window);  // Destroy the created window
    glfwTerminate();  // Terminate GLFW to clean up resources

    return 0;
}