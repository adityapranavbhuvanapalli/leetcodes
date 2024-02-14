class Solution {
public:
    int racecar(int target) {
        int steps = 0;
        queue<pair<long, long>> q;    // Position, Speed
        set<pair<int, int>> visited;

        q.push({0, 1});
        visited.insert({0, 1});
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                auto& [pos, speed] = q.front();

                if(pos == target)
                    return steps;

                // A
                if(visited.insert({pos + speed, speed * 2}).second)
                    q.push({pos + speed, speed * 2});

                // R
                // Perform R only if car is moving away from the target
                if(visited.insert({pos, -speed / abs(speed)}).second && 
                    ((pos + speed > target && speed > 0) || (pos + speed < target and speed < 0)))
                    q.push({pos, -speed / abs(speed)});

                q.pop();
            }
            steps++;
        }

        return steps;
    }
};

/*
A -> pos += speed; speed *= 2
R -> speed = speed < 0 ? 1 : -1

    0 .. n
  R  (AR)   R
 <-         ->

4 
pos:
0->1->3->
speed:
1->2->4->
*/