#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include <emscripten.h>

EM_JS(void, printResults, (const char* log1, const char* log2), {
  document.getElementById('resultCpp').innerHTML = UTF8ToString(log1,4096) + '<br>' + UTF8ToString(log2,4096);
});

double mcpi(int loop)
{
    int c = 0;
    srand(time(NULL));
    int i;
    for (i = 0; i < loop; i++)
    {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1)
        {
            c++;
        }
    }
    return double(c) / double(loop) * 4.0;
}

EMSCRIPTEN_KEEPALIVE
int main()
{
    int iter = 100000000;
    clock_t start = clock();
    double pi = mcpi(iter);
    clock_t end = clock();
    double elapsed = (end - start) / (CLOCKS_PER_SEC / 1000);
    stringstream ss1;
    stringstream ss2;
    ss1 << "elapsed time: " << elapsed << "ms";
    ss2 << "iterations: " << iter << ", estimated value: " << pi;
    string log1 = ss1.str();
    string log2 = ss2.str();
    cout << log1 << "\n"
         << log2 << "\n";
    printResults(log1.c_str(), log2.c_str());
    return 0;
}
