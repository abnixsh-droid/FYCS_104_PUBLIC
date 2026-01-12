#include <iostream>
#include <iomanip>   // for std::setw and precision
#include <cmath>     // for sin() and M_PI
#include <vector>

int main() {
    const double L = 1.0;          // box length (normalized to 1)
    const int n_max = 4;           // show first 4 states
    const int points = 100;        // number of x points to sample

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "=== Particle in a 1D Box (Infinite Square Well) ===\n";
    std::cout << "Box length L = " << L << "\n";
    std::cout << "Wave function ψ_n(x) = sqrt(2/L) * sin(n π x / L)\n\n";

    std::vector<double> x(points);
    for (int i = 0; i < points; ++i) {
        x[i] = i * L / (points - 1.0);
    }

    for (int n = 1; n <= n_max; ++n) {
        double norm = std::sqrt(2.0 / L);   // normalization constant

        std::cout << "State n = " << n << "   (E ~ n²)\n";
        std::cout << "   x          ψ_n(x)         |ψ_n(x)|²\n";
        std::cout << "--------------------------------------------\n";

        for (int i = 0; i < points; ++i) {
            double psi = norm * std::sin(n * M_PI * x[i] / L);
            doule prob = psi * psi;

            std::cout << std::setw(6) << x[i] << "   "
                      << std::setw(12) << psi << "   "
                      << std::setw(12) << prob << "\n";
        }
        std::cout << "\n";
    }

    std::cout << "Note: Energies scale as E_n ∝ n²\n";
    std::cout << "      Probability |ψ|² is highest where sine peaks.\n";

    return 0;
}
