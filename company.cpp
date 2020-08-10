#include <bits/stdc++.h>
#include <stdio.h>
#include "company.h"

using namespace std;

COMPANY::COMPANY() : iTen("ta"), iMa("abc"), iGiasan(1) ,iGiatran(1),iGiadongcua(1), iKhoiluong("5,6") {
};

COMPANY::COMPANY(string iTen, string iMa, double iGiasan, double iGiatran, double iGiadongcua, string iKhoiluong) {
  this -> iTen = iTen;
  this -> iMa = iMa;
  this -> iGiasan = iGiasan;
  this -> iGiatran = iGiatran;
  this -> iGiadongcua = iGiadongcua;
  this -> iKhoiluong = iKhoiluong;
};

void COMPANY::setCOMPANY(string iTen, string iMa, double iGiasan, double iGiatran, double iGiadongcua, string iKhoiluong) {
  this -> iTen = iTen;
  this -> iMa = iMa;
  this -> iGiasan = iGiasan;
  this -> iGiatran = iGiatran;
  this -> iGiadongcua = iGiadongcua;
  this -> iKhoiluong = iKhoiluong;
};

void COMPANY::setTen(string Ten) {
  this -> iTen = Ten;
};

void COMPANY::setMa(string Ma) {
  this -> iMa = Ma;
};

void COMPANY::setGiasan(double Giasan) {
  this -> iGiasan = Giasan;
};

void COMPANY::setGiatran(double Giatran) {
  this -> iGiatran = Giatran;
};

void COMPANY::setGiadongcua(double Giadongcua) {
  this -> iGiadongcua = Giadongcua;
};

void COMPANY::setKhoiluong(string Khoiluong) {
  this -> iKhoiluong = Khoiluong;
};

string COMPANY::getTen() {
  return iTen;
};

string COMPANY::getMa() {
  return iMa;
};

double COMPANY::getGiasan() {
  return iGiasan;
};

double COMPANY::getGiatran() {
  return iGiatran;
};

double COMPANY::getGiadongcua() {
  return iGiadongcua;
};

string COMPANY::getKhoiluong() {
  return iKhoiluong;
};
