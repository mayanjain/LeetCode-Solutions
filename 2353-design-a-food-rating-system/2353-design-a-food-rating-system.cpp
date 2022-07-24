class FoodRatings {
    struct cmp {
        bool operator() (pair<string,int> a, pair<string,int> b) const {
            return a.second!=b.second?a.second>b.second:a.first<b.first;
        }
    };
    
    map<string,set<pair<string,int>,cmp>> menu;
    map<string,string> type;
    map<string,int> rate;
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0 ; i<foods.size() ; i++){
            menu[cuisines[i]].insert({foods[i],ratings[i]});
            type[foods[i]]=cuisines[i];
            rate[foods[i]]=ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        auto it=menu[type[food]].find({food,rate[food]});
        menu[type[food]].erase(it);
        menu[type[food]].insert({food,newRating});
        rate[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        auto it=*menu[cuisine].begin();
        // cout<<it.second;
        return it.first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */