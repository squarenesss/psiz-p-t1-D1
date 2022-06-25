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

    addLog("Rozpoczecie analizy plikow");
    auto start = chrono::high_resolution_clock::now();
    
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

    auto stop = chrono::high_resolution_clock::now();
    createLog("Zakonczenie analizy plikow");
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    
    tuple <int, int, float, long> results = make_tuple(porownanie, roznica, ber, duration.count());
    return results;
}

int main(int argc, char** argv){
       
    fstream fileA, fileB;
    fileA.open(argv[1]);
    fileB.open(argv[2]);
    if(!fileA.is_open() || !fileB.is_open()){
        addLog("Nie mozna otworzyc plikow");
        addLog("Zatrzymanie programu");
        return 0;
    } else {
        addLog((string) "Zostaly otwarte dwa pliki:" + argv[1] + "/" + argv[2]);
    }
    
    tuple<int, int, float, long> results = makePorownanie(fileA, fileB);
    
    string resultMsg = "Wyniki analizy: Porownane bity: " + to_string(get<0>(results)) + 
                        "; Rozne bity: " + to_string(get<1>(results)) + 
                        "; BER: " + to_string(get<2>(results)) + "%" + 
                        "; Czas analizy: " + to_string(get<3>(results)) + " ms";
    addLog(resultMsg);
    cout << resultMsg << endl;
    
    fileA.close();
    fileB.close();
    addLog("Pliki zostały zakmniete")
    
    return 0;
}
