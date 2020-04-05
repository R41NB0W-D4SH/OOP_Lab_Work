using namespace std;
 
////////////////////////////////////////////////////////////////
class String
{
protected:
    static const int SZ=18;//максимальный размер строки
    char str[SZ];//сама строка
public:
    String()//конструктор без параметров
    {str[0]='\x0';}
    String(char s[])//конструктор с одним параметром
    {strcpy_s(str, s);}
    void display()//показ строки
    {
        cout <<str <<endl;
    }
    //перевод строки к обычному типу
    operator char*()
    {return str;}
};
///////////////////////////////////////////////////////////////
class Pstring:public String
{
public:
    Pstring():String()
    {}
    Pstring(char s[])
    {
        if(strlen(s)<SZ){
            strcpy_s(str, s);}
        if(strlen(s)>=SZ){
            for(int j=0; j<SZ; j++){
                if(j==(SZ-1)){
                    str[j]='\0';
                    continue;
                }
                str[j]=s[j];                
            }
        }
    }
    void display()
    {String::display();}
};
///////////////////////////////////////////////////////////////
class Pstring2: public Pstring
{
private:
    int number;//номер символа
    char simbol;//символ строки
public:
    Pstring2():Pstring()
    {}
    Pstring2(char s[]):Pstring(s)
    {}
    Pstring2& left(Pstring p2, int number)//в строку s2 помещаются n самых левых символов строки s1
    {
        for(int j=0; j<=number; j++){
            str[j]=p2[j];
            if(j==number){
                str[j]='\0';
            }
        }
        return Pstring2(str);
    }
    Pstring2& mid(Pstring p2, char sl, int n)//в строку s2 помещаются n символов строки s1 начиная с символа s
    {
        for(int j=0; j<strlen(p2); j++){
            if(p2[j]!=sl){
                continue;
            }else{
                for(int i=0; i<=n; i++){
                    str[i]=p2[j+i];
                    if(i==n){
                        str[i]='\0';
                        break;
                    }
                }
            }
        }
        return Pstring2(str);
    }
    Pstring2& right(Pstring p2, int n)//в строку s2 помещаются n самых правых символов строки s1
    {
        int t=strlen(p2)-n;
        for(int j=0; j<=strlen(p2); j++){
            str[j]=p2[j+t];
            if(j==strlen(p2)){
                str[j]='\0';
            }
        }
        return Pstring2(str);
    }
};
///////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL,"");
    Pstring s, s1;
    s="Шла саша по шоссе";    
    s.display();
    s1="Асталависта бэйби нау";
    s1.display();
    Pstring2 s2, s3, s4;
    s3.left(s1, 5);//пять символов слева
    s3.display();
    s2=s3.mid(s1, 'в', 7);//семь символов начиная с символа 'в'
    s2.display();
    s4.right(s1, 9);//девять крайних правых символов
    s4.display();
    cout <<endl;
    system("pause");
    return 0;
}
