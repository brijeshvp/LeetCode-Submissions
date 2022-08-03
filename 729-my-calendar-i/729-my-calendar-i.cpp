class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        auto nextToStart = mp.upper_bound(start);
        if(nextToStart!=mp.end() && nextToStart->second<end)return false;
        
        mp.insert({end,start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */