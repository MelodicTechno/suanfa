#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_PARTICLES = 30;
const int NUM_DIMENSIONS = 2;
const int MAX_ITERATIONS = 1000;
const double INERTIA_WEIGHT = 0.5;
const double COGNITIVE_WEIGHT = 1.5;
const double SOCIAL_WEIGHT = 1.5;

struct Particle {
    vector<double> position;
    vector<double> velocity;
    vector<double> best_position;
    double best_value;

    Particle() {
        position.resize(NUM_DIMENSIONS);
        velocity.resize(NUM_DIMENSIONS);
        best_position.resize(NUM_DIMENSIONS);
        best_value = numeric_limits<double>::max();
    }
};

double objective_function(const vector<double>& position) {
    // Example: Sphere function
    double sum = 0.0;
    for (double x : position) {
        sum += x * x;
    }
    return sum;
}

void initialize_particles(vector<Particle>& particles) {
    for (Particle& particle : particles) {
        for (int d = 0; d < NUM_DIMENSIONS; ++d) {
            particle.position[d] = ((double) rand() / RAND_MAX) * 10 - 5;
            particle.velocity[d] = ((double) rand() / RAND_MAX) * 2 - 1;
            particle.best_position[d] = particle.position[d];
        }
        particle.best_value = objective_function(particle.position);
    }
}

void update_particles(vector<Particle>& particles, const vector<double>& global_best_position) {
    for (Particle& particle : particles) {
        for (int d = 0; d < NUM_DIMENSIONS; ++d) {
            double r1 = (double) rand() / RAND_MAX;
            double r2 = (double) rand() / RAND_MAX;

            particle.velocity[d] = INERTIA_WEIGHT * particle.velocity[d] +
                                   COGNITIVE_WEIGHT * r1 * (particle.best_position[d] - particle.position[d]) +
                                   SOCIAL_WEIGHT * r2 * (global_best_position[d] - particle.position[d]);

            particle.position[d] += particle.velocity[d];
        }

        double value = objective_function(particle.position);
        if (value < particle.best_value) {
            particle.best_value = value;
            particle.best_position = particle.position;
        }
    }
}

int main() {
    srand(time(0));

    vector<Particle> particles(NUM_PARTICLES);
    initialize_particles(particles);

    vector<double> global_best_position(NUM_DIMENSIONS);
    double global_best_value = numeric_limits<double>::max();

    for (int iter = 0; iter < MAX_ITERATIONS; ++iter) {
        for (const Particle& particle : particles) {
            if (particle.best_value < global_best_value) {
                global_best_value = particle.best_value;
                global_best_position = particle.best_position;
            }
        }

        update_particles(particles, global_best_position);

        cout << "Iteration " << iter + 1 << ": Best Value = " << global_best_value << endl;
    }

    cout << "Global Best Value: " << global_best_value << endl;
    cout << "Global Best Position: ";
    for (double x : global_best_position) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}