///       Set Merge   ///
set<int> a {1, 3, 7, 10, 13, 20};
	set<int> b {2, 3, 5, 7, 11, 13, 15, 19};
	
	vector<int> v;
	merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(v));
  set<int> m(v.begin(), v.end());
  
or :
set<int> m;
merge(a.begin(), a.end(), b.begin(), b.end(), inserter(m, m.end()));

///      Vector Merge    ///
vector<int>a,b,c;
merge(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c));
