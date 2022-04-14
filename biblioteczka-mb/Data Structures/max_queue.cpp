template <typename T>
struct max_queue{

    deque<pair<T, int>> Q;

    void push(T val){
        int counter = 0;

        while(!Q.empty() && val >= Q.front().first){
            counter += Q.front().second + 1;
            Q.pop_front();
        }
        Q.push_front({val, counter});
    }

    void pop(){
        if(Q.back().second == 0) Q.pop_back();
        else Q.back().second--;
    }

    T max(){
        if(Q.empty()) return numeric_limits<T>::min();
        return Q.back().first;
    }
    
    bool empty(){
        return Q.empty();
    }
};