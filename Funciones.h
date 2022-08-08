#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
//declaracion de funciones
int acu_trufas(int trufas[5]);
int hallar_maximo(int vec[5]);
void mostrar_menu();
void Ingreso_nombres();
void mensaje();
int tirada();
int sumar(int n1, int n2);
bool empatar(int a, int b);
void Continuar(bool &seguir1);
void mensaje_cuadro(int a, int lanz, int trufas[5],string primer);
void mensaje_trufas_acu(int trufas_primer[5], int trufas_segundo[5], string primer, string segundo);
void mostrar_ganador(int PDV[2],string primero,string segundo,int &pdv_max,string &nombre_max,string &nom_estadistica,int &pdv_estadistica);
void cuadro_final(int trufas_primer[5], int trufas_segundo[5], string primer, string segundo,int oinks1,int oinks2,int lanzj1,int lanzj2,int PDV[2]);
void quien_arranca(bool empate, string player1, string player2, string &primero, string &segundo);
void PuntoA(int n1, int n2, int trufas[5], int x,bool &oink,bool &seguir);
void PuntoB(int n1,int n2,int trufas[5],int i,bool &oink,bool &seguir,bool &barro,int &cont_oink,int &lanzamiento);
void PuntoC(int n1,int n2,int trufas[5],int i,bool &oink,bool &seguir);
void PuntoD(int n1,int n2,int trufas[5],int i,bool &oink,bool &seguir,bool &barro);
void Continuar(bool &turno, bool &seguir);
bool dados_triples(int primer[5],int segundo[5],bool barro1,bool barro2);
void PuntoA3(int n1,int n2,int n3,int trufas[5],int i,bool &oink,bool &seguir);
void PuntoB3(int n1, int n2 , int n3 , int trufas[5] , int x , bool &oink , bool &turno, bool &barro,int &cont_oink,int &lanzamiento);
void PuntoC3(int n1,int n2, int n3, int trufas[5],int i,bool &oink,bool &turno);
void PuntoD3(int n1,int n2,int n3,int trufas[5],int i,bool &oink,bool &turno,bool &barro);
#endif // FUNCIONES_H_INCLUDED
