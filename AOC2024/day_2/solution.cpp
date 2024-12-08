#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

bool isReportSafe(vector<int> reports_vector){
  for(int i=1; i<(reports_vector.size()-1); i++){
    int dist_1 = reports_vector[i-1] - reports_vector[i];
    int dist_2 = reports_vector[i] - reports_vector[i+1];
    if((abs(dist_1) > 3)||(abs(dist_2) > 3)) {  return false; }
    if((dist_1 == 0)||(dist_2 == 0)) {          return false; }
    if((dist_1 * dist_2) < 0) {                 return false; }
  }
  return true;
}

bool containsOnlyOneBadLevel(vector<int> reports_vector){
  for(int i=0; i<(reports_vector.size()); i++){
    vector<int> one_less_reports_vector = reports_vector;
    one_less_reports_vector.erase(one_less_reports_vector.begin()+i);
    if(isReportSafe(one_less_reports_vector)){
      return true;
    }
  }
  return false;
}

int howManyBadLevels(char *reports) {

  vector<int> reports_vector;
  char *token = strtok(reports," ");
  while (token != NULL) {
    int i_token = stoi(token);
    reports_vector.push_back(i_token);
    token = strtok(NULL," ");
  }

  if(isReportSafe(reports_vector)) {
    return 0;
  }
  if(containsOnlyOneBadLevel(reports_vector)) {
    return 1;
  } else {
    return 2;
  }

}

int main() {

  int total_safe_no_bad = 0;
  int total_safe_one_bad = 0;
  char line[256];
  ifstream input_data("./input.txt");

  for(int i=0; i<1000; i++) {

    input_data.getline(line,sizeof(line));

    int i_numBadReports = howManyBadLevels(line);

    switch(i_numBadReports){
      case 0: total_safe_no_bad++; total_safe_one_bad++; break;
      case 1: total_safe_one_bad++; break;
      default: break; 
    }

  }

  cout << "Total safe (no bad) reports: " << total_safe_no_bad << endl;
  cout << "Total safe (one bad) reports: " << total_safe_one_bad << endl;

}
