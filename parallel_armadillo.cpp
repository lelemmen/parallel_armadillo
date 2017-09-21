#include <omp.h>
#include <iostream>
#include <armadillo>

void symm_diag(std::vector<unsigned>& dims) {
    std::cout << "Diagonalizing symmetric matrices" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    for (const auto& dim : dims) {
        const clock_t begin_time = clock();

        arma::mat A (dim, dim, arma::fill::randu);
        A = A + A.t();

        arma::vec eigenvalues;
        arma::mat eigenvectors;

        arma::eig_sym(eigenvalues, eigenvectors, A);
        std::cout << "dim: "  << dim << "\t diagonalization time: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << " seconds" << std::endl;
    }
}


int main () {

#if defined(_OPENMP)
    std::cout << "Number of processors available: " << omp_get_num_procs() << std::endl;
    std::cout << "Maximum number of threads: " << omp_get_max_threads() << std::endl;
#endif

    std::vector<unsigned> dims = {100, 250, 500, 1000, 2500, 5000, 10000};

    symm_diag(dims);
}