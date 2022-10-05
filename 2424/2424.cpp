class LUPrefix {
public:
    LUPrefix(int n) {
        v.resize(n + 1, 0);
        v[0] = 1;
    }
    
    void upload(int video) {
        v[video] = 1;
    }
    
    int longest() {
        int res = 0, i = longest2 + 1;
        for(; i < v.size(); ++i){
            if(v[i] == 0)break;
        }
        longest2 = i - 1;
        res = longest2;
        return res ;
    }
private:
    vector<int>v;
    int longest2 = -1;
    
};
