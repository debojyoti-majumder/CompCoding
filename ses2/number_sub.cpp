// Problem URL: https://leetcode.com/problems/additive-number/description/
class Solution {
public:
	bool isAdditiveNumber(string num, int firstOpLength = 1, int probeCount = 1) {
		// Base case
		if (num.length() == 2) return true;

		auto num_1_str(num.substr(0, firstOpLength));
		auto num_2_str(num.substr(firstOpLength, probeCount));
		
		auto num_1 = atoi(num_1_str.c_str());
		auto num_2 = atoi(num_2_str.c_str());

		auto digit_sum = num_1 + num_2;
		
		// Converting int to stream
		stringstream sum_stream;
		sum_stream << digit_sum;
		auto result_sum = sum_stream.str();

		auto target_num = num.substr(probeCount + 1, probeCount + result_sum.length() - 1);
		if ( target_num.compare(result_sum) == 0 ) {
			auto subItem = num.substr(firstOpLength);
			return isAdditiveNumber(subItem);
		}
		else {
			return isAdditiveNumber(num, 1,probeCount + 1);
		}
	}
};
