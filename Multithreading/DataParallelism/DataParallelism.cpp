#include <iostream>
#include <future>
#include <thread>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>    // std::generate
double accum(double *beg, double *end)
{
    double init;
    while (beg != end) init += *beg++;
    return init;
}

int randomNum()
{
    return std::rand();
}

double add_parallelism(std::vector<double> &vec)
{
    auto vec0 = &vec[0];
    auto vsize = vec.size();

    std::future<double> fut1 = std::async(accum, vec0, vec0 + vsize/4);
    std::future<double> fut2 = std::async(accum, vec0+vsize/4, vec0 + 2*vsize/4);
    std::future<double> fut3 = std::async(accum, vec0+2*vsize/4, vec0 + 3*vsize/4);
    std::future<double> fut4 = std::async(accum, vec0+3*vsize/4, vec0 + vsize);

    //reduce step: combine result
    return fut1.get() + fut2.get() + fut3.get() + fut4.get();
}

int main()
{
    //create a vector have 16 element.
    std::vector<double> vec(16);

    //create a vector have 16 element, and init with random value
    std::vector<double> vrand(10);
    std::generate(vrand.begin(), vrand.end(), randomNum);

    std::cout << accum(&vrand[0], &vrand[vrand.size()]) << std::endl;

    std::cout << add_parallelism(vrand) << std::endl;

    return 0;
}