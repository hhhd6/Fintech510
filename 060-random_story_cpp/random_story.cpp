#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <random>

using namespace std;

int generate_random_number(int max, int seed) {
    // Usually, we would use "rd" to seed the random number generator
    // in non-test / non-reproducibility situations.
    //
    // Also, we wouldn't recreate the generator every call, but re-use
    // to generate a sequence of results.
    // using class static members would be a good place to hold these objects
    //
    // std::random_device rd;

    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distr(0, max); // closed interval
    return distr(gen);
}

int main(int argc, char *argv[]) {
    

}

