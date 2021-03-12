class FreqStack {
public:
    FreqStack() {

    }

    void push(int x) {
        freq_rec.insert({++freq[x], x});
    }

    int pop() {
        int cur = freq_rec.begin()->second;
        freq_rec.erase( freq_rec.begin());
        --freq[cur];
        return cur;
    }
private:
    unordered_map <int, int> freq;
    multimap <int, int, greater_equal<int>> freq_rec;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
