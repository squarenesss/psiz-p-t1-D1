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

tuple <int, int, float, long> makePorownanie(fstream &fileA, fstream &fileB){

    int roznica = 0, porownanie = 0;
    long sizeInBytes = 0L;
    float ber = 0.;
    char a, b;
    string bitSetA, bitSetB;

    while(!fileA.eof()){

        a = fileA.get();
        b = fileB.get();
        sizeInBytes++;

        if(a != b){
            bitSetA = bitset<8>(a).to_string();
            bitSetB = bitset<8>(b).to_string();

            for(int i = 7; i >= 0; i--){
                if(bitSetA[i] != bitSetB[i]) diff++;
                porownanie++;
            }
        }
    }

    sizeInBytes -= 1;
    ber = float(roznica) / (sizeInBytes * 8.) * 100.;

    tuple <int, int, float, long> results = make_tuple(porownanie, roznica, ber);
    return results;
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
