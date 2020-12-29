stack<pair<int,int>>st;
    ll re=0;
    ll tem=0;

    for(int i=1;i<m;i++)
    {
    	if((!st.empty()) && ar[i] >= st.top().first)
        {
             tem+= cr[i];
             st.push({ar[i], 1});  
        }
        else
        {
            int cnt = 1;
            while((!st.empty()) && st.top().first > ar[i])
               cnt+=st.top().second, tem -= (ll)st.top().second * (ll)st.top().first,st.pop();
           
            st.push({ar[i], cnt});
            tem += (ll)cnt * ar[i];
        }
        re+=tem;
    }
   
    cout<<re<<"\n";
