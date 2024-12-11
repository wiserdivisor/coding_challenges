#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
  
  //char line[3500];
  string sline;
  ifstream input_data("./input.txt");

  for(int i=0; i<6; i++) {
    getline(input_data,sline);
    cout << sline << endl;
  }

  input_data.close();
}
