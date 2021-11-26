// Copyright 2021 Ian McDevitt
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using std::vector;
using std::cout;
using std::string;


void readPuzzle(vector<vector<char>> &puzzle, string filename);
void readWords(vector<string> &words, string filename);
void printPuzzle(const vector<vector<char>> &puzzle);
void printWords(const vector<string> &words);
void printLocation(string word, const vector<int> &start,
                   const vector<int> &end, bool found);
bool findWord(const vector<vector<char>> & puzzle, string word,
              vector<int> &start, vector<int> &end);
bool check_hor_right(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j);
bool check_vert_up(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j);
bool check_hor_left(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j);
bool check_vert_down(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j);
bool check_vert_up_horz_left(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j);
bool check_vert_up_horz_right(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j);
bool check_vert_down_horz_left(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j);
bool check_vert_down_horz_right(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j);



int main(int argc, char **argv) {
  string puzzleFileName;
  string wordsFileName;
  vector<vector<char>> puzzle;
  vector<string> words;
  if (argc != 3) {
    cout << "Usage: ./sub2 puzzle.txt words.txt\n";
    exit(0);
  }
  puzzleFileName = argv[1];
  wordsFileName = argv[2];
  readPuzzle(puzzle, puzzleFileName);
  readWords(words, wordsFileName);
  printPuzzle(puzzle);
  printWords(words);

  for (auto word : words) {
    vector<int> start;
    vector<int> end;
    bool found;
    found = findWord(puzzle, word, start, end);
    printLocation(word, start, end, found);
    end.clear();
    start.clear();
  }
  return 0;
}

void readPuzzle(vector<vector<char>> &puzzle, string filename) {
  cout << "Reading Puzzle" << std::endl;
std::fstream in(filename);
string line = ""; 

while(getline(in, line)) {
 
  vector<char> row;
  cout << line << std::endl;
  std::stringstream ss(line);
  string token = "";
  while(getline(ss, token, ' ')) {
    row.push_back(token[0]);
  }
  puzzle.push_back(row);
}
  /**for (int i = 0; i < puzzle.size(); i++ ) {
      for (int j =0; j < puzzle[i].size(); j++) {
        cout << puzzle[i][j] << std::endl;
      }
     // cout << std::endl;
    } **/
    return;
   
}

void readWords(vector<string> &words, string filename) {
string ch = "";
int count = 0;
std::fstream in(filename);
if (in.is_open()) {
while (getline (in,ch) ) { 
      words.push_back(ch); 
}
  in.close();
 
} else {
  std::cout << "Unable to open file" << std::endl;
}
    return;

}

void printPuzzle(const vector<vector<char>> &puzzle) {
  cout << "Print Puzzzle" << std::endl;
    for (int i = 0; i < puzzle.size(); i++ ) {
      for (int j =0; j < puzzle[i].size(); j++) {
        cout << puzzle[i][j] << " ";
      }
    cout << std::endl;
    }
    return;
}

void printWords(const vector<string> &words) {
  for ( int i = 0; i < words.size(); i++) {
    cout << words[i] << std::endl;
  }
    return;
}

void printLocation(string word, const vector<int> &start,
                   const vector<int> &end, bool found) {
                   

    if (found) {
      cout << "Word " << word << " Starting location (" << start[0] << "," << start[1] << ")" << std::endl;
      cout << "Word " << word << " End location (" << end[0] << "," << end[1] << ")" << std::endl;
    } else {
      cout << "Word " << word << " not found." << std::endl;
    }
    cout << std::endl;
    return;
}

bool findWord(const vector<vector<char>> & puzzle, string word,
              vector<int> &start, vector<int> &end) {
                cout << "looking for " << word << std::endl;
    int k = 0;
    int s = word.size();
    bool found = true;
    for (int i = 0; i < puzzle.size(); i++) {
      for (int j = 0; j < puzzle[i].size(); j++) {
        if (puzzle[i][j] == word[k]) {
     
          if (j == 6 && i != 0 && i != 2){
           
            found = check_hor_left(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
            
            found = check_vert_up(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
            found = check_vert_down(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
            found = check_vert_up_horz_left(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
            found = check_vert_down_horz_left(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }

          } else if (j == 0 && i != 0 && i != 2) {
           

            found = check_hor_right(puzzle, word, start, end, i, j);
            
            
            if (found == true ) {
              return true;
            }
            
            
            found = check_vert_up(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            } 
             
            found = check_vert_down(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
             
            found = check_vert_up_horz_right(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
             
            found = check_vert_down_horz_right(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
           


          } else if (i == 0 && j != 0 && j != 6) {
       
            found = check_hor_right(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
           
           found = check_hor_left(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
            found = check_vert_down(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
            found = check_vert_down_horz_left(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
            found = check_vert_down_horz_right(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
          } else if (i == 2 && j != 0 && j != 6) {

            found = check_hor_right(puzzle, word, start, end, i, j);
            
            if (found == true ) {
              return true;
            }
             
            found = check_hor_left(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
             
            found = check_vert_up(puzzle, word, start, end, i, j);
            if (found == true ) {
              
              return true;
            }
             
            found = check_vert_up_horz_left(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
             
            found = check_vert_up_horz_right(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
          } else if (j == 6 && i == 2) {
            found = check_hor_left(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
            found = check_vert_up(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
            found = check_vert_up_horz_left(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
          } else if (j == 6 && i == 0) {
            found = check_hor_left(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
            found = check_vert_down(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
            found = check_vert_down_horz_left(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
          } else if (j == 0 && i == 2) {
         
            found = check_hor_right(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
     
            found = check_vert_up(puzzle, word, start, end, i, j);
            if (found == true ) {
             return true;
            }
       
            found = check_vert_up_horz_right(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }

          } else if (j == 0 && i == 0) {
          
              
            found = check_hor_right(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
            found = check_vert_down(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }
            found = check_vert_down_horz_right(puzzle, word, start, end, i, j);
            if (found == true ) {
              return true;
            }

          } else {
              
          
          //----------------------------------------------------------- 
          found = check_hor_right(puzzle, word, start, end, i, j);
          if (found == true ) {
            return true;
          }
          found = check_hor_left(puzzle, word, start, end, i, j);
          if (found == true ) {
            return true;
          }
          found = check_vert_up(puzzle, word, start, end, i, j);
          if (found == true ) {
            return true;
          }
          found = check_vert_down(puzzle, word, start, end, i, j);
          if (found == true ) {
            return true;
          }
          found = check_vert_up_horz_left(puzzle, word, start, end, i, j);
          if (found == true ) {
            return true;
          }
          found = check_vert_up_horz_right(puzzle, word, start, end, i, j);
          if (found == true ) {
            return true;
          }
          found = check_vert_down_horz_left(puzzle, word, start, end, i, j);
          if (found == true ) {
            return true;
          }
          found = check_vert_down_horz_right(puzzle, word, start, end, i, j);
          if (found == true ) {
            return true;
          }
          //--------------------------------------------------------------
           
        }
          
      }
        
          

    } 
  }
  return false;
}
bool check_hor_right(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j) {
  int k = 0;
  int j_holder;
  if (j == 0) {
    j_holder = j;
  } else  {
    j_holder = j / 2;
  }
  start.push_back(i);
  start.push_back(j_holder);
   
  for (; k < word.size(); j+=2) {
    if (puzzle[i][j] ==  word[k]) {
      k++;
      continue;
    } else {
       start.clear();
      return false;
    }
   }  
    if (j != 0 ) {
      j_holder = j / 2;
    } else {
      j_holder = 0;
    }
    
    end.push_back(i);
    end.push_back(j_holder-1);
    return true;
  }
  

bool check_hor_left(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j) {
  int k = 0;
  int j_holder;
  if (j == 0) {
    j_holder = j;
  } else  {
    j_holder = j / 2;
  }
  start.push_back(i);
  start.push_back(j-1);
  for (; k < word.size(); j-=2) {
    if (puzzle[i][j] ==  word[k]) {
      k++;
      continue;
    } else {
      start.clear();
      return false;
    }
  }
  if (j_holder != 0 ) {
      j_holder = j / 2;
    } else {
      j_holder = j;
    } 
  end.push_back(i);
  end.push_back(j-word.size()-1);
  return true;
}
bool check_vert_up(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j) {
  int k = 0;
  int j_holder = j;
  if (j == 0) {
     j_holder = j;
  } else  {
   j_holder =  j / 2;
  }
  start.push_back(i);
  start.push_back(j_holder);
  for (; k < word.size(); i--) {
    if (puzzle[i][j] ==  word[k]) {
      k++;
      continue;
    } else {
      start.clear();
      return false;
    }
  }
  if (j_holder != 0 ) {
      j_holder = j / 2;
    } else {
      j_holder = j;
    }
  
    end.push_back(i+1);
    end.push_back(j_holder+1);
  return true;
} 
bool check_vert_down(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j) {
  int k = 0;
  int j_holder;
  if (j == 0) {
    j_holder = j;
  } else  {
    j_holder = j / 2;
  }
    start.push_back(i);
    start.push_back(j_holder);
  for (; k < word.size(); i++) {
    if (puzzle[i][j] ==  word[k]) {
      k++;
      continue;
    } else {
      start.clear();
      return false;
    } 
    if (j_holder != 0 ) {
      j_holder = j / 2;
    } else {
      j_holder = j;
    }
  }
    
    end.push_back(i-1);
    end.push_back(j_holder);
    return true;
  }
bool check_vert_up_horz_right(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j) {
  int k = 0;
  int j_holder;
 if (j == 0) {
    j_holder = j;
  } else  {
    j_holder = j / 2;
  }
  start.push_back(i);
    start.push_back(j_holder);
  for (; k < word.size(); i--) {
    if (puzzle[i][j] ==  word[k]) {
      k++;
      j+=2;
     continue;
    } else {
      start.clear();
      return false;
    }
  }
    if (j != 0 ) {
      j_holder = j / 2;
    } else {
      j_holder = j;
    }
    
    end.push_back(i+1);
    end.push_back(j_holder -1);
 // }
  return true;
} 
bool check_vert_up_horz_left(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j) {
  int k = 0;
  int j_holder;
  if (j == 0) {
    j_holder = j;
  } else  {
    j_holder = j / 2;
  }
    start.push_back(i);
    start.push_back(j_holder);
  for (; k < word.size(); i--) {
    if (puzzle[i][j] ==  word[k]) {
      j-=2;
      k++;
      continue;
    } else {
      start.clear();
      return false;
    }
  }
 if (j_holder != 0 ) {
      j_holder = j / 2;
    } else {
      j_holder = j;
    }
 
    end.push_back(i+1);
    end.push_back(j_holder+1);
  return true;
} 
bool check_vert_down_horz_right(const vector<vector<char>> & puzzle, string word, vector<int> &start, vector<int> &end, int i, int j) {
  int k = 0;
  int j_holder;
  if (j == 0) {
    j_holder = j;
  } else  {
    j_holder = j / 2;
  }
  start.push_back(i);
    start.push_back(j_holder);
  for (; k < word.size(); i++) {
    if (puzzle[i][j] ==  word[k]) {
      j+=2;
      k++;
      continue;
    } else {
      start.clear();
      return false;
    }
  }
 if (j != 0 ) {
      j_holder = j / 2;
    } else {
      j_holder = j;
    }
 
    end.push_back(i-1);
    end.push_back(j_holder-1);
  return true;
} 
bool check_vert_down_horz_left(const vector<vector<char>> & puzzle, string word, vector<int> &
start, vector<int> &end, int i, int j) {
  int k = 0;
  int j_holder;
  if (j == 0) {
    j_holder = j;
  } else  {
    j_holder = j / 2;
  }
    start.push_back(i);
    start.push_back(j_holder);
  for (; k < word.size(); i++) {
    if (puzzle[i][j] ==  word[k]) {
      j-=2;
      k++;
      continue;
    } else {
      start.clear();
      return false;
    }
  }
 if (j_holder != 0 ) {
      j_holder = j / 2;
    } else {
      j_holder = j;
    }
 
    end.push_back(i-1);
    end.push_back(j_holder+1);
  return true;
} 
