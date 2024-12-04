#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
  // readline
  // prev_dist = 0
  // for each two nums:
  //   if dist > 3 or 0 or prev_dist*curr_dist is negative return
  //   else set prev dist
  int total_safe_no_disruptive = 0;
  int total_safe_one_disruptive = 0;
  char line[256];
  ifstream input_data("./input.txt");

  for(int i=0; i<1000; i++) {
    input_data.getline(line,sizeof(line));
    bool is_safe = true;
    int i_prev_dist = 0;
    int i_grand_prev_dist = 0;
    int i_disruptive_nos = 0;
    char *ca_grand_prev_num;
    char *ca_prev_num = strtok(line," ");
    char *ca_curr_num = strtok(NULL," ");
    while (ca_curr_num != NULL) {      
      int i_prev_num = stoi(ca_prev_num);
      int i_curr_num = stoi(ca_curr_num);
      int i_curr_dist = i_prev_num - i_curr_num;
      if ((abs(i_curr_dist) > 3) || (i_curr_dist == 0) || ((i_prev_dist * i_curr_dist) < 0)) {
        i_disruptive_nos++;
        if(i_disruptive_nos == 1) {
          ca_prev_num = ca_grand_prev_num;
          i_prev_dist = i_grand_prev_dist;
        } else {
          is_safe = false;
          break;
        }
      } else {
        ca_grand_prev_num = ca_prev_num;
        ca_prev_num = ca_curr_num;
        i_grand_prev_dist = i_prev_dist;
        i_prev_dist = i_curr_dist;
        ca_curr_num = strtok(NULL," ");
      }
    }
    if (is_safe && i_disruptive_nos == 0) {
      total_safe_no_disruptive++;
      total_safe_one_disruptive++;
    }
    if (is_safe) {
      total_safe_one_disruptive++;
    }
  }

  cout << "Total safe (no disruptive) reports: " << total_safe_no_disruptive << endl;
  cout << "Total safe (one disruptive) reports: " << total_safe_one_disruptive << endl;
}
