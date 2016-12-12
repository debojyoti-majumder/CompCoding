class Solution {
public:
    bool isAnagram(string s, string t) {
	    if (s.length() != t.length())
		  return false;

	    for (auto ch : s) {
		    size_t findPos = t.find(ch);
		
		    if (findPos == -1)
			    return false;
		    else
			    t.erase(t.begin() + findPos);
	    }

	    auto bRet = t.length() ? false : true;
	    return bRet;        
  }
};
