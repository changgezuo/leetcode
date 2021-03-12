
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
	    int sta = 0, len = words.size(), curS = 0, curLen = 0;
	    vector<string>ans;
	    bool flo = false;
	    while (sta < len) {
		    curLen = -1; curS = sta;
		    while (true) {
			    if (sta >= len) { flo = true; break; }
			    if (curLen + words[sta].size() + 1 > maxWidth)break;
			    curLen += words[sta++].size() + 1;
		    }
		    if (!flo) {
			     string t;
			     if (sta - curS != 1) {
				     int small = (maxWidth - curLen + sta - curS - 1) / (sta - curS - 1);
				     int largeN = maxWidth - curLen + sta - curS - 1 - small * (sta - curS - 1);
				     string emc;
				     for (int i = 0; i < small; ++i)emc += ' ';
				     for (int i = 0; i < largeN; ++i) {
					     t += words[i + curS];
					     t += emc;
					     t += ' ';
				     }
				     for (int i = largeN; i < sta - curS - 1; ++i) {
					     t += words[i + curS];
					     t += emc;
				     }
				     t += words[sta - 1];
			     }
			     else {
				      t += words[sta - 1];
				      int steps = maxWidth - t.size();
				      for (int i = 0; i < steps; ++i) {
					       t += ' ';
				      }
			      }
			      ans.push_back(t);
		      }
	      }
	      string t;
	      for (int i = curS; i < len; ++i) {
		       t += words[i];
		       t += ' ';
	      }
	      if (t.size() > maxWidth)t = t.substr(0, t.size() - 1);
	      else {
		        curLen = t.size();
		        for (int i = curLen; i < maxWidth; ++i) {
			          t += ' ';
		        }
	     }
	     ans.push_back(t);
	     return ans;
    }
};