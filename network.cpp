#include "header.h"

Network::Network()
    : layers({Layer()}), numLayers(1) {}

Network::Network(std::vector<int> numNodesPerLayer, std::vector<int> layersActivation)
{
    numLayers = numNodesPerLayer.size();
    for (int n=1; n<numLayers; n++)
    {
        layers.push_back(Layer(numNodesPerLayer[n-1], numNodesPerLayer[n], layersActivation[n]));
    }
}

Matrix Network::ForwardPropagation(const Matrix& input)
{
    Matrix output = input;
    std::cout << output << std::endl;
    for (int i=0; i<numLayers-1; i++)
    {
        output = layers[i].Calculate(output);
        std::cout << output << std::endl;
    }
    return output;
}