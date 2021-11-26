// Copyright 2021 Ian McDevitt
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::cout;
using std::string;
using namespace std;

void readData(vector<string> &data, string filename);
void printData(const vector<string> &data);
vector<int> findMinHamming(const vector<string> & data, string test);
void printMinDistance(const vector<string> &data, string word,
                      const vector<int> min);

int main(int argc, char **argv) {
  string filename;
  vector<string> data;
  if (argc != 2) {
    cout << "Usage: ./sub1 data.txt\n";
    exit(0);
  }
  filename = argv[1];
  readData(data, filename);
  printData(data);
  for (auto line : data) {
    vector<int> ret;
    ret = findMinHamming(data, line);
    printMinDistance(data, line, ret);
  }
  return 0;
}

void readData(vector<string> &data, string filename) {
cout << "reading data" << std::endl;
string line = "";
//int count = 0;
std::fstream myfile(filename); 
if (myfile.is_open()) {
while ( getline (myfile,line) ) {
 // cout << line << '\n';
  data.push_back(line);
  //cout++;
}
  myfile.close();
 
} else {
  cout << "Unable to open file" << endl;
}
}


void printData(const vector<string> &data) {
  cout << "printing data" << std::endl;
  for (int i = 0; i < data.size();  i++ ) {
    cout << data[i] << endl;
  } cout << std::endl;
  return;
}

vector<int> findMinHamming(const vector<string> & data, string test) {
  vector<int> ret; 
  vector<int> counter;
  int ind = 0;
  int min = 100;
  for (int i = 0; i < data.size(); i++) {
    int dist = 0;
    for (int j = 0; j < test.size();j++) {
      if (data[i][j] != test[j]) {
        dist++;
      }
    }
    if (dist < min && dist != 0) {
      min = dist;
      ind = i;
    }
    
  }
  ret.push_back(ind);
  ret.push_back(min);
  
  return ret;
  }
  
  


void printMinDistance(const vector<string> &data, string word,
                      const vector<int> min) {
  
   /**                    
  for (int i = 0; i < data.size(); i++){
    cout << data[i] << std::endl;
    cout << min[i] << std::endl;
  }
  **/
  cout << "The minimum hamming distance for " <<  word << " is " << min[1] << " (matching word: " << data[min[0]] << ")" << std::endl;

  return;
}
/**
vector<int> ret; 
  vector<int> counter;
  vector<int> index;
  int count = 0;
  int decider = 0;
  for (int i=0; i < data.size(); i++) {
    //if (test[i] != i[i]) {
      //ret[0] = i;
      for(int j = 0; j < data[i].size(); j++) {
      
      if(data[i][j]!= test[j]) {
        count++;
      }
      
      }
      index.push_back(i);
      counter.push_back(count);
      count = 0;
      //return ret;
    }
    
    for (int i = 0; i < counter.size(); i++) {
      if ( i !=  counter.size()){
        if( counter[i] > counter[i+1]) {
          if( decider < counter[i])
            decider = counter[i];
        } else {
          if (decider < counter[i+1])
            decider = counter[i+1];
        }
      }
      

    }

    for ( int i = 0; i < counter.size(); i++) {
        if (decider == counter[i]){
          cout << decider << std::endl;
          ret.push_back(i);
          ret.push_back(decider);
          break;
        }
      }
    return ret;
  }
  
  
**/