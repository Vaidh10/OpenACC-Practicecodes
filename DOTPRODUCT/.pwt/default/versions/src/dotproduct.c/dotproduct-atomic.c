double dotproduct(double* v, double* u, int n)
{
    int i;
    double result = 0;

    #pragma omp parallel default(none) shared(n, result, u, v)
    {
    #pragma omp for schedule(auto)
    for (i = 0; i < n; i++) {
        #pragma omp atomic update
        result += v[i] * u[i];
    }
    } // end parallel

    return result;
}
