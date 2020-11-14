int LIS(vector<int> input, vector<int>& solution)
{
    vector<int> magic;
    vector< vector<int> > history; // OPTIONAL
    for (int x: input) {
        vector<int>::iterator it = lower_bound(magic.begin(), magic.end(), x);
        if (it == magic.end()) {
            magic.push_back(x);
            history.push_back(vector<int>(1, x)); // OPTIONAL
        }
        else {
            *it = x;
            history[it-magic.begin()].push_back(x); // OPTIONAL
        }
    }
    
    // OPTIONAL
    {
        int result = magic.size();
        solution.resize(result);
        solution.back() = magic.back();
        for (int i=result-2; i>=0; i--) {
            auto it = lower_bound(history[i].rbegin(), history[i].rend(), solution[i+1]);
            it --;
            solution[i] = *it;
        }
    }
    
    return magic.size();
}
