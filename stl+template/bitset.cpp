https://codeforces.com/blog/entry/73558

bitset<mx>bt;
bt.set() /// all bit 1
bt.reset() ///all bit 0
bt.count() // total number of 1 bit
bt._Find_first() // palce of the first 1 bit  
bt._Find_next() // next one bit
for(int i=bt._Find_first();i<mx;i=bt._Find_next(i)) // for traversing all 1 node
