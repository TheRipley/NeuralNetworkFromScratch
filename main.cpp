#include "header.h"

std::default_random_engine generator;
std::uniform_real_distribution<float> distribution;

int main()
{

    Matrix input = (std::vector<std::vector<float>>){
        {1.0},
        {-4.0},
        {2.0},
        {-1.0}
    };
    std::vector<int> numNodesPerLayer = {4, 8, 8, 3};
    std::vector<int> layersActivation = {TANH, RELU, SIGMOID};
    Network network(numNodesPerLayer, layersActivation); 
    Matrix output = network.ForwardPropagation(input);
    std::cout << output << std::endl;
    return 0;
}
