class Solution {
     stack<int>minSt;
          stack<int>mainSt;
        int minEle;
  public:
  
    Solution() {
        minEle=INT_MAX;
    }

    // Add an element to the top of Stack
    void push(int x) {
        
        mainSt.push(x);
        minEle=min(minEle,x);
        minSt.push(minEle);
    }

    // Remove the top element from the Stack
        
    void pop() {
        if(!mainSt.empty()){
            int topEle=mainSt.top();
            int minTop=minSt.top();
            mainSt.pop();
            minSt.pop();
            if(topEle==minTop){
                if(!minSt.empty()){
                    minEle=minSt.top();
                }
                else{
                    minEle=INT_MAX;
                }
            }
        }
    }

        
    // Returns top element of the Stack
    int peek() {
        // code here
        
        if(!mainSt.empty()){
            return mainSt.top();
        }
        return -1;
    }
        

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(!minSt.empty()){
            return minSt.top();
        }
        return -1;
    }
};