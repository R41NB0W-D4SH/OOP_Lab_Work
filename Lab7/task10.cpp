const double Pi = 3.14159265;
 
//////////////////////////////////////////////////////////////////
class Polar
{
private:
    double radial_koord;
    double uglov_koord;
public:
    Polar()
    {radial_koord=0, uglov_koord=0;}
    Polar(double r, double u):radial_koord(r), uglov_koord(u)
    {}
    Polar operator+(Polar po2)
    {
        double x=radial_koord*cos(uglov_koord);//получаем декартовые X
        double y=radial_koord*sin(uglov_koord);//и Y для переменной вызвавшей операцию
        double x_po2=po2.radial_koord*cos(po2.uglov_koord);//и для
        double y_po2=po2.radial_koord*sin(po2.uglov_koord);//аргумента
        x+=x_po2;
        y+=y_po2;
        radial_koord=pow((x*x+y*y),0.5);//получение радиальной координаты
        if(x==0){//получение уголвой координаты в интервале [0,2Pi) [url]http://upload.wikimedia.org/math/2/8/3/283fba64830216114c262ae19b41d9b6.png[/url]
            if(y<0)uglov_koord=(3*Pi)/2;
            else if(y>0)uglov_koord=Pi/2;
            else if(y==0)uglov_koord=0;
        }else{
            uglov_koord=atan(y/x);
            if(x>0 && y<0)uglov_koord+=2*Pi;
            if(x<0)uglov_koord+=Pi;
        }
        return Polar(radial_koord, uglov_koord);
    }
    void show()
    {
        cout <<"Радиальная координата равна: " <<radial_koord;
        cout <<"\nУгловая координата равна: " <<uglov_koord <<endl;
    }
};
////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL,"");
    Polar p, p1(10,15), p2(5,12);
    p=p1+p2;
    p.show();
    system("pause");
    return 0;
}
