class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i = 0, n = heights.size();
        priority_queue<int> pq;

        for(int i=0; i<n-1; i++) {
            int diff = heights[i + 1] - heights[i];
        
            // For jumping down, no need of bricks or ladders
            if(diff <= 0)
                continue;

            // If bricks are available, use 'diff' bricks to move forward
            if(bricks >= diff) {
                pq.push(diff);
                bricks -= diff;
                continue;
            }

            // If bricks are not available and ladders are zero
            if(ladders == 0) 
                return i;

            // If bricks are not available and ladders are there, use ladders for the biggest jump till i+1
            // The biggest jump can be current or previous 
            // If it is previous, then use the ladder instead of the bricks and increment the bricks by that amount
            if(pq.size() && diff < pq.top()) {
                bricks += pq.top() - diff;
                pq.pop();
                pq.push(diff);
            }
            
            ladders--;
        }

        return n - 1;
    }
};

/*
ladders = 2
bricks = 10

4   12  2   7   3   18  20  3   19
    8       5       15  2       16

8   5   15  2   16


pq(maxHeap): 15 5
ladders = 0
bricks = 10

4   2   7   6   9   14  12
        5       3   5   

5   3   5
1   3   4
    i
bricks = 5
ladders = 1

pq: 5
*/