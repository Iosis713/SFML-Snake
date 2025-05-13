module;

#include "Config.hpp"
#include <vector>

export module NeuralNetwork;

export class OutputNeuron
{
protected:
    size_t index_ = 0;
    float value_ = 0.0f;

public:
    OutputNeuron() = default;
    OutputNeuron(const size_t index);
    OutputNeuron(const OutputNeuron& neuron) = default;
    OutputNeuron(OutputNeuron&& neuron) = default;
    OutputNeuron& operator=(const OutputNeuron& neuron) = default;
    OutputNeuron& operator=(OutputNeuron&& neuron) = default;
    virtual ~OutputNeuron() = default;
    float getValue() const { return this->value_; };
    void setValue(const float value) { this->value_ = value; };
    size_t index() const { return this->index_; };
};

export class Neuron : public OutputNeuron
{
protected:
    std::vector<float> weights_;

public:
    Neuron() = default;
    Neuron(const Neuron& neuron) = default;
    Neuron(Neuron&& neuron) = default;
    Neuron& operator=(const Neuron& neuron) = default;
    Neuron& operator=(Neuron&& neuron) = default;
    Neuron(const size_t index, const unsigned int weightsSize);
    ~Neuron() = default;
    
    std::vector<float> getWeights() const { return weights_; };
};

export class Layer
{
private:
    std::vector<Neuron> neurons_;

public:
    Layer() = delete;
    Layer(const unsigned int size);
    ~Layer() = default;
    void calculateTargetLayer(Layer& targetLayer);

    
    std::vector<Neuron>& getNeurons() { return neurons_; };

    template<typename NeuronClass>
    void calculateTargetNeuron(NeuronClass& targetNeuron)
    {
        float resultValue = 0.0f;
        const size_t targetIndex = targetNeuron.index();
        
        for(const auto& sourceNeuron : neurons_)
        {
            resultValue += sourceNeuron.getValue() * sourceNeuron.getWeights().at(targetIndex);    
        }
        targetNeuron.setValue(resultValue);
    }
    
};