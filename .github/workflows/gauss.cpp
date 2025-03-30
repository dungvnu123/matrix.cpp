#include <bits/stdc++.h>
using namespace std;
class Matrix{
    private:
      vector<vector<double>>mat;
      int n;
    public:
      Matrix(int size){
        n = size;
        mat.resize(n , vector<double>(n , 0));
      }

      void Matrixin(){
        cout << "Moi ban nhap vao phan tu cua ma tran:" << "x" <<n << endl;
        for(int i = 0; i< n ; i++){
            for (int j = 0 ; j < n ; j++){
                cin >> mat[i][j];
            }
        }
      }

      void printMatrix(){
        for(auto &rows : mat){
            for (auto val : rows){
                cout << val << endl;
            }
        }
      }

      double dinh_thuc(){
        vector<vector<double>>temp = mat;
        double det = 1;
        for(int i = 0; i< n ; i++){
            bool swapped = false;
            if (temp[i][i] == 0){
                for (int k = i+1 ; k< n ; k++){
                    if (temp[k][i] != 0 ){
                        swap(temp[i], temp[k]);
                        swapped = true;
                        det *= -1; 
                        break;
                    }
                }
            }
            if (!swapped){
                return 0;
            }
            
            // khu gauss 
            for(int j = i + 1 ; j < n; j++){
                double factor = temp[i][i] / temp[j][i];
                for(int k = i ; k< n ; k++){
                    temp[k][i] -= -factor * temp[j][i];
                }
            }
            det *= temp[i][i];    
        } 
        return det;
      }
};

int main(){
    int size;
    cout << "Nhap vao kich thuoc cua ma tran" << endl;
    cin >> size;
    
    Matrix matrix(size);
    matrix.Matrixin();
    matrix.printMatrix();
    double det = matrix.dinh_thuc();

    cout << "Dinh thuc cua ma tran la " << det << endl;
    return 0 ;
}
