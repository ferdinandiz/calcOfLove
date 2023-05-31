#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;


char* tratarString(char palavra[]) {
  unsigned int x = 0;

  //Transformando em minusculo
  while (palavra[x]) {
  palavra[x] = tolower(palavra[x]);
  x++;
  }
  return palavra;
}
void tiraEspaco(char* nome1){
    int tamanho1 = strlen(nome1);
    for(int i=0;i<tamanho1+1;i++){
        if(nome1[i] == ' '){
            for(int k=i;k<tamanho1+1;k++)
                nome1[k] = nome1[k+1];

            tamanho1 -=1;
            i--;
        }
    }
}


void transforma(char *nome1 ){
    int soma1=1, tamanho1 = strlen(nome1);
    for(int i =0;i<tamanho1;i++){
        if(nome1[i]!='0'){
        for(int j = i+1;j<tamanho1; j++){
            if(nome1[j]==nome1[i]){
                nome1[j]='0';
                soma1 +=1;
            }
        }
        nome1[i] = soma1+'0';
        soma1 = 1;
        }else{
            for(int k=i;k<tamanho1+1;k++){
                nome1[k] = nome1[k+1];
            }
            tamanho1 -=1;
            i--;
        }
    }
    nome1[tamanho1] = '\0';
}

int junta(char *nome, string s1, string s2){
    char* n1 = const_cast<char*>(s1.c_str());
    char* n2 = const_cast<char*>(s2.c_str());

    int t1 = strlen(n1), t2 = strlen(n2);
    for(int i = 0;i<t1;i++)
        nome[i] = n1[i];
    for(int i = 0;i<t2;i++)
        nome[i+t1] = n2[i];
    nome[t1+t2] = '\0';
    return t1+t2;
}

void refatora(char *val){
    char a = '1', b;
    for(int i=0;i<strlen(val)+1;i++){
        if(val[i]>'9'){
           b = val[i]-10;

           for(int k =strlen(val);k>=i;k--)
            val[k] = val[k-1];
           val[i] = a;
           val[i+1] = b;
        }
    }
    val[strlen(val)+1] = '\0';
}

void calculaNome (char *nome){
    for(int tam = strlen(nome);tam>2; tam = strlen(nome)){
        for(int i =0 ;i<tam/2;i++){
            nome[i] = nome[i]+ nome[tam-i-1]-'0';
            if(nome[i]>'9')
                refatora(nome);
            else nome[tam-i-1] = '\0';
        }
    }
}

int main() {
    string nome1, nome2;
    char nome[200];
    setlocale(LC_ALL, "");
    // Configurar o locale para lidar com caracteres multibyte
    locale::global(locale(""));
    // Aplicar o locale a cin
    cin.imbue(locale());
    cout<<"---- Matematica do Amor <3 ----"<<endl<<endl;
    cout << "Digite o primeiro nome (sem acento): ";
    getline( cin, nome1 );
    cout << "Digite o segundo nome (sem acento): ";
    getline(cin, nome2);

    int tamanho1 = junta(nome,nome1,nome2);
    tiraEspaco(nome);
    tratarString(nome);
    transforma(nome);
    calculaNome(nome);
    cout<<endl<<"Probabilidade de "<<nome1<<" e "<<nome2<<" ficarem juntos: "<<endl;
    cout<<"==> "<<nome<<"%";

    return 0;
}
