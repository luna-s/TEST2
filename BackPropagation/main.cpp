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
	double input_, output_;		// saved for back-prop
	double alpha_;	// learning rate


public:		// behavior
	double feedForward(const double& input_x)
	{
		input_ = input_x;

		const double sigma = w_ * input_ + b_;
		
		output_ = getActivation(sigma);

		return output_;
	}

	double getActivation(const double& x)
	{
		// linear or idenity activation function
		return x;

		// ReLU max(0.0, x);
		// return MAX2(0.0, x);
	}

	double getActGrad(const double& x)
	{
		// linear or idenity activation function
		return 1.0;

		// ReLU max(0.0, x);
		// return MAX2(0.0, 1.0);
	}

	void propBackward(const double& target)
	{
		const double grad = (output_ - target) * getActivation(output_);

		alpha_ = 0.1;

		w_ -= alpha_ * grad * input_;	//
		b_ -= alpha_ * grad * 1.0;		//
	}

	void feedForwardAndPrint(const double& input_x)
	{
		std::cout << w_ << " " << b_ << " " << feedForward(input_x) << std::endl;
	}

	friend std::ostream& operator << (std::ostream& stream, Neuron& n)
	{
		std::cout << n.w_ << " " << n.b_ << std::endl;

		return stream;
	}

};

void main()
{
	Neuron my_neuron(2.0, 1.0);
	my_neuron.alpha_ = 0.01;


	for (int i = 0; i < 10000; ++i)
	{
		std::cout << "Training " << i << std::endl;
		my_neuron.feedForwardAndPrint(2.0);
		my_neuron.propBackward(6.0);
		std::cout << "w= " << my_neuron.w_ << " b= " << my_neuron.b_ << std::endl;

	}
}