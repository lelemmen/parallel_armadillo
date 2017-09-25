#include <iostream>
#include <chrono>

#include <cassert>
#define ARMA_DONT_USE_WRAPPER
#include <armadillo>


/** Check whether a given matrix is symmetric
 */
bool is_symmetric(arma::mat& A) {
    return arma::approx_equal(A, A.t(), "reldiff", 1.0e-8);
}

/** Return a random symmetric matrix
 */
arma::mat random_symmetric_matrix(size_t dim) {
    arma::mat A (dim, dim, arma::fill::randu);
    arma::mat AT = A.t();
    arma::mat S = A + AT;           // The sum of a matrix and its transpose is symmetric

    assert(is_symmetric(S));        // Double-check that S is symmetric
    return S;
}




void time_diagonalization(std::vector<size_t> dims) {
    for(const auto& dim : dims) {
        // Prepare the random symmetric matrix
        arma::mat A = random_symmetric_matrix(dim);

        // Time the diagonalization
        auto start = std::chrono::high_resolution_clock::now();
        arma::eig_sym(A);
        auto stop = std::chrono::high_resolution_clock::now();

        // Process the chrono time and output
        auto elapsed_time = stop - start;           // in nanoseconds
        auto seconds = elapsed_time.count() / 1e9;  // in seconds
        std::cout << dim << " : " << seconds << std::endl;
    }
}



int main () {

    std::vector<size_t> dims {50, 100, 250, 500, 1000, 2500, 5000, 10000};

    time_diagonalization(dims);


    return 0;
}
