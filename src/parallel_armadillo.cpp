#include <iostream>
#include <chrono>

#include <cassert>
#define ARMA_DONT_USE_WRAPPER
#include <armadillo>


/** Check whether a given (sparse) matrix is symmetric
 */
bool is_symmetric(arma::mat& A) {
    return arma::approx_equal(A, A.t(), "reldiff", 1.0e-8);
}
bool is_symmetric(arma::sp_mat& A) {
    return arma::approx_equal(A, A.t(), "absdiff", 1.0e-8);
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

arma::sp_mat random_sparse_symmetric_matrix(size_t dim) {
    arma::sp_mat A = arma::sprandu<arma::sp_mat>(dim, dim, 0.1);
    arma::sp_mat AT = A.t();
    arma::sp_mat S = A + A.t();

    assert(is_symmetric(S));
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

void time_sparse_diagonalization(std::vector<size_t> dims) {
    for(const auto& dim : dims) {
        // Prepare the random symmetric matrix
        arma::sp_mat A = random_sparse_symmetric_matrix(dim);

        // Time the diagonalization
        auto start = std::chrono::high_resolution_clock::now();
        arma::eigs_sym(A, 10);
        auto stop = std::chrono::high_resolution_clock::now();

        // Process the chrono time and output
        auto elapsed_time = stop - start;           // in nanoseconds
        auto seconds = elapsed_time.count() / 1e9;  // in seconds
        std::cout << dim << " : " << seconds << std::endl;
    }
}



int main () {

    std::vector<size_t> dims {50, 100, 250, 500, 1000, 2500, 5000, 10000};
    std::vector<size_t> sparse_dims {1000, 2500, 5000, 10000, 25000};

    // time_diagonalization(dims);
    time_sparse_diagonalization(sparse_dims);


    return 0;
}
