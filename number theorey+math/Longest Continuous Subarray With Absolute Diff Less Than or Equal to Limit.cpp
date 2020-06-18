 int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>s;
        int n=nums.size();
        int last=0;
        int re=0;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
            while(*s.rbegin()-*s.begin()>limit)
            {
                s.erase(s.find(nums[last++]));
            }
            re=max(re,i-last+1);
        }
        return re;
    }
