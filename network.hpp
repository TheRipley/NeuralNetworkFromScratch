#include "header.h"

#ifndef NETWORK_HPP
#define NETWORK_HPP
struct Network
{
private:
    std::vector<Layer> layers;
    int numLayers;
public:
    Network();
    Network(std::vector<int> numNodesPerLayer, std::vector<int> layersActivation);

    Matrix ForwardPropagation(const Matrix& input);
    void BackwardPropagation(const Matrix& expectedOutput);

};
#endif