#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int n, m, q;

typedef vector<map<int, int> *> FAdj;
map<int, int> *fadj[200001];

// typedef map<int,map<int, int>> Adj;
// Adj adj;
// int adj[200001][200001];
vector<vector<int>> adj;

// typedef map<int, int> Pair;
// Pair sd;

// Adj visited;
typedef vector<int> Path;
Path path;
bool visitedNode[200001];

// int adj[200000][200000];
// int test2[200000][200000];

// Pair mergeMap;
/*
int getMerged(int in) {
  int target = mergeMap[in];
  if (target == in) {
    return target;
  }
  target = getMerged(target);
  mergeMap[in] = target;
  return target;
}*/

void onBack(int u, int v) {
  if (u == v) {
    return;
  }
  adj[v][u] = false;
}

bool dfs2(int s, int d, int minStep) {
  /*
  if(!adj.count(s)) {
      cout << s << "," << d<< endl;
  }
  assert(adj.count(s));
  assert(adj.count(d));
  */
  path.clear();
  path.reserve(200001);

  memset(visitedNode, 0, sizeof(bool) * 200001);

  int cur;
  auto visit = [&cur](int x) {
    cur = x;
    path.push_back(cur);
    visitedNode[cur] = true;
    // cout << cur << endl;
  };
  visit(s);

  int fakeStep = 0;
  while (cur != d || (int)path.size() < minStep) {
    // auto& nb = adj[cur];
    // auto& nb = *fadj[cur];
    bool visitNext = false;
    for (int i = 1; i <= n; i++) {
      if (!adj[cur][i])
        continue;

      if (visitedNode[i]) {
        continue;
      }
      // visitNext
      visit(i);
      visitNext = true;
      fakeStep++;
      break;
    }
    if (visitNext) {
      continue;
    }
    // go back
    if (cur == s) {
      cout << "f" << fakeStep << "f " << endl;
      return false;
    }

    path.pop_back();
    cur = path.back();
    // cout << 'v' << cur << endl;
  }

  cout << "f" << fakeStep << endl;
  return true;
}
/*
bool dfs(int cur, int d, int& step, void (*onBack)(int, int) = [](int, int){}) {
    step ++;
    if(cur == d && step > 1) {
        path.push_back(cur);
        return true;
    }
    auto& dest = adj[cur];
    for(auto itr = dest.begin(); itr != dest.end(); itr++) {
       if(visited[cur][itr->first] || visited[itr->first][cur]) {
            continue;
       }
       visited[cur][itr->first] = true;
       if(dfs(itr->first, d, step)) {
           path.push_back(cur);
           onBack(cur, itr->first);
           return true;
       }
    }
    step--;
    return false;
}
*/
/*
void adjErase(int x) {
    auto& xadj = adj[x];
    for(auto itr = xadj.begin(); itr!= xadj.end(); itr++) {
        auto& nAdj = adj[itr->first];
        nAdj.erase(nAdj.find(x));
    }
    adj.erase(adj.find(x));
}
*/
/*
// update adj and mergeMap, merge to destination;
void mergeXToY(int x, int y) {
        assert(adj.count(x));
        assert(adj.count(y));
        auto& yadj = adj[y];
        auto& xadj = adj[x];

        // y link to all nb of x, avoid self linking
        for(auto itr = xadj.begin(); itr != xadj.end(); itr++) {
            if(itr->first != y) {
                yadj[itr->first] = true;
                adj[itr->first][y] = true;
            }
        }
        mergeMap[x] = y; // set child merge map
        adjErase(x);
}


void mergePath() {
    assert(path.size() >= 3);
    assert(path.front() == path.back());
    int parent = path.back();
    path.pop_back();
    for(auto chItr = path.begin() + 1; chItr != path.end(); chItr++) {
        assert(adj.count(*chItr));
        mergeXToY(*chItr, parent);
    }

}

void merge() {
    Pair mergePair;
    for(auto itr = adj.begin(); itr!=adj.end(); itr++) {
        for(auto vitr = itr->second.begin(); vitr!= itr->second.end(); vitr++) {
            if(vitr->second >= 2) {
                mergePair[itr->first] = vitr->first;
            }
        }
    }

    for(auto itr = mergePair.begin(); itr!= mergePair.end(); itr++) {
       int x = getMerged(itr->first);
       int y = getMerged(itr->second);
       if(x!=y) {
            mergeXToY(x, y);
       }
    }

    for(int i=1; i<=n; i++) {
        if(getMerged(i) != i) {
            continue;
        }
        cout << i << endl;
        //visited.clear();
        //path.clear();
        if(dfs2(i, i, 3)) {
            cout << "mergelo" << endl;
            mergePath();
            i--;
        }
    }
}
*/
/*
void dfsSD() {

    for(int i = 1; i<=n; i++) {
        if(adj.count(i)) {
            fadj[i] = &adj[i];
        }
    }

    for(auto itr=sd.begin(); itr!=sd.end(); itr++) {
        //visited.clear();
        //d
        //path.clear();
        int s = getMerged(itr->first);
        int d = getMerged(itr->second);
        cout << s << "sd "<< d << endl;
        if(!dfs2(s, d, 1)) {
            cout << "NO" << endl;
            return;
        }else{
            for(int i = 1; i < (int)path.size(); i++) {
                onBack(path[i-1], path[i]);
            }
        }
    }
    cout << "Yes" << endl;
}*/

bool validPath(int s, int d) {
  if (s == d) {
    return true;
  }
}

bool validPath(int s, int m, int d) {
  return validPath(s, m) && validPath(m, d);
}
void LCA(int n) {
  makeSet(n);
  for (auto &it : adj[n]) {
    LCA(n);
    unionSet(it, n); // constant time
  }
  color[n] = true;
  for (auto &it : sd[n]) {
    if (color[it.d]) {
      int lca = find(it.d).parent; // constant time if flatten
      if (!validPath(it.isSource ? it.d : n, lca, it.isSource ? n : it.d)) {
        cout << "NO" << endl;
        exit(0);
      }
    }
  }
}
/*
void dfsSD() {
  for (auto itr = sd.begin(); itr != sd.end(); itr++) {
    dfs2(getMerged(1), getMerged(n), 1);
    cout << itr->second << endl;
  }
}
*/
int main() {
  // cin >> n >> m >> q;
  n = 200000;
  m = 199999;
  q = 4900;

  adj.resize(n + 1);
  /*
    for (int i = 1; i <= n; i++) {
      mergeMap[i] = i;
      // adj[i];
      cout << i << endl;
      for (int j = 1; j <= n; j++) {
        adj[i][j] = 0;
      }
    }

    for (int i = 0; i < m; i++) {
      int u, v;
      // cin >> u >> v;
      u = i + 1;
      v = i + 2;
      // test[u][v]++;
      // test2[u][v]++;
      adj[u][v]++;
      adj[v][u]++;
    }

    sd.resize(n + 1);

    for (int i = 0; i < q; i++) {
      int s, d;
      // cin >> s >> d;
      s = n - i;
      d = i + 1;
      sd[s].push_back({d, false});
      sd[d].push_back({s, true});
    }
  */
  // return 0;

  cout << "start" << endl;
  // merge();
  cout << "dfsSD" << endl;
  // dfsSD();
  cout << "bye" << endl;

  return 0;
}
