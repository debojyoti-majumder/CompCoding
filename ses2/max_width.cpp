class Solution {
private:
	map<int, vector<int>> _depToPosVector;
	void updateMapInfo(int d, int pos) {
		auto it = _depToPosVector.find(d);

		if (it == _depToPosVector.end()) {
			_depToPosVector.insert(make_pair(d, vector<int>({ pos })));
		}
		else
			it->second.push_back(pos);
	}

	void treeTraversor(TreeNode* nd, int depth, int pos) {
		if( nd != nullptr ) {
			updateMapInfo(depth, pos);
			treeTraversor(nd->left, depth + 1, pos - 1);
			treeTraversor(nd->right, depth + 1, pos + 1);
		}
	}

public:
	int widthOfBinaryTree(TreeNode* root) {
		// This method should build depth map
		treeTraversor(root, 0, 0);
		vector<int> depthValues;

		for (auto it = _depToPosVector.begin(); it != _depToPosVector.end(); it++) {
			auto v = it->second;

			auto max_it = max_element(v.begin(), v.end());
			auto min_it = min_element(v.begin(), v.end());

			depthValues.push_back(*max_it - *min_it);
		}

		auto ret_it =  max_element(depthValues.begin(), depthValues.end());
		return *ret_it;
	}
};
