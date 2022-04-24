class UndergroundSystem {
public:
    map<int,pair<string,int>> checkin;
    map<string,pair<int,int>> routes;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t){
        checkin[id]=make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t){
        auto check=checkin[id];
        auto route=check.first+" "+stationName;
        routes[route].first+=t-check.second;
        routes[route].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto route=startStation+" "+endStation;
        if(!routes.count(route))return 0;
        return (double)routes[route].first/routes[route].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */