class Solution {
public:

    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
		sort(courses.begin(), courses.end(),[](vector<int> &a, vector<int> &b){
			return a[1] < b[1];
		});
		int curTime = 0;
		priority_queue<int>pq;
		for(auto &a : courses){
			curTime += a[0];
			pq.push(a[0]);
			if(curTime > a[1]){
				curTime -= pq.top();
				pq.pop();
			}
			
		}
		return pq.size();
    }
};

