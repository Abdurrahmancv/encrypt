#include <iostream>
#include <fstream>
using namespace std;

// Encryption methods
void ascii_cipher(string& text, int index){
    string newText;
    for(int i=0; i<text.length(); i++){
        //if(text.at(i)+index > 255) newText.push_back((text.at(i)+index)%255); // Canceled?
        newText.push_back(text.at(i)+index);
    }
    text=newText;
}

void xor_cipher(){}

// Other
void func1(string& filename){ // Dosya adı alır.
    cout<<"File name: "; cin>>filename; cin.ignore();
}

void func2(int& key){ // Şifreleme anahtarı alır.
    cout<<"Encryption key: "; cin>>key;
}

#include <string>

int main(){
    while(true){
        cout<<"1) Encrypt file\n2) Decrypt file\n3) Quit\n\nChoose: "; string choose; cin>>choose;
        
        if(choose=="3"){cout<<"Goodbye\n"; break;}
        else{
            
            fstream file;
            string text;
            string filename;
            int key=0;
            
            if(choose=="1"){
                func1(filename);
                file.open(/*"files/"+*/filename+".txt", ios::out);
                
                if(!file.is_open()) cout<<"File cannot be opened\n";
                else{
                    cout<<"Text: "; getline(cin, text);
                    
                    if(!file.is_open()) cout<<"File not found\n";
                    else{
                        func2(key);

                        ascii_cipher(text, key);

                        if(!file.is_open()) cout<<"File not found\n";
                        else{
                            file<<text;
                            file.close();
                        }
                    }
                }
            }
            else if(choose=="2"){
                func1(filename);
                file.open(filename+".txt", ios::in);
                
                if(!file.is_open()) cout<<"File not found\n";
                else{
                    func2(key);

                    while(getline(file, text)){
                        ascii_cipher(text, -key);
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
