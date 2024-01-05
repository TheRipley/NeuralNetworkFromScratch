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

Matrix Network::ForwardPropagation(const Matrix& input)
{
    Matrix output = input;
    for (int i=0; i<numLayers-1; i++)
    {
        output = layers[i].Calculate(output);
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
    
    for (int i=numLayers-2; i>=1; i--)
    {
        Layer* layer = &layers[1];

        // dC/dYpred
        Matrix costGradient = (output - expectedOutput) * 2.0f;

        std::cout << "1" <<std::endl;

        //dYpred/dZ
        Matrix dYpredOVdZ = layer->getZ();
        dYpredOVdZ = dYpredOVdZ.sechSquared();
        std::cout << "2" << std::endl;

        //dZ/dW
        Matrix dZOVdW = layer->getInput(); 
        std::cout << "3" << std::endl;
        //dZOVdW.Transpose();

        std::cout << costGradient <<std::endl;
        std::cout << dYpredOVdZ << std::endl;
        std::cout << dZOVdW << std::endl; 

        //W = W−α(∂Cost(y,ŷ)/∂W)

        Matrix hadam = HadamarProduct(costGradient, dYpredOVdZ, dZOVdW);
        std::cout << "4";
        std::cout << hadam << std::endl;
        layer->updateWeights(hadam, learningRate);
    }
}