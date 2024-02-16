class StockPrice {
public:
    unordered_map<int, int> pricePerTime;  //(time, price)
    priority_queue<pair<int, int>> maxHeap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    int latestTime;
    
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        maxHeap.push({price, timestamp});
        minHeap.push({price, timestamp});

        pricePerTime[timestamp] = price;
        latestTime = max(latestTime, timestamp);
    }
    
    int current() {
        return pricePerTime[latestTime];
    }
    
    int maximum() {
        while(maxHeap.size() && pricePerTime[maxHeap.top().second] != maxHeap.top().first) {
            maxHeap.pop();
        }

        return maxHeap.top().first;
    }
    
    int minimum() {
        while(minHeap.size() && pricePerTime[minHeap.top().second] != minHeap.top().first) {
            minHeap.pop();
        }

        return minHeap.top().first;
    }
};

/*
1 - 10,3
2 - 5
4 - 2

pq:
{10,1}  {5,2}   {3, 1}  {2,4}   

set:
{10,1}

*/

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */