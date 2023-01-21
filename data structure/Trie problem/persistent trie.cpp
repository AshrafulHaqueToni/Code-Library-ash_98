#include <bits/stdc++.h>

using namespace std;

 // persistent Trie
 
// find maximum value (x^a[j]) in the range (l,r) where l<=j<=r
const int N = 2e5 + 05;
const int K = 30;
 
struct node_t {
  int time;
  node_t* to[2];
  node_t() : time(0) {
    to[0] = to[1] = 0;
  }
  bool go(int l) const {
    if (!this) return false;
    return time >= l;
  }
};
typedef node_t* pnode;
 
pnode clone(pnode p) {
  pnode cur = new node_t();
  if (p) {
    cur->time = p -> time;
    cur->to[0] = p -> to[0];
    cur->to[1] = p -> to[1];
  }
  return cur;
}
 
pnode last;
pnode version[N];
 
void insert(int a, int time) {
  pnode v = clone(last);
  version[time] = last = v;
  for (int i = K - 1; i >= 0; --i) {
    int bit = (a >> i) & 1;
    pnode &child = v->to[bit];
    child = clone(child);
    v = child;
    v->time = time;
  }
}
 
int query(pnode v, int x, int l) {
  int ans = 0;
  for (int i = K - 1; i >= 0; --i) {
    int bit = (x >> i) & 1;
    if (v->to[bit]->go(l)) { // checking if this bit was inserted before the range
      ans |= 1 << i;
      v = v->to[bit];
    } else {
      v = v->to[bit ^ 1];
    }
  }
  return ans;
}

void solve() {
  int n, q;
  scanf("%d %d", &n, &q);
  last = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    insert(a, i);
  }
  while (q--) {
    int x, l, r;
    scanf("%d %d %d", &x, &l, &r);
    --l, --r;
    printf("%d\n", query(version[r], ~x, l));
    // Trie version[r] contains the trie for [0...r] elements
  }
}
// credit: mochow13
