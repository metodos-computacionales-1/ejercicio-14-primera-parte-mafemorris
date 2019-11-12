#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void euler(double* x, double* v, double h, double k, double m, double lambda, int pasos);
double dx(double k, double m, double lambda);
double dv(double v);

template <class T>
void escribe(string archivo, T* datos, int n_dat){
  ofstream outfile;
  //abre el archivo.
  outfile.open(archivo);

  for (int i=0; i < n_dat; i++){
    outfile << datos[i] << endl;
  }
  //cierra el archivo.
  outfile.close(); 
}

int main(){
    int lambda = 1;
    double k = 100;
    double m = 2;
    double h = 0.01;
    double x0 = 0;
    double xf = 10;
    int pasos = (xf-x0)/h;
    
    double* x = new double[pasos];
    double* v = new double[pasos];

    euler(x,v,h,k,m,lambda,pasos);
    escribe("x.txt",x,pasos);
    escribe("v.txt",v,pasos);

    delete[] x;
    delete[] v;

    return 0;
}



double dx(double x, double k, double m, double lambda){
    return (-k/m)*pow(x,lambda);
}

double dv(double v){
    return v;
}


void euler(double* x, double* v, double h, double k, double m, double lambda, int pasos){
    x[0] = 1; //condiciones iniciales
    v[0] = 1;

    for(int i=1; i<pasos; i++){
        x[i] = x[i-1] + h*dx(x[i-1],k,m,lambda); 
        v[i] = v[i-1] + h*dv(v[i-1]);
        cout << x[i] << " " << v[i] << endl;
    }
}
