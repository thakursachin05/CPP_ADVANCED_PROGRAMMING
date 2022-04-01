#include<bits/stdc++.h>

using namespace std;

struct point{
    int x,y;
    bool operator < (point P) const {
        if(x==P.x) return y<P.y;
        else return x<P.x;
    }
    bool operator == (point P) const {
        return (x == P.x && y = P.y);
    }
};

bool cw(point a, point b, point c){
    return a.x*(c.y-b.y)+b.x*(a.y-c.y)+c.x*(b.y-a.y)>0;
}
bool ccw(point a, point b, point c){
    return a.x*(c.y-b.y)+b.x*(a.y-c.y)+c.x*(b.y-a.y)<0;
}
bool cll(point a, point b, point c){
    return a.x*(c.y-b.y)+b.x*(a.y-c.y)+c.x*(b.y-a.y)==0;
}

vector<point> convex_hull(vector<point> points){
    if(points.size() <= 2) return points;
    sort(points.begin(),points.end());

    vector<point> up , down;

    point first = points[0] , last = points.back();
    up.push_back(first); down.push_back(first);

    for(int i=1;i<points.size();i++){
        if(i== points.size()-1 || (first, points[i],last)){
            //up set
            while(up.size()>=2 && !cw(up[up.size()-2],up[up.size()-1],points[i])){
                up.pop_back();
            }
            up.push_back(points[i]);
        }
        if(i== points.size()-1 || ccw(first, points[i],last)){
            //down set
            while(down.size()>=2 && !ccw(down[down.size()-2],down[down.size()-1],points[i])){
                down.pop_back();
            }
            down.push_back(points[i]);
        }
    }

    points.clear();

    for(int i=0;i<up.size();i++){
        points.push_back(up[i]);
    }
    for(int i=0;i<down.size();i++){
        points.push_back(down[i]);
    }
    sort(points.begin(),points.end());
    points.resize(unique(points.begin(),points.end())-points.begin()); 
    return points;
}

int main(){

    int n;
    cin>>n;
    vector<Point> points(n);

    for(int i=0;i<n;i++){
        cin>>points[i].x>>points[i].y;
    }
    vector<point> convex_hull_ans = convex_hull(points);

    for(int i=0;i<convex_hull_ans.size();i++){
        cout<<convex_hull_ans.x[i]<<" "<<convex_hull_ans.y[i]<<endl;
    }


    return 0;
}