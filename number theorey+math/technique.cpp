1.  nC0+nC1+nC2+nC3+.....+nCn= 2^n
2.  0*nC0+1*nC1+2*nC2+3*nC3+.....+n*nCn=?
    using contribution technique:
    found 1s contribution: 2^(n-1)== how many set 1 occurs
    found 2s contribution: 2^(n-1)== how many set 2 occurs
    ......
    ......
    found ns contribution: 2^(n-1)== how many set n occurs
    
    so overall result 0*nC0+1*nC1+2*nC2+3*nC3+.....+n*nCn=n*2^(n-1).
    
3. 0Cr+1Cr+2Cr+3Cr+4Cr+5Cr+6Cr+....+nCr= (n+1)C(r+1)
   Hockey Stick identity :
   if n=6 and c=3
   the answer is 7C4.
   if we choose 1 max and it's 7 then we choose let 3 in =6C3.
   if we choose 1 max and it's 6 then we choose let 3 in =5C3.
   if we choose 1 max and it's 5 then we choose let 3 in =4C3.
   if we choose 1 max and it's 4 then we choose let 3 in =3C3.
   others =0;
   so, 0+0+0+3C3+4C3+5C3+6C3=7C3
4.
   nCr=nC(n-r)
   because in every part we choose with nCr and without nC(n-r).
5.
   (nC0)^2+(nC1)^2+(nC2)^2+....+(nCn)^2=(2*n)Cn
   proof:
        if we part 2*n numbers in two groups (1,2....n) and (n+1,n+2,...,n+n)
        and we can choose n numbers from two groups
        * group-1   ----  group-2
           0                n     ==  (nC0)*(nCn) == (nC0)*(nC0)== (nC0)^2  [nCr=nC(n-r)]
           1                n-1   ==  (nC1)*(nC(n-1)) == (nC1)*(nC1)== (nC1)^2  [nCr=nC(n-r)]
           .......
           n                0    ==  (nC0)*(nCn) == (nCn)*(nCn)== (nCn)^2  [nCr=nC(n-r)]
           
           so,  (nC0)^2+(nC1)^2+(nC2)^2+....+(nCn)^2=(2*n)Cn
   
   
    
    
