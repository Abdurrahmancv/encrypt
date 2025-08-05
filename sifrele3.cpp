// Test 2 // Bunu bitir Godot'a başla // Temel motivasyonun Tacint unutma
// Bunu sadece bitirmek için yaptım.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Şifreleme function'ı
void xor_cipher(string& text, int index){
    string newText;
    for(int i=0; i<text.length(); i++){
        newText.push_back(text.at(i)+index);
    }
    text=newText;
}

int main(){
    int choice;
    string filename;
    fstream file;
    string text;
    bool loop=true;
    while(loop){
        cout<<"1) Dosya sifrele\n2) Dosya coz\n3) Cik\n\nSec: "; cin>>choice;

        switch(choice){
        case 1:
            cout<<"Dosya adi: "; cin>>filename; cin.ignore();

            file.open(filename+".txt", ios::out);

            if(!file.is_open()) cout<<"Dosya acilamadi\n";
            else{
                cout<<"Text: "; getline(cin, text);
        
                xor_cipher(text, 2);

                if(!file.is_open()) cout<<"Dosya bulunamadi\n";
                else{
                    file<<text;
                    file.close();
                }
            }break;
        case 2:
            cout<<"Dosya adi: "; cin>>filename; cin.ignore();
            file.open(filename+".txt", ios::in);

            if(!file.is_open()) cout<<"Dosya bulunamadi\n";
            else{
                while(getline(file, text)){
                    xor_cipher(text, -2);
                    cout<<text<<endl;
                }
                file.close();
            }break;
        case 3: loop=false; cout<<"Hoscakal\n"; return 0;
        default: cout<<"Gecersiz tercih\n";
        }
        cout<<endl;
    }

    return 0;
}