#include <bits/stdc++.h>
using namespace std;

bool file_exist(const char *fileName){
    std::ifstream infile(fileName);
    return infile.good();
}

string a;

int main(){
    time_t tt;
    struct tm * ti;
    time (&tt);
    ti = localtime(&tt);
    int day = ti->tm_mday, mon = ti->tm_mon, year = ti -> tm_year;
    year %= 100, mon += 1;
    char sy[100], sm[100], sd[100];
    sprintf(sy, "%d", year);
    sprintf(sm, "%d", mon);
    sprintf(sd, "%d", day);
    string name = strcat(strcat(strcat(strcat(sy, "-"), sm), "-"), sd);
    string lname = name + ".cpp";
    if(!file_exist(lname.c_str())){
      name = lname;
      freopen("template.cpp", "r", stdin);
      freopen(name.c_str(), "w", stdout);
      while(getline(cin, a)) cout << a << "\n";
      system(name.c_str());
      return 0;
    }
    else{
      string tname;
      int cnt = 1;
      char tc[100];
      string lname;
      while(true){
        sprintf(tc, "%d", cnt);
        tname = tc;
        tname = name + "-" + tname;
        lname = tname + ".cpp";
        if(!file_exist(lname.c_str())){
          name = lname;
          freopen("template.cpp", "r", stdin);
          freopen(name.c_str(), "w", stdout);
          while(getline(cin, a)) cout << a << "\n";
          system(name.c_str());
          return 0;
        }
        cnt++;
      }
    }
}
