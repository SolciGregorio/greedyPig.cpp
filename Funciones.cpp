#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
//definiciones de funciones

void mostrar_menu(){
    cout<<endl;
    cout<<" BIENVENIDO AL GRAN CERDO"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"1 - JUGAR"<<endl;
    cout<<"2 - ESTADISTICAS"<<endl;
    cout<<"3 - CERDITOS"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"0 - SALIR"<<endl;
    cout<<endl;
}
int acu_trufas(int trufas[5]){
    int acu=0;
    for(int i=0;i<5;i++){
        acu+=trufas[i];
    }
    return acu;
}
int hallar_maximo(int vec[5]){
    int i,maximo=0;
    maximo=vec[0];
    for(i=1;i<5;i++){
        if(vec[i]>maximo){
            maximo=vec[i];
        }
    }
    return maximo;
}
void Ingreso_nombres(){
    string jugador1,jugador2;
    cout<<"INGRESAR EL NOMBRE DEL JUGADOR UNO : ";
        cin>>jugador1;
        cin.ignore();
        cout<<"INGRESAR EL NOMBRE DEL JUGADOR DOS : ";
        cin>>jugador2;
        cout<<endl<<" PREPARATE PARA JUGAR AL GRAN CERDO! "<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"SE SORTEARAN LOS DADOS PARA INDICAR QUE JUGADOR EMPIEZA PRIMERO"<<endl<<endl;
}
void mensaje(){
    cout<<"---------------------------"<<endl;
    cout<<"SE SORTEARAN LOS DADOS PARA INDICAR QUE JUGADOR EMPIEZA PRIMERO"<<endl;
    cout<<"---------------------------"<<endl;
}
int tirada(){
  return (rand() % 6)+1;
}
int sumar(int n1, int n2){
    int resultado;
    resultado = n1+n2;
    return resultado;
}
bool empatar(int a, int b){
    if(a==b){
        return true;
    }
    else{
        return false;
    }

}
void mensaje_cuadro(int a, int lanz, int trufas[5],string primer){
    cout<<"RESUMEN DE "<<primer<<endl;
    cout<<"+---------------------------+"<<endl;
    cout<<"| RONDAS #"<<a<<"                 |"<<endl;
    cout<<"| TRUFAS DE LA RONDA: "<<trufas[a-1]<<"    |"<<endl;
    cout<<"| LANZAMIENTOS: "<<lanz-1<<"           |"<<endl;
    cout<<"+---------------------------+"<<endl;
}
void mensaje_trufas_acu(int trufas_primer[5], int trufas_segundo[5],string primer, string segundo){
    int acu1=0,acu2=0;
    cout<<"GRAN CERDO"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<primer<<": ";
    for(int i=0;i<5;i++){
        acu1+=trufas_primer[i];
    }
    cout<<acu1<<" trufas acumuladas";
    cout<<"           "<<segundo<<": ";
    for(int i=0;i<5;i++){
        acu2+=trufas_segundo[i];
    }
    cout<<acu2<<" trufas acumuladas"<<endl<<endl;
}
void cuadro_final(int trufas_primer[5], int trufas_segundo[5], string primer, string segundo,int oinks1,int oinks2,int lanzj1,int lanzj2,int PDV[2]){
    int acu1=0,acu2=0;
    acu1=acu_trufas(trufas_primer);
    acu2=acu_trufas(trufas_segundo);
    cout<<"GRAN CERDO"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"HITO                     "<<primer<<"                           "<<segundo<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Mas trufas en total      ";
    if(acu1>acu2){
        cout<<"5 PDV ("<<acu1<<" trufas)";
        PDV[0]+=5;
    }
    else{
            if(acu1<acu2){
            cout<<"0 PDV ("<<acu1<<" trufas)";
            }
            else{
                cout<<"5 PDV ("<<acu1<<" trufas)";
                PDV[0]+=5;
            }
    }
    cout<<"              ";
    if(acu2>acu1){
        cout<<"5 PDV ("<<acu2<<" trufas)"<<endl;
        PDV[1]+=5;
    }
    else{
            if(acu2<acu1){
            cout<<"0 PDV ("<<acu2<<" trufas)"<<endl;
            }
            else{
                cout<<"5 PDV ("<<acu2<<" trufas)"<<endl;
                PDV[1]+=5;
            }
    }
    cout<<"Cada 50 trufas           ";
    cout<<acu1/50<<" PDV ("<<(acu1/50)*50<<" trufas)               ";
    PDV[0]+=(acu1/50);
    cout<<acu2/50<<" PDV ("<<(acu2/50)*50<<" trufas)"<<endl;
    PDV[1]+=(acu2/50);
    cout<<"Oinks                    ";
    cout<<oinks1*2<<" PDV ("<<oinks1<<" oinks)                ";
    PDV[0]+=(oinks1*2);
    cout<<oinks2*2<<" PDV ("<<oinks2<<" oinks)"<<endl;
    PDV[1]+=(oinks2*2);
    cout<<"Cerdo codicioso          ";
    if(lanzj1>lanzj2){
        cout<<"3 PDV ("<<lanzj1<<" lanzamientos)";
        PDV[0]+=3;
    }
    else{
        if(lanzj1<lanzj2){
            cout<<"0 PDV ("<<lanzj1<<" lanzamientos)";
        }
        else{
            cout<<"3 PDV ("<<lanzj1<<" lanzamientos)";
            PDV[0]+=3;
        }
    }
    cout<<"         ";
    if(lanzj2>lanzj1){
        cout<<"3 PDV ("<<lanzj2<<" lanzamientos)"<<endl;
        PDV[1]+=3;
    }
    else{
        if(lanzj2<lanzj1){
            cout<<"0 PDV ("<<lanzj2<<" lanzamientos)"<<endl;
        }
        else{
            cout<<"3 PDV ("<<lanzj2<<" lanzamientos)"<<endl;
            PDV[1]+=3;
        }
    }

    cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"TOTAL                    ";
    cout<<PDV[0]<<" PDV                       "<<PDV[1]<<" PDV"<<endl;
}
void quien_arranca(bool empate, string player1, string player2, string &primero, string &segundo){
    srand (time(0));
    empate=false;
    int dado1,dado2,suma1,suma2;
    do{
                cout<<"El jugador "<<player1<<" tiro los dados:";
                dado1= tirada();
                dado2= tirada();
                suma1=dado1+dado2;
                cout<<endl<<"      obtuvo "<<suma1<<" de puntaje "<<endl;
                cout<<"El jugador "<<player2<<" tiro los dados:";
                dado1= tirada();
                dado2= tirada();
                suma2=dado1+dado2;
                cout<<endl<<"      obtuvo "<<suma2<<" de puntaje "<<endl;
                empate = empatar(suma1,suma2);
                if(empate==true){
                cout<<"----------------------------------------------------"<<endl;
                cout<<"AMBOS JUGADORES EMPATARON SE VUELVE A TIRAR DE NUEVO"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                }

            }while(empate==true);
            if(suma1>suma2){
                primero=player1;
                segundo=player2;
            }
            else{
                primero=player2;
                segundo=player1;
            }
}
void PuntoC(int n1,int n2,int trufas[5],int i,bool &oink,bool &turno){
    if((n1!=n2) && (n1 == 1 || n2 == 1))
        {
        cout<<endl<< "PIERDES TODAS LAS TRUFAS ACUMULADAS DE LA RONDA " <<endl;
        cout<<"!PIERDES TU TURNO!"<<endl;
        trufas[i-1]=0;
        turno=true;
        oink=false;
        }
}
void PuntoD(int n1,int n2,int trufas[5],int i,bool &oink,bool &turno,bool &barro){
    if( (n1==n2) && (n1==1) ){
        oink=false;
        cout<<endl<<"|TE HUNDISTE EN EL BARRO|"<<endl;
        cout<<endl<< "PIERDES TODAS LAS TRUFAS ACUMULADAS HASTA EL MOMENTO " <<endl;
        cout<<"!PIERDES TU TURNO!"<<endl;
        for(int x=0;x<5;x++){
            trufas[x]=0;
        }
        turno=true;
        barro=true;
    }
}
void PuntoA(int n1, int n2, int trufas[5], int x,bool &oink,bool &turno){
    if( (n1!=n2) && (n1!=1 && n2!=1) )
        {
            turno=false;
            oink=false;
            trufas[x-1]+=n1+n2;
            cout<<endl<<"�Sumaste " <<n1+n2<<" trufas! "<<endl;
        }
}
void PuntoB(int n1,int n2,int trufas[5],int x,bool &oink,bool &turno,bool &barro,int &cont_oink,int &lanzamiento){
    if((n1==n2) && (n1!=1 && n2!=1))
        {
        //turno=true;
        oink=true;
        trufas[x-1]+=(n1+n2)*2;
        cout<<endl<<"HICISTE UN OINK! DUPLICASTE LAS TRUFAS OBTENIDAS EN EL LANZAMIENTO "<<endl;
        cout<<endl<<"�Sumaste " <<(n1+n2)*2<<" trufas! "<<endl;
        cont_oink++;
        }
    while(oink==true){
        cout<<endl<<"TIRABA OBLIGATORIA"<<endl;
        cout<<"---------------"<<endl;
        cout<<endl<<"LANZAMIENTO #"<<lanzamiento++<<endl<<endl;
        n1=tirada();
        n2=tirada();
        cout<<"Obtuvo "<<n1<<" y "<<n2<<endl;
        PuntoC(n1,n2,trufas,x,oink,turno);
        //PuntoD(n1,n2,trufas,x,oink,turno,barro);
        //PUNTO D
        if( (n1==n2) && (n1==1) ){
        oink=false;
        turno=true;
        barro=true;
        cout<<endl<<"|TE HUNDISTE EN EL BARRO|"<<endl;
        cout<<endl<< "PIERDES TODAS LAS TRUFAS ACUMULADAS HASTA EL MOMENTO " <<endl;
        cout<<"!PIERDES TU TURNO!"<<endl;
        for(int x=0;x<5;x++){
            trufas[x]=0;
        }
        }
        PuntoA(n1,n2,trufas,x,oink,turno);
        //PUNTO B
        if((n1==n2) && (n1!=1 && n2!=1))
        {
        turno=true;
        oink=true;
        trufas[x-1]+=(n1+n2)*2;
        cout<<endl<<"HICISTE UN OINK! DUPLICASTE LAS TRUFAS OBTENIDAS EN EL LANZAMIENTO "<<endl;
        cout<<endl<<"�Sumaste " <<(n1+n2)*2<<" trufas! "<<endl;
        cont_oink++;
        }
        //PuntoD(n1,n2,trufas,x,oink,turno,barro);
        //PuntoC(n1,n2,trufas,x,oink,turno);
    }
}
void Continuar(bool &turno,bool &seguir){
    if(turno==true){
        seguir=false;
    }
    else{
    cout<<endl<<"DESEA SEGUIR JUGANDO S(1)/N(0)"<<endl;
    cin>>seguir;
    }
}
bool dados_triples(int primer[5],int segundo[5],bool barro1,bool barro2){
    int acu1=0,acu2=0;
    for(int i=0;i<5;i++){
        acu1+=primer[i];
        acu2+=segundo[i];
    }
    if( (acu1>=50 && acu2>=50) || (barro1==true || barro2==true)){
        return true;
    }
    else{
        return false;
    }
}
void PuntoC3(int n1,int n2, int n3, int trufas[5],int i,bool &oink,bool &turno){
    if((n1!=n2 && n2!=n3 && n1!=n3) && (n1 == 1 || n2 == 1 || n3==1))
        {
        cout<<endl<< "PIERDES TODAS LAS TRUFAS ACUMULADAS DE LA RONDA " <<endl;
        cout<<"!PIERDES TU TURNO!"<<endl;
        trufas[i-1]=0;
        turno=true;
        oink=false;
        }
}
void PuntoD3(int n1,int n2,int n3,int trufas[5],int i,bool &oink,bool &turno,bool &barro){
    int acu1=0;
    acu1= acu_trufas(trufas);
    if( (n1==1 && n2==1 && n3!=1) || (n1==1 && n2!=1 && n3==1) ||(n1!=1 && n2==1 && n3==1) ){
        oink=false;
        cout<<endl<<"|TE HUNDISTE EN EL BARRO|"<<endl;
        cout<<endl<< "PIERDES TODAS LAS TRUFAS ACUMULADAS HASTA EL MOMENTO " <<endl;
        cout<<"!PIERDES TU TURNO!"<<endl;
        for(int x=0;x<5;x++){
            trufas[x]=0;
        }
        turno=true;
        barro=true;
    }
}
void PuntoA3(int n1,int n2,int n3,int trufas[5],int x,bool &oink,bool &turno){
    if( (n1!=n2 && n2!=n3 && n1!=n3) && (n1!=1 && n2!=1 && n3!=1) )
        {
            turno=false;
            oink=false;
            trufas[x-1]+=(n1+n2+n3);
            cout<<endl<<"�Sumaste " <<n1+n2+n3<<" trufas! "<<endl;
        }
    if( ((n1==n2 && n3!=n2) || (n1==n3 && n2!=n3) || (n2==n3 && n1!=n2)) && (n1!=1 && n2!=1 && n3!=1) ){
        turno=false;
            oink=false;
            trufas[x-1]+=(n1+n2+n3);
            cout<<endl<<"�Sumaste " <<n1+n2+n3<<" trufas! "<<endl;
    }
}
void PuntoB3(int n1, int n2 , int n3 , int trufas[5] , int x , bool &oink , bool &turno, bool &barro,int &cont_oink,int &lanzamiento){
    if ((n1==n2 && n2==n3) && (n1!=1 && n2!=1 && n3!=1) ){
        //turno=false;
        oink=true ;
        trufas[x-1]+=(n1+n2+n3)* 2 ;
        cout<<endl<<"HICISTE UN OINK! DUPLICASTE LAS TRUFAS OBTENIDAS EN EL LANZAMIENTO "<<endl;
        cout<<endl<<"�Sumaste " <<(n1+n2+n3)*2<<" trufas! "<<endl;
        cont_oink++;
        }
    while(oink==true){
        cout<<endl<<"TIRABA OBLIGATORIA"<<endl;
        cout<<"---------------"<<endl;
        cout<<endl<<"LANZAMIENTO #"<<lanzamiento++<<endl<<endl;
        n1=tirada();
        n2=tirada();
        n3=tirada();
        cout<<"Obtuvo "<<n1<<" , "<<n2<< " Y " << n3 << endl;

        PuntoC3(n1, n2,n3, trufas,x, oink, turno);
        PuntoD3( n1, n2,n3, trufas, x, oink, turno, barro);
        PuntoA3(n1,n2,n3,trufas, x, oink , turno);
        //PUNTO B
        if ((n1==n2 && n2==n3) && (n1!=1 && n2!=1 && n3!=1) ){
        //turno=false;
        oink=true ;
        trufas[x-1]+=(n1+n2+n3)* 2 ;
        cout<<endl<<"HICISTE UN OINK! DUPLICASTE LAS TRUFAS OBTENIDAS EN EL LANZAMIENTO "<<endl;
        cout<<endl<<"�Sumaste " <<(n1+n2+n3)*2<<" trufas! "<<endl;
        cont_oink++;
        }
        }
}
void mostrar_ganador(int PDV[2],string primero,string segundo,int &pdv_max,string &nombre_max,string &nom_estadistica,int &pdv_estadistica){
    cout<<endl;
    if(PDV[0] > PDV[1]){
       cout<<"GANADOR: "<<primero<<" con "<<PDV[0]<<" de victoria"<<endl;
        pdv_max=PDV[0];
        nombre_max=primero;
       }
    else{
        if(PDV[1]>PDV[0]){
            cout<<"GANADOR: "<<segundo<<" con "<<PDV[1]<<" de victoria"<<endl;
            pdv_max=PDV[1];
        nombre_max=segundo;
        }
        else{
            cout<<"AMBOS JUGADORES EMPATARON CON "<<PDV[0]<<" DE VICTORIA"<<endl;
            pdv_max=PDV[0];
        nombre_max=primero;
        }
    }

    if(pdv_max>pdv_estadistica){
        pdv_estadistica=pdv_max;
        nom_estadistica=nombre_max;
    }
}
