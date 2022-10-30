double dotproduct(double* v, double* u, int n)
{
    int i;
    double result = 0;

    #pragma omp parallel default(none) shared(n, result, u, v)
    {
    #pragma omp for reduction(+: result) schedule(auto)
    for (i = 0; i < n; i++) {
        result += v[i] * u[i];
    }
    } // end parallel

    return result;
}
