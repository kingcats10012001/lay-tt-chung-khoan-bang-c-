#ifndef COMPANY_H
#define COMPANY_H

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

  class COMPANY {
    private:
      string iTen;
      string iMa;
      double iGiasan;
      double iGiatran;
      double iGiadongcua;
      string iKhoiluong;

    public:
      COMPANY();
      COMPANY(string , string ,double ,double ,double , string);

      void setCOMPANY(string , string ,double ,double ,double , string);

      void setTen(string ) ;
      void setMa(string ) ;
      void setGiasan(double ) ;
      void setGiatran(double ) ;
      void setGiadongcua(double ) ;
      void setKhoiluong(string ) ;

      string getTen();
      string getMa();
      double getGiasan();
      double getGiatran();
      double getGiadongcua();
      string getKhoiluong();
      
};

#endif