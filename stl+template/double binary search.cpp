ll be=1,en=1e9;
   ll re=en;
   int magic=100;
   while(magic--)
   {
      ll mid=(be+en)/2.00;
      if(func(mid))
      {
        re=mid;
        en=mid;
      }
      else be=mid;
 
   }
