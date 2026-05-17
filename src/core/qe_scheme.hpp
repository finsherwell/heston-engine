#include <math.h>

double qe_step(double v, double dt, double kappa, double theta, double xi, double z_v)
{
    double e = std::exp(-kappa * dt);
    double m = theta + (v - theta) * e;
    double s2 = v*xi*xi*e/kappa*(1-e) + theta*xi*xi/(2*kappa)*(1-e)*(1-e);
    double psi = s2 / (m * m);

    if (psi <= 1.5) { // Gaussian Regime
        double b2 = 2/psi - 1 + std::sqrt(2/psi*(2/psi-1));
        double a = m / (1 + b2);
        return a * std::pow(std::sqrt(b2) + z_v, 2);
    } else { // Exponential Regime
        double p = (psi-1) / (psi+1);
        double beta = (1-p) / m;
        double U = 0.5*(1 + std::erf(z_v/std::sqrt(2)));
        return U <= p ? 0.0 : -std::log((1-U)/(1-p))/beta;
    }
}