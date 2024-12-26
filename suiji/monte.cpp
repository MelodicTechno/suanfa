#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

int main() {
    const int num_samples = 1000000;
    int inside_circle = 0;

    std::srand(std::time(0));

    for (int i = 0; i < num_samples; ++i) {
        double x = static_cast<double>(std::rand()) / RAND_MAX;
        double y = static_cast<double>(std::rand()) / RAND_MAX;

        if (std::sqrt(x * x + y * y) <= 1.0) {
            ++inside_circle;
        }
    }

    double pi_estimate = 4.0 * inside_circle / num_samples;
    std::cout << "Estimated value of Pi: " << pi_estimate << std::endl;

    return 0;
}