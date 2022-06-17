#include<iostream>
#include<fstream>
#include<chrono>
#include<tuple>
#include<ctime>
#include<bitset>


using namespace std;

void addLog(string message){
    fstream logFile;
    logFile.open("logi.txt", ios::app);
    time_t t = time(0);
    string dt = ctime(&t);
    logFile << endl << dt.substr(0, dt.length()-1) << " : " << message;
    logFile.close();
}

int main(void){

    

    return 0;
}
