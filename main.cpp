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
    Matrix expectedOutput = (std::vector<std::vector<float>>){
        {9.0},
        {3.0},
        {3.5}
    };
    std::vector<int> numNodesPerLayer = {4, 2, 4, 3};
    std::vector<int> layersActivation = {TANH, RELU, SIGMOID};
    Network network(numNodesPerLayer, layersActivation, 0.01f); 
    Matrix output;
    for (int i=0; i<10; i++){
        output = network.ForwardPropagation(input);
        network.BackwardPropagation(output, expectedOutput);
    }
    return 0;
}
