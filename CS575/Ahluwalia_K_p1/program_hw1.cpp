#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <iterator>
#include <map>
#include <fstream>
#include <iostream>
#include<chrono>
using namespace std;

struct pairs{
  string a;
  int b;
};
void problemSolver(ifstream& prices,int loopcnt,int limit, int mCnt, map<string,int> marketlist,FILE* f){
  const clock_t begin_time = clock();
  int count =0;
  struct pairs pricelist[loopcnt];
  string fline;
  int cardval;
  while(count<loopcnt){
    getline(prices,fline);
    stringstream converter(fline);
    converter >> fline;
    converter >> cardval;
    //printf("%d \n", cardval);
    struct pairs card;
    card.a = fline;
    card.b = cardval;
    pricelist[count++] = card;
  }
  int maxProfit = 0;
  string currentSet[loopcnt];
  string maxSet[loopcnt];
  int maxcount = 0;
  int pricesum = 0;
  for(int i = 0; i < loopcnt;i++){
    pricesum += pricelist[i].b;
    maxProfit += marketlist[pricelist[i].a]-pricelist[i].b;
    }
  if (pricesum<=limit){
    maxcount = loopcnt;
    for (int h = 0; h < loopcnt;h++){
      maxSet[h] = pricelist[h].a;
    }
  }else{
    maxProfit = 0;
    long long power = 1<<loopcnt;
    for(long long i=0;i<power;i++){
      int counter = 0;
      int sum = 0;
      int profit = 0;
      string currentSet[loopcnt];
      for(int j = 0;j<loopcnt;j++){
        if(i & (1<<j)){
          string name = pricelist[j].a;
          int value = pricelist[j].b;
          sum += value;
          profit += marketlist[name] - value;
          currentSet[counter++] = pricelist[j].a;
        }
      }
      if(sum<=limit){
        if (maxProfit<profit){
            maxProfit = profit;
            for(int k = 0; k<loopcnt;k++){
              maxSet[k] = currentSet[k];
            }
            maxcount = counter;
        }
      }
    }
  }

    float time = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    fprintf(f,"Number of cards in price list:%d   Profit:%d   Purchased cards:%d    Time in seconds:%g\n",loopcnt,maxProfit,maxcount,time);
    for (int r=0;r<maxcount;r++){
      string s = maxSet[r];
      //printf("%s ",s.c_str());
      fprintf(f, "%s \n",s.c_str());
    }
}
void problemManager(ifstream& prices, map<string,int> marketlist, int mCnt){
  string line;
  FILE *f = fopen("output.txt", "w");
  while(getline(prices, line)){
    //printf("%s \n", line.c_str());
    stringstream splitline(line);
    int loopcnt = -1;
    int limit =-1;
    splitline >> loopcnt;
    splitline >> limit;
    problemSolver(prices,loopcnt,limit,mCnt, marketlist,f);
  }
  fclose(f);
}
void read_in_data(char *argv[]){
  ifstream market(argv[2]);
  ifstream pricelist(argv[4]);
  string firstline;
  int loop = 0;
  string line;
  map<string,int> marketlist;
  int mListCnt = 0;
  if(market.is_open()){
    getline(market, firstline);
    stringstream converted(firstline);
    converted >> loop;
    int cnt = 0;
    if(loop==0){
      //printf("Loop DNE\n");
    }
    while(cnt<loop){
      getline(market,line);
      string firstword;
      int cardvalue =-1;
      stringstream splitline(line);
      splitline >> firstword;
      splitline >> cardvalue;
      marketlist[firstword] = cardvalue;
      cnt++;
    }
  }
  problemManager(pricelist,marketlist,mListCnt);
}
int main(int argc, char *argv[]){
  read_in_data(argv);
  return 0;
}
