#include <iostream>
#include <locale.h>
#include <string.h>

using namespace std;

int contagemContato=0, totalContato=31, totalInfo=3;
string info[3/*totalInfo*/]={"Nome", "Tel.", "E-mail"};
char contato[31/*totalContato*/][3/*totalInfo*/][100], input[100];
string semcontato=" Você não possui contatos.";

void addcontato(){
    if(contagemContato<totalContato-1){
        for(int i=0; i<totalInfo; i++){
            cout<<" Digite o "<<info[i]<<": ";
            cin.sync();
            cin>>contato[contagemContato][i];
        }
        for(int i=0; i<=totalContato; i++){
            if((strcmp(contato[contagemContato][0], contato[i][0]))==0 && i!=contagemContato){
                cout<<"\n Contato já existente.";
                break;
            } else if(i==totalContato){
                cout<<"\n Contato adicionado!";
                contagemContato++;
            }
        }
    } else{
        cout<<" Lista cheia!";
    }
}
void edtcontato(){
    char auxcontato[totalInfo][100];

    if(contagemContato>0){
        cout<<" Insira o nome do contato: ";
        cin.sync();
        cin>>input;

        for(int i=0; i<contagemContato; i++){
            if(strcmp(input, contato[i][0])==0){
                cout<<"\n >";
                for(int i2=0; i2<totalInfo; i2++){
                    cout<<" "<<info[i2]<<": "<<contato[i][i2]<<" |";
                    strcpy(auxcontato[i2], contato[i][i2]);
                }
                cout<<endl<<endl;
                for(int i2=0; i2<totalInfo; i2++){
                    cout<<" Digite o "<<info[i2]<<": ";
                    cin.sync();
                    cin>>contato[i][i2];
                }
                for(int i2=0; i2<=contagemContato; i2++){
                    if((strcmp(contato[i][0], contato[i2][0])==0) && i!=i2){
                        for(int i3=0; i3<totalInfo; i3++){
                            strcpy(contato[i][i3], auxcontato[i3]);
                        }
                        cout<<"\n Contato já existente.";
                        break;
                    } else if(i2==contagemContato){
                        cout<<"\n Contato atualizado!";
                    }
                }
            }
            if(strcmp(auxcontato[0],"")!=0){break;}
            else if(i==contagemContato-1){cout<<"\n Contato não encontrado.";}
        }
    } else{cout<<semcontato;}
}
void rmvcontato(){
    if(contagemContato>0){
        cout<<" Insira o nome do contato: ";
        cin.sync();
        cin>>input;

        for(int i=0; i<totalContato; i++){
            if(strcmp(input, contato[i][0])==0){
                for(int i2=i; i2<totalContato; i2++){
                    for(int i3=0; i3<totalInfo; i3++){
                        strcpy(contato[i2][i3], contato[i2+1][i3]);
                        strcpy(contato[i2+1][i3], "");
                    }
                }
                cout<<"\n Contato removido!";
                contagemContato--;
                break;
                } else if(i==totalContato-1){cout<<"\n Contato não encontrado."; break;}
        }
    } else{cout<<semcontato;}
}
void psqcontatonome(){
    int resultado=0;

    if(contagemContato>0){
        cout<<" Pesquisar: ";
        cin.sync();
        cin>>input;

        for(int i=0; i<contagemContato; i++){
            if(strcmp(contato[i][0], input)==0){
                resultado++;
            }
        }
        if(resultado>0){
            cout<<" "<<resultado<<" Resultado";
            if(resultado>1){cout<<"s.\n\n";}
            else{cout<<".\n\n";}

            for(int i=0; i<contagemContato; i++){
                    if(strcmp(contato[i][0], input)==0){
                        cout<<" >";
                        for(int i3=0; i3<totalInfo; i3++){
                            cout<<" "<<info[i3]<<": "<<contato[i][i3]<<" |";
                        }
                        resultado--;
                        if(resultado>0){
                            cout<<"\n_______________________________________________________________________________________________________________\n\n";
                        }
                    }
            }
        } else{cout<<" Sem resultados.";}
    } else{cout<<semcontato;}
}
void psqcontatotel(){
    int resultado=0;

    if(contagemContato>0){
        cout<<" Pesquisar: ";
        cin.sync();
        cin>>input;

        for(int i=0; i<contagemContato; i++){
            if(strcmp(contato[i][1], input)==0){
                resultado++;
            }
        }
        if(resultado>0){
            cout<<" "<<resultado<<" Resultado";
            if(resultado>1){cout<<"s.\n\n";}
            else{cout<<".\n\n";}

            for(int i=0; i<contagemContato; i++){
                    if(strcmp(contato[i][1], input)==0){
                        cout<<" >";
                        for(int i3=0; i3<totalInfo; i3++){
                            cout<<" "<<info[i3]<<": "<<contato[i][i3]<<" |";
                        }
                        resultado--;
                        if(resultado>0){
                        cout<<"\n_______________________________________________________________________________________________________________\n\n";
                        }
                    }
            }
        } else{cout<<" Sem resultados.";}
    } else{cout<<semcontato;}
}
void psqcontatomail(){
    int resultado=0;

    if(contagemContato>0){
        cout<<" Pesquisar: ";
        cin.sync();
        cin>>input;

        for(int i=0; i<contagemContato; i++){
            if(strcmp(contato[i][2], input)==0){
                resultado++;
            }
        }
        if(resultado>0){
            cout<<" "<<resultado<<" Resultado";
            if(resultado>1){cout<<"s.\n\n";}
            else{cout<<".\n\n";}

            for(int i=0; i<contagemContato; i++){
                    if(strcmp(contato[i][2], input)==0){
                        cout<<" >";
                        for(int i3=0; i3<totalInfo; i3++){
                            cout<<" "<<info[i3]<<": "<<contato[i][i3]<<" |";
                        }
                        resultado--;
                        if(resultado>0){
                        cout<<"\n_______________________________________________________________________________________________________________\n\n";
                        }
                        break;
                    }
            }
        } else{cout<<" Sem resultados.";}
    } else{cout<<semcontato;}
}
void exbcontato(){
    char auxcontato[100];

    for(int i=0; i<contagemContato; i++){
        for(int i2=i; i2<contagemContato-1; i2++){
            if(strcmp(contato[i2][0],contato[i2+1][0])>0){
                for(int i3=0; i3<totalInfo; i3++){
                    strcpy(auxcontato, contato[i2][i3]);
                    strcpy(contato[i2][i3], contato[i2+1][i3]);
                    strcpy(contato[i2+1][i3], auxcontato);
                }
            }
        }
    }

    if(contagemContato>0){
        cout<<" "<<contagemContato<<"/"<<totalContato-1<<" contatos."<<endl<<endl;
        for(int i=0; i<contagemContato; i++){
            cout<<" >";
            for(int i2=0; i2<totalInfo; i2++){
                cout<<" "<<info[i2]<<": "<<contato[i][i2]<<" |";
            }
            if(i<contagemContato-1){
                cout<<"\n_______________________________________________________________________________________________________________\n\n";
            }
        }
        cout<<endl;
    } else{cout<<semcontato;}
}

int main(){
    setlocale(LC_ALL, "portuguese");
    int menu=1;

    while(menu>0 && menu<8){
        cout<<
        endl<<"_____________________________"<<
        endl<<"                             |"<<
        endl<<"            MENU             |"<<
        endl<<"                             |"<<
        endl<<" 1 - Adicionar Contato       |"<<
        endl<<" 2 - Editar Contato          |"<<
        endl<<" 3 - Remover Contato         |"<<
        endl<<" 4 - Pesquisar Nome          |"<<
        endl<<" 5 - Pesquisar Tel.          |"<<
        endl<<" 6 - Pesquisar E-mail        |"<<
        endl<<" 7 - Exibir Todos            |"<<
        endl<<" 8 - Sair                    |"<<
        endl<<"                             |"<<
        endl<<"_____________________________|";

        cout<<"\n\n Selecione uma opção: ";
        cin.sync();
        cin>>menu;

        strcpy(input, "");

        cout<<endl<<endl;

        switch(menu){
            case 1: addcontato(); break;
            case 2: edtcontato(); break;
            case 3: rmvcontato(); break;
            case 4: psqcontatonome(); break;
            case 5: psqcontatotel(); break;
            case 6: psqcontatomail(); break;
            case 7: exbcontato(); break;
            default:
                cout<<" Tem certeza?\n 1-Continuar | 2-Sair: ";
                cin>>menu;
                if(menu!=1){menu=10;}
        }
        cout<<endl;
    }
}
