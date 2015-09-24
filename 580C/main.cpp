#include <iostream>
#include <vector>
#include <list>
#include <functional>

using namespace std;

#define SIZE (100000)

int main() {
  long n, m;
  cin >> n >> m;

  bool cat[SIZE] = {false};
  for (int i = 0; i < n; i++) {
    cin >> cat[i];
  }

  std::vector<std::list<int>> adj(SIZE);
  for (int i = 1; i <= n-1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }

  struct dfsState {
    bool visited;
    int c_cat;
  } dfs[SIZE] = {{false, 0}};

  std::function<int(int, int)> visit =
      [&dfs, &cat, &visit, &adj, &m](int parent, int node) {
        //cout << "visiting " << node+1 << " from "<< parent+1 << endl;
          
        dfs[node].c_cat = (parent != -1 ? dfs[parent].c_cat : 0);
        dfs[node].c_cat = (cat[node] ? dfs[node].c_cat+1 : 0);
        dfs[node].visited = true;

        //cout << "c_cat" << dfs[node].c_cat << endl;
        if(dfs[node].c_cat > m) {
            return 0;
        }

        if(adj[node].size() == 1 && node !=0) {
            return 1;
        }

        int rest = 0;
        for (auto itr : adj[node]) {
          if (!dfs[itr].visited) {
            rest += visit(node, itr);
          }
        }
        //cout << node+1 << "  "<< rest << endl;
        return rest;
      };

  cout << visit(-1, 0) << endl;

  return 0;
}
