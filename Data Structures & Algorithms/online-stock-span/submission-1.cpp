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
    //      -> if curr element is greater than top stack value then push curr value with top stack span + 1 and pop the top element
    //      the reason this works is because we add the previous elements span if the curr element is greater because for any other elements after this element that is greater will also be greater than the previous elements also
    //      O(n) runtime complexity, we are iterating through n elements and popping at most n elements, O(n) space complexity, iterating through n elements and having up to n elemnets in stack
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