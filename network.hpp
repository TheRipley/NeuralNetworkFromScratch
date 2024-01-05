#include "header.h"

#ifndef NETWORK_HPP
#define NETWORK_HPP
struct Network
{
private:
    std::vector<Layer> layers;
    int numLayers;
    float learningRate;
public:
    Network();
    Network(std::vector<int> numNodesPerLayer, std::vector<int> layersActivation, float learningRate);
    Network(const Network& other);

    //Network& operator=(const Network&);

    Matrix ForwardPropagation(const Matrix& input);
    void BackwardPropagation(const Matrix& output, const Matrix& expectedOutput);
    float Cost(const Matrix& output, const Matrix& expectedOutput);

};
#endif