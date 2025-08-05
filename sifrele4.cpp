// Bunu mükemmel (daha perform ve güvenli) hale getirmeye çalışacaktım.
#include <iostream>
#include <fstream>
using namespace std;

void xor_cipher(string& text, int index){
    string newText;
    for(int i=0; i<text.length(); i++){
        //if(text.at(i)+index > 127) newText.push_back((text.at(i)+index)%127);
        //else if(text.at(i)+index < 0) // C++ bunu kendi yapıyormuş.
        newText.push_back(text.at(i)+index);
    }
    text=newText;
}

#include <string>

int main(){
    while(true){
        cout<<"1) Encrypt file\n2) Decrypt file\n3) Quit\n\nChoose: "; string choose; cin>>choose;
        
        if(choose=="3"){cout<<"Goodbye\n"; break;}
        else{
            cout<<"File name: "; string filename; cin>>filename; cin.ignore();
            fstream file;
            string text;
            
            if(choose=="1"){
                file.open(/*"files/"+*/filename+".txt", ios::out);
                
                if(!file.is_open()) cout<<"File cannot be opened\n";
                else{
                    cout<<"Text: "; getline(cin, text);
                    
                    if(!file.is_open()) cout<<"File not found\n";
                    else{
                        cout<<"Encryption key: "; int key=0; cin>>key;
                        xor_cipher(text, key);

                        if(!file.is_open()) cout<<"File not found\n";
                        else{
                            file<<text;
                            file.close();
                        }
                    }
                }
            }
            else if(choose=="2"){
                file.open(filename+".txt", ios::in);
                
                if(!file.is_open()) cout<<"File not found\n";
                else{
                    cout<<"Encryption key: "; int key=0; cin>>key;
                    while(getline(file, text)){
                        xor_cipher(text, -key);
                        cout<<text<<endl;
                    }
                    file.close();
                }
            }
            else cout<<"Invalid choice\n";
        }cout<<endl;
    }

    return 0;
}