module;

#include <algorithm>
#include <ranges>
#include <stdexcept>

module NeuralNetwork;

OutputNeuron::OutputNeuron(const size_t index)
    : index_(index)
{};

Neuron::Neuron(const size_t index, const unsigned int weightsSize)
    : OutputNeuron(index)
{
    weights_.reserve(weightsSize);
}

Layer::Layer(const unsigned int size)
{
    neurons_.reserve(size);
    for (size_t i = 0; i < size; i++)
        neurons_.emplace_back(Neuron(i, size));
}

void Layer::calculateTargetLayer(Layer& targetLayer)
{
    if (std::ranges::any_of(neurons_, [&](const auto& neuron)
        {
            return neuron.getWeights().size() != targetLayer.getNeurons().size();
        }))
    {
        throw std::runtime_error("Different weights and targetLayer size!");
    }

    for (auto& targetNeuron : targetLayer.getNeurons())
    {
        this->calculateTargetNeuron(targetNeuron);
    }
}

