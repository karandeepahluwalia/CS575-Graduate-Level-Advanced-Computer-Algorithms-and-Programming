//Karandeep Ahlwualia
#include <math.h>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int converttobits(int num){
  int count = 0;
  while(n){
    count++;
    n>>=1;
  }
  cout<<"Log function "<<count<<endl;
  return count;
}

void direct(char *argv[], ofstream& output, int cache_size){
  int line = 32;
  bool num_hit = 0;
  int counter;
  int offset = 5;
  int index = converttobits(cache_size*1024/32);
  int tag = converttobits(cache_size*1024) - offset - index;
  set_num = cache_size*1024/32;
  vector<int> cache(cache_size*1024/32);
  vector<bool> cache(cache_size*1024/32,false);
  ifstream infile(argv[1]);
  unsigned long long addr;
  string behavior, line;
  // The following loop will read a line at a time
  while(getline(infile, line)) {
    counter++;
    // Now we have to parse the line into it's two pieces
    stringstream s(line);
    s >> behavior >> std::hex >> addr;
    unsigned long long new_addr = addr >> offset;
    tag_addr = new_addr >>index;
    if(cache[new_addr%set_num]==tag_addr&&valid[new_addr]){
      num_hit++;
    }else{
      cache[new_addr%set_num]=tag_addr;
      valid[new_addr] = true;
    }
    output<<num_hit<<","<<counter<<";"<<endl;
    output<<counter - correct_amt<<","<<counter<<";"<<endl;
}

int main(int argc, char *argv[]){
  ofstream ouput;
  output.open(argv[2]);
  direct(argv,1,4,16,32)
  output.close();
}
