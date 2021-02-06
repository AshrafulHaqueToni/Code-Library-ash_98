
1.    nC0+nC1+nC2+nC3+.....+nCn=2^n


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

       if we do partition 2*n numbers in two groups (1,2....n) and (n+1,n+2,...,n+n)


       and we can choose n numbers from two groups


       * group-1   ----  group-2


          0                n     ==  (nC0)*(nCn) == (nC0)*(nC0)== (nC0)^2  [nCr=nC(n-r)]


          1                n-1   ==  (nC1)*(nC(n-1)) == (nC1)*(nC1)== (nC1)^2  [nCr=nC(n-r)]


          .......


          n                0    ==  (nC0)*(nCn) == (nCn)*(nCn)== (nCn)^2  [nCr=nC(n-r)]


          so,  (nC0)^2+(nC1)^2+(nC2)^2+....+(nCn)^2=(2*n)Cn.


6. # of factor of two in n!


  n/2+n/4+n/8+ n/16+.....  (takes floor value)


7. nCr%2=?


   you can do it using *6 ideas( using factor 2).


    Lucas Theorem:


     at first convert n and c in binary representation.


     then multiply all bit (n's ith bit C r's ith bit).


     like n=8,c=2


     8=1000


     2=0010


     so result is= 1C0*0C0*0C1*0C0,  [is there any 0C1 then it will be divided by 2]


     More specifically if r is a submask of n then it will not be divisible by 2.

    nCr% any prime under 10^6=?

     just convert the mod number representation system.

8. # of ways to permutation this sting ?


         AAABBBCCCDDEFF . length=14


         14C3*11C3*8C3*5C2*3C1*2C2 ways


         some modification it will be =14!/(3!*3!*3!*2!*1!*2!)


9. how many ways you can go to (0,0) to (n,m) coordinate(you can only up and right).


  main observations i need to move x axis n times and y axis m times.


  so just found the permutation of m times U and n times R.


  like n=2,m=3,


  son RRUUU = 5!/(2!*3!)


  if there are more than two dimensions you will do just total moves time! / (x axis moves times!* y axis moves time! *.....)


10.


  stars and bars theorem:


  you have n balls k bucket # of ways insert the ball into bucket such that every bucket has more than 0 balls


  n=5 ,k=3


   k1+k2+k3=n ; ki>=1


  .| .| . . .


  .| . . |. .


  so here . means start


  ans | mean bars .  total ways is (n-1)C(k-1).


  you have n balls k bucket # of ways insert the ball into bucket such that every bucket has any numbers of ball


  n=5 ,k=3


  k11+k22+k33=n ; ki>=0


  k11=k1-1,k22=k2-1,k33=k3-1


  k1-1+k2-1+k3-1=n


  ->k1+k2+k3=n+3=n+k


   so the result is (n+k-1)C(k-1)

   if every bucket has minimum ball required condition then


   just change this (k1-x)+(k2-xx)=n equation.


   -------------------------------------------------------



   k1+k2+k3+k4+k5=n; 0<=ki<x


   for 0<=ki, total result is RESULT1= (n+k-1)C(k-1)  but some part is overlapping when ki<x .

   Now ki<x, this part we will do using exclusion and inclusion ,


   at first calculation # of way when just one ki>=x


     and the way is val1= kC1*(n-x+k-1)C(k-1)


   for second calculation,


     val2= kC2*(n-(2*x)+k-1)C(k-1)


   after valk calculation Final value will be,


   RESULT2=((-k)^1)*val1+((-k)^2)*val2+((-k)^1)*val3+.....((-k)^k)*valk  ;  /// But some time we have not calculated overall val1 to valk .

    Because (n-(x*kth)+k-1) will be <0


   So, Final Result is = RESULT1-RESULT2
   

11. Catalan Numbers:


   (i) you are given n opening bracker and n closing bracket # of ways  permutation this bracket sequence such that it is a valid bracker sequence.


       we can do it by selecting the position.


       but it takes O(n*n) time.


        the form is Cn=summation of Ck*Cn-k-1 where k=0 to n-1. base case C1=1,C0=1. [it takes 0(n) times]


         In catalan number Cn=(1/(n+1))*((2*n)Cn). [it takes 0(1) times]


         In other form Cn=((2*n)C(n))-((2*n)C(n+1))


        If you do google you can find more applications of catalan numbers.
