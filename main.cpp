#include "header.h"

std::default_random_engine generator;
std::uniform_real_distribution<float> distribution;


int main()
{
    const int epochs = 10;
    std::vector<Matrix> inputs;
    std::vector<Matrix> expectedOutputs;
    Matrix input;
    Matrix output;
    for (float i=0.0; i<1.0; i+=0.001)
    {
        input = Matrix((std::vector<std::vector<float>>){{(float)i}});
        inputs.push_back(input);
    }
    /*
    for(float i=0; i<100; i++)
    {
        std::cout << inputs[i] << std::endl;
    } */

    for (float i=0.0; i<1.0; i+=0.001)
    {
        output = Matrix((std::vector<std::vector<float>>){{(float)(i*i)}});
        expectedOutputs.push_back(output);
    }

    std::vector<Matrix> expectedOutput;
    
    std::vector<int> numNodesPerLayer = {1, 3, 5, 8, 5, 3, 1};
    std::vector<int> layersActivation = {RELU, RELU, RELU, SIGMOID, RELU, TANH};
    Network network(numNodesPerLayer, layersActivation, 0.01f); 
    Matrix testoutput;
    for (int epoch=0; epoch<epochs; epoch++){
        for (std::size_t j=0; j<inputs.size(); j++)
        {
            testoutput = network.ForwardPropagation(inputs[j]);
            network.BackwardPropagation(testoutput, expectedOutputs[j]);
        }
    }


    for(int i=0; i<100; i++)
    {
        std::cout << inputs[i] << ", " << network.ForwardPropagation(inputs[i]) << std::endl;
    } 
    return 0;
}
