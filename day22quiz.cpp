#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <chrono>

using namespace std;

const size_t num_elements = 10000;

std::mt19937_64 eng(1842);
std::uniform_real_distribution<> distr(23.0, 89.0);

vector<double>* get_speed_data_as_vector() {
    vector<double>* result = new vector<double>();
    for (size_t i = 0; i < num_elements; i++) {
        result->insert(result->begin(),distr(eng));
    }
    return result;
}

list<double>* get_speed_data_as_list() {
    list<double>* result = new list<double>();
    for (size_t i = 0; i < num_elements; i++) {
        result->insert(result->begin(),distr(eng));
    }
    return result;
}

template<typename Iterator>
Iterator high(Iterator first, Iterator last) {
    Iterator high = first;
    for (Iterator p = first; p!=last; ++p)
    if (*high<*p) high = p;
    
    return high;
}


int main() {
    int num = 0;

    auto start = chrono::high_resolution_clock::now();
    vector<double>* speed_vector = get_speed_data_as_vector();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "duration of get_speed_data_as_vector(): " << duration.count() << "\n";

    start = chrono::high_resolution_clock::now();
    list<double>* speed_list = get_speed_data_as_list();
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "duration of get_speed_data_as_list(): " << duration.count() << "\n";

    start = chrono::high_resolution_clock::now();
    std::cout << "Max vector: " << *high(speed_vector->begin(), speed_vector->end()) << "\n";
    std::cout << "Max list: " << *high(speed_list->begin(), speed_list->end()) << "\n";

    // Uncomment the following lines, run the code, and paste your output. 
    //std::cout << "Min vector: " << *low(speed_vector->begin(), speed_vector->end()) << "\n";
    //std::cout << "Min list: " << *low(speed_list->begin(), speed_list->end()) << "\n";
    
    delete speed_list;
    delete speed_vector;
   
}
