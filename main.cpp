#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

//mi prueba de commit
//mi segunda prueba de commit
//mi tercera prueba de commit

/// Funcion split, 
// Retorna un vector de cadenas de caracteres, compuesto por
// todos aquellos elementos de la cadena str, que se
//  encuentran separados por la cadena delimitadora delim
///
vector<string> split(const string& str, const string& delim)
{
    printf("A");
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

// g++ main.cpp -o main.exe
// ./main.exe -e datos.in -s datos.out -n 5

int main(int argc, char **argv){
    
    int c;
    
    vector<int> myVector;
    
    string filenameIN;
    string filenameOUT;
    int numVector;
    
    extern char *optarg;
    opterr = 0;
    
    while ((c = getopt (argc, argv, "e:s:n:")) != -1){
        switch (c){
            case 'e':
                filenameIN = optarg;
                break;
            case 's':
                filenameOUT = optarg;
                break;
            case 'n':
                numVector = atoi(optarg);
                break;
            default:
                abort ();
        }
    }
    cout << filenameIN << " " << filenameOUT << " " << numVector << endl;
    //Aquí debe escribir su lógica

    vector<int> myVector;
    fstream fileIn(filenameIN);
    ofstream fileOut(filenameOUT);

    if(fileIn.is_open()){
        fileIn.open(filenameIN, ios::in);
    }

    ofstream fileOut(filenameOUT);
    if(fileIn.is_open()){
        fileIn.open(filenameIN);
    }

    vector<int> ValoresSumados;
    int suma=0;
    string line;
    for(int i = 0; i < numVector; i++){
        getline(fileIn, line);
        //cout << "Imprimiendo la linea " << i << line << endl;
        vector<string> misNumeros = split(line, " ");
        int acumulador = 0;
        for(int j = 0; j < misNumeros.size(); j++){
            acumulador += stoi(misNumeros[j]);
            suma += acumulador;
            
            //cout << misNumeros[j]<< " ";
        }
        cout << acumulador << endl;
        ValoresSumados[i]=suma;
        suma=0;
    }

    return 0;
}
