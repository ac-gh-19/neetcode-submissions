class StockSpanner {
private:
    stack<pair<int,int>> valueAndSpan;
public:
    // curr day that we're on accounts for +1 to the span
    // 1 solution = array 
    //      -> iterate through elements and for every element count back until start or value greater than curr
    //      O(n^2) runtime complexity, O(n) space complexity

    // 2 solution = stack
    //      -> iterate through elements pushing value and span
    //      -> if curr element is greater than top stack value then push curr value with top stack span + 1
    //      -> the reason why this works is for every new value we push onto the stack, we check if its greater than the top stacks value, if so it adds +1 to the span, we can then use this value and span to calculate if the next value being pushed on will contribute to the span or if its less than the top stack value the span will just become 1 indicating the start of a new sequence
    StockSpanner() {
    }
    
    int next(int price) {
        if (valueAndSpan.empty() || valueAndSpan.top().first > price) {
            valueAndSpan.push({price, 1});
            return 1;
        }

        int newSpan = 1;
        while (!valueAndSpan.empty() && price >= valueAndSpan.top().first) {
            newSpan += valueAndSpan.top().second;
            valueAndSpan.pop();
        }

        valueAndSpan.push({price, newSpan});
        return newSpan;


    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */