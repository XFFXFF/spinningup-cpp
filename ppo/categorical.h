#include "distribution.h"
#include <vector>

class Categorical : public Distribution
{
private:
	torch::Tensor probs;
	torch::Tensor logits;
	std::vector<int64_t> batch_shape;
	torch::Tensor param;
	int num_events;
	std::vector<int64_t> extended_shape(c10::ArrayRef<int64_t> sample_shape);

public:
	Categorical(const torch::Tensor *probs, const torch::Tensor *logits);

	torch::Tensor entropy();
	torch::Tensor log_prob(torch::Tensor value);
	torch::Tensor sample(c10::ArrayRef<int64_t> sample_shape);

	inline torch::Tensor get_logits() { return logits; }
	inline torch::Tensor get_probs() { return probs; }
};