#include "header.h"

std::default_random_engine generator;
std::uniform_real_distribution<float> distribution;


int main()
{
    std::vector<Matrix> inputs;
    std::vector<Matrix> expectedOutputs;
    Matrix input;
    Matrix output;
    for (float i=0.0; i<1.0; i+=0.01)
    {
        input = Matrix((std::vector<std::vector<float>>){{(float)i}});
        inputs.push_back(input);
    }

    for(float i=0; i<100; i++)
    {
        std::cout << inputs[i] << std::endl;
    } 

    for (float i=0.0; i<1.0; i+=0.01)
    {
        output = Matrix((std::vector<std::vector<float>>){{(float)(i*i)}});
        expectedOutputs.push_back(output);
    }

    std::vector<Matrix> expectedOutput;
    
    std::vector<int> numNodesPerLayer = {1, 3, 2, 1};
    std::vector<int> layersActivation = {TANH, TANH, TANH};
    Network network(numNodesPerLayer, layersActivation, 0.01f); 
    std::cout << network.getLayers()[2].getWeights() << std::endl;
    Matrix testoutput;
    for (int i=0; i<100; i++){
        for (int j=0; j<inputs.size(); j++)
        {
            testoutput = network.ForwardPropagation(inputs[j]);
            network.BackwardPropagation(testoutput, expectedOutputs[j]);
        }
    }

    std::cout << network.getLayers()[0].getWeights() << std::endl;
    std::cout << network.getLayers()[0].getBiases() << std::endl;


    for(int i=0; i<100; i++)
    {
        std::cout << i << ", " << network.ForwardPropagation(inputs[i]) << std::endl;
    } 
    return 0;
}
