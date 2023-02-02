struct BASIS {
    int basis[d]; // d = 31,63
    int sz;
 
    void init() {
        for(int i = 0; i < d; i++) basis[i] = 0;
        sz = 0;
    }
 
    void insertVector(int mask) {
        for (int i = d-1; i >= 0; i--) {
            if (((mask>>i)&1) == 0) continue;
 
            if (!basis[i]) {
                basis[i] = mask;
                ++sz;
                return;
            }
            mask ^= basis[i];
        }
    }
 
    void mergeBasis(const BASIS &from) {
        for(int i = d-1; i >= 0; i--) {
            if(!from.basis[i])
                continue;
 
            insertVector(from.basis[i]);
        }
    }
 
    int findMax()  {
        int ret = 0;
        for(int i = d-1; i >= 0; i--) {
            if(!basis[i] || (ret>>i & 1))
                continue;
 
            ret ^= basis[i];
        }
        return ret;
    }
};
