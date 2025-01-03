#ifndef INERUALNETWORK_H
#define INERUALNETWORK_H


#include <math.h>
#include <vector>
#include <iostream>

#include "ILayerNeurons.h"

using namespace std;



class INerualNetwork
{ 
    //--- activation function
    float activation( float x , ILayerNeurons::LayerOutputType type )
    {
        if(type == ILayerNeurons::LayerOutputType::Sigmoid )
        {
            return 1.0 / ( 1.0 + std::exp(-x) );
        }
        else if(type == ILayerNeurons::LayerOutputType::Tanh )
        {
           return std::tanh(x);
        }
        else if(type == ILayerNeurons::LayerOutputType::ReLU )
        {
            return x >= 0 ? x : 0;
        }
    }

    //--- activation function derivative
    float derivative( float x )
    {
         return (x * (1.0 - x));
    }

public:

    /**
     * Deffault-Constructor
     * @param n_copy
     */
    INerualNetwork(){}

    /**
     * Copy-Constructor
     * @param n_copy
     */
    INerualNetwork(const INerualNetwork& n_copy);

    /**
     * Initilization-Constructor
     * @param n_copy
     */
    INerualNetwork(std::initializer_list<unsigned int>&& values);


    /**
     * Initilization-Constructor
     * @param n_copy
     */
    INerualNetwork(std::vector<unsigned int> NetworkStructure);

   // myNeuro();
    ~INerualNetwork();


    void InitRandom();


    /**
     * Compute the neural network output signal based on the input signal x_in.
     * The output signal can be accessed with the function getOutputActivation().
     * @param x_in Input signal.
     * @return true if successful.
     */
    float *feedForwarding(const float *_input);


    void backPropagate(const float *_inputes, const float *targetes,const float& learningRate);


    unsigned int getCountNeuronsOutput() const { return m_nOutputNeurons; }
    unsigned int getCountNeuronsInput() const { return m_nInputNeurons; }
    unsigned int getCountLayers() const { return m_nlCountLayers; }

    /**
     * Return a handle to the layer at index layerIdx.
     * @param layerIdx Layer index.
     * @return Null, if layer does not exist. Otherwise handle to layer.
     */
    ILayerNeurons* getLayer(int indx) const { return m_nLayers[indx]; }
    ILayerNeurons* getLayer(int indx) { return m_nLayers[indx]; }

    void CopyWeightAndErrorBias(const INerualNetwork& other);

    /**
     * Returns the structure of the neural network.
     * @return
     */
    std::vector<unsigned int> getNetworkStructure() const
    {
        return m_NetworkStructure;
    }

    /**
     * Serialize the network (layers).
     * @return string holding binary representation of the network.
     */
    string serialize() const;

    /**
     * Deserialize a binary representation of a network.
     * @param buffer Binaray data.
     * @return Initialized network
     */
    static INerualNetwork* deserialize(const string& buffer );

    /**
     * Save the current neuronal network to a file.
     * @param filePath Path to file.
     * @return True if successful, otherwise false.
     */
    bool save( const std::string& filePath );


    /**
     * Load a neuronal network from a file
     * @param filePath Path to file.
     * @return Initialized network
     */
    static INerualNetwork* load( const std::string& filePath );

private:

    int m_nInputNeurons;
    int m_nOutputNeurons;
    int m_nlCountLayers;

    std::vector<unsigned int> m_NetworkStructure;
    std::vector<ILayerNeurons*> m_nLayers;


};

#endif // INERUALNETWORK_H
