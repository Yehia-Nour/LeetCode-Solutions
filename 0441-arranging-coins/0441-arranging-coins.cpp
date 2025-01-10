class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
       while(n > 0)
       {
           n -= i;      
           i++;
           if(n < i)
           break;
          
       }
       return i - 1;
    }
};