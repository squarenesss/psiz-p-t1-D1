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

int main(int argc, char** argv){
       
    fstream fileA, fileB;
    fileA.open(argv[1]);
    fileB.open(argv[2]);
    if(!fileA.is_open() || !fileB.is_open()){
        addLog("Nie można otworzyć plików");
        addLog("Zatrzymanie programu");
        return 0;
    } else {
        addLog((string) "Zostały otwarte dwa pliki:" + argv[1] + "/" + argv[2]);
    }

    return 0;
}
