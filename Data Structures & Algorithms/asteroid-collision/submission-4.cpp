class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // positive value = right, negative = left
        // will collide when + is to the left of -

        // stack -> iterate through all asteroids 
        // for current asteroid we're on 
        // while previous asteroid in stack is opposing directions 
        //      compare sizes 
        //      if prev bigger then continue
        //      else if same size then pop asteroid off and continue
        //      destroy top asteroid and continue while loop

        stack<int> asteroidStack;
        for (int i = 0; i < asteroids.size(); ++i) {
            int currAsteroid = asteroids[i];

            if (asteroidStack.empty()) {
                asteroidStack.push(currAsteroid);
                continue;
            }

            bool isAlive = true;
            while (!asteroidStack.empty() && isColliding(asteroidStack.top(), currAsteroid)) {
                    int prevAsteroid = asteroidStack.top();
                    if (prevAsteroid > abs(currAsteroid)) {
                        isAlive = false;
                        break;
                    } else if (prevAsteroid == abs(currAsteroid)) {
                        isAlive = false;
                        asteroidStack.pop();
                        break;
                    } else {
                        asteroidStack.pop();
                        continue;
                    }
                }
            

            if (isAlive) {
                asteroidStack.push(currAsteroid);
            }
        }

        vector<int> results;
        while (!asteroidStack.empty()) {
            results.push_back(asteroidStack.top());
            asteroidStack.pop();
        }
        
        reverse(results.begin(), results.end());
        return results;

    }

    bool isColliding(int n1, int n2) {
        return (n1 > 0 && n2 < 0);
    }
};