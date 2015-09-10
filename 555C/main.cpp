#include<iostream>
#include<map>
#include<iterator>

using namespace std;

typedef struct {
    long w;
    long h;
} Area;

typedef struct {
    long xmin;
    long xmax;
} Inter;

struct CmpInter
{
    bool operator()( Inter const& lhs, Inter const& rhs ) const
    {
        if(lhs.xmax < rhs.xmin) return true;
        return false;
    }
};

typedef map<Inter, Area, CmpInter> Map;
typedef Map::iterator Itr;

int main() {
    Map map;
    long n, q = 0;
    cin >> n;
    cin >> q;

    map[{1, n}] = {1, 1};

    long x, y = 0;
    char c;

    for(int i = 0; i < q; i++) {
        cin >> x;
        cin >> y;
        cin >> c;

        Itr itr = map.find({x,x});
        
        if(itr == map.end()) {
            cout << 0 << endl;
            continue;
        }

        Inter in = itr->first;
        Area a = itr->second;

        map.erase(in);

        if(x < in.xmax) {
            if(c == 'L') {
                map[{x+1, in.xmax}] = {a.w + x+1 - in.xmin, a.h};
            } else {
                map[{x+1, in.xmax}] = {1, a.h};
            }   
        }
        if(x > in.xmin) {
            if(c == 'L') {
                map[{in.xmin, x-1}] = {a.w, 1};
            } else {
                map[{in.xmin, x-1}] = {a.w, a.h+in.xmax-(x-1)};
            } 
        }
        if(c == 'L') {
            cout << x - in.xmin + a.w << endl;
        } else {
            cout << in.xmax - x + a.h << endl;
        }
    }
    return 0;
}
