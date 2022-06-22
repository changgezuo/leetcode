class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slot1, vector<vector<int>>& slot2, int duration) {
        sort(slot1.begin(), slot1.end());
		sort(slot2.begin(), slot2.end());
		for(int i = 0, j = 0; i < slot1.size() && j < slot2.size()){
			int start = max(slot1[i][0], slot2[j][0]);
			int end = min(slot1[i][1], slot2[j][1]);
			if(end - start >= duration){
				return {start, start + duration};
			}
			if(slot1[i][1] > slot2[j][1]){
				j++;
			}else if(slot1[i][1] < slot2[j][1]){
				i++j;
			}else{
				i++;
				j++;
			}
		}
		return {};
    }
};