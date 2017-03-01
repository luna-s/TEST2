#include <iostream>

#define MAX2(a, b) (a) > (b) ? (a) : (b)

class Neuron
{
	
public:
	Neuron()
		:w_(0.0), b_(0.0)
	{}

	Neuron(const double& input_w, const double& input_b)
		:w_(input_w), b_(input_b)
	{}


public:		// attributes
	double w_;	// weight of an input
	double b_;	// bias

	
public:		// behavior
	double feedForward(const double& input_x)
	{
		const double sigma = w_ * input_x + b_;

		return getActivation(sigma);
	}

	double getActivation(const double& x)
	{
		// linear or idenity activation function
		return x;

		// ReLU max(0, x);
		// return MAX2(0, x);
	}

	friend std::ostream& operator << (std::ostream& stream, Neuron& n)
	{
		std::cout << n.w_ << " " << n.b_ << std::endl;

		return stream;
	}

};

void main()
{
	Neuron my_neuron(1.1, 3.3);

	std::cout << my_neuron << " " << my_neuron.feedForward(3.0) << std::endl;

}