#include "header.h"

Network::Network()
    : layers({Layer()}), numLayers(1), learningRate(0.01f) {}

Network::Network(std::vector<int> numNodesPerLayer, std::vector<int> layersActivation, float learningRate)
    : learningRate(learningRate)
{
    numLayers = numNodesPerLayer.size();
    for (int n=1; n<numLayers; n++)
    {
        layers.push_back(Layer(numNodesPerLayer[n-1], numNodesPerLayer[n], layersActivation[n-1]));
    }
}

Network::Network(const Network& other)
    : layers(other.layers), numLayers(other.numLayers) {}

std::vector<Layer> Network::getLayers() {return layers;}

Matrix Network::ForwardPropagation(const Matrix& input)
{
    Matrix output = input;
    for (int i=0; i<numLayers-1; i++)
    {
        output = layers[i].Forward(output);
    }
    return output;
}

float Network::Cost(const Matrix& output, const Matrix& expectedOutput)
{
    float sum=0;
    for (int i=0; i<output.getHeight(); i++)
    {
        sum += pow((expectedOutput.getValues()[i][0] - output.getValues()[i][0]), 2);
    }
    return sum;

}

void Network::BackwardPropagation(const Matrix& output, const Matrix& expectedOutput)
{
    Matrix costGradient = (output - expectedOutput) * (2.0 / expectedOutput.getHeight());

    for (int i=numLayers-2; i>0; i--)
    {
        Layer* layer = &layers[i];
        costGradient = layer->Backward(costGradient, learningRate);
    }
}