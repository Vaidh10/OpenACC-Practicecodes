double dotproduct(double* v, double* u, int n)
{
    int i;
    double result = 0;

    #pragma omp parallel default(none) shared(n, result, u, v)
    {
    // preamble
    double result_private = 0;
    // end preamble
    #pragma omp for schedule(auto)
    for (i = 0; i < n; i++) {
        result_private += v[i] * u[i];
    }
    // postamble
    #pragma omp atomic update
    result += result_private;
    // end postamble
    
    } // end parallel

    return result;
}
