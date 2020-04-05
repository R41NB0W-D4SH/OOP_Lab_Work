using namespace std;
 
const int LIMIT=100;
//////////////////////////////////////////////////////////////////
class safearray
{
protected:
    int arr[LIMIT];
public:
    //функция возвращает ссылку
    int& operator[](int n)
    {
        if(n<0||n>=LIMIT){
            cout <<"Ошибочный индекс!";
            exit(1);
        }
        return arr[n];
    }
};
/////////////////////////////////////////////////////////////////
class safehilo: private safearray
{
private:
    int min;
    int max;
public:
    safehilo():min(0), max(0)
    {}
    safehilo(int mn, int mx):min(mn), max(mx)
    {}
    void getin()
    {
        cout <<"Введите min массива: "; cin >>min;
        cout <<"Введите max массива: "; cin >>max;
    }
    void zap_mass()
    {
        int puk=max-min;
        if(puk>LIMIT)exit(1);
        for(int j=0; j<=puk; j++){
            arr[j]=j*10;
        }
    }
    void show_arr()
    {
        int puk=max-min;
        for(int j=0; j<=puk; j++){
            int temp=arr[j];
            cout <<"Элемент " <<j+min <<" равен " <<temp <<endl;
        }
    }
};
//////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL,"");
    safehilo sh1;
    sh1.getin();
    sh1.zap_mass();
    sh1.show_arr();
    system("pause");
    return 0;
}
