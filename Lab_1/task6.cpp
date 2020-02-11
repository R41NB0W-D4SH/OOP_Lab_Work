#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
    float d, s, f, m, y;

    cout << "Введите денежную сумму в долларах : ";
    cin >> d;

    cout << endl << "Курсы валют: " << endl << endl;
    cout << "1 фунт стерлингов = $1.487" <<
    endl << "1 франк = $0.172" <<
    endl << "1 немецкая марка = $0.584" <<
    endl << "1 японская йена = $0.00955" << endl;

    s = d * (1 / 1.487);
    f = d * (1 / 0.172);
    m = d * (1 / 0.0584);
    y = d * (1 / 0.00955);
    //float r = d * (1 / 0.016);

    cout << d << " $ = " << s << " фунты стерлингов" << endl;
    cout << d << " $ = " << f << " франки" << endl;
    cout << d << " $ = " << m << " немецкие марки" << endl;
    cout << d << " $ = " << y << " японские йены" << endl;
    //cout << d << " $ = " << r << " рубли" << endl;

    system("pause");
    return 0;
}
