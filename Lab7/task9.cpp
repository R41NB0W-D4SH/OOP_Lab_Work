const int LIMIT=100;
//////////////////////////////////////////////////////////////////
class safearray
{
private:
    int min;
    int max;
    int arr[LIMIT];
public:
    safearray()
    {min=0, max=0;}
    safearray(int mn, int mx):min(mn), max(mx)
    {}
    void getin(){
        cout <<"Введите min элемент массива: ";
        cin >>min;
        cout <<"Введите max элемент массива: ";
        cin >>max;
        int puk=max-min;
        if(puk>100)exit(1);
        //задаем значения элементов      
        for(int j=0; j<=puk; j++)
        arr[j]=j*10;//используем ф-ию слева от знака
        //показываем элементы
        for(int j=0; j<=puk; j++){
        int temp=arr[j];//используем ф-ию справа от знака
        cout <<"Элемент " <<j+min <<" равен " <<temp <<endl;
        }
    }
    //функция возвращает ссылку
    int& operator[](int n)
    {
        if(n<min||n>=max){
            cout <<"Ошибочный индекс!";
            exit(1);
        }
        return arr[n];
    }
};
/////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL,"");
    safearray sa;
    sa.getin();
    system("pause");
    return 0;
}
