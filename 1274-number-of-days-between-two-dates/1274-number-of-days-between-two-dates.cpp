class Solution {
public:
    bool ly(int y){
        return ((y%4==0 && y%100!=0) || (y%400==0));
    }
    int dis(int y , int m , int d){
        int ans=0;
        vector<int>v{31,28,31,30,31,30,31,31,30,31,30,31};
        for(int i=1971; i<y; i++){
            ans=ans+365+ly(i);
        }
        for(int i=1; i<m; i++){
            ans=ans+v[i-1];
        }
        ans=ans+d;
        if(m>2 && ly(y)){
            ans=ans+1;
        }
        return ans;
    }
    int daysBetweenDates(string date1, string date2){
        int y1=stoi(date1.substr(0,4));
        int m1=stoi(date1.substr(5,2));
        int d1=stoi(date1.substr(8,2));
        int y2=stoi(date2.substr(0,4));
        int m2=stoi(date2.substr(5,2));
        int d2=stoi(date2.substr(8,2));
        return abs(dis(y1,m1,d1)-dis(y2,m2,d2));
    }
};