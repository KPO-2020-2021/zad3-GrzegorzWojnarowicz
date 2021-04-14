#include <Rectangle.h>
#include <Matrix2x2.h>
#include "lacze_do_gnuplota.hh"


using namespace std;

int main()
{

        double sinn, coss;
    double angle = 90;
    sinn = sin(angle*M_PI/180);
    coss = cos(angle*M_PI/180);

    Matrix2x2 m2(Vector2D(coss,-sinn), Vector2D(sinn,coss));
        std::ofstream test;
    test.open("../data/vertex.xy", std::ios::trunc); // overwrite mode
    Rectangle rec(Vector2D(0, 0), Vector2D(0, 10), Vector2D(15, 10), Vector2D(15, 0));
    if (test.is_open())
    {
        test << rec.Rotate(m2);

    }
    test.close();
        
    char  Opcja;
    PzG::LaczeDoGNUPlota  Lacze;
    Lacze.DodajNazwePliku("../data/vertex.xy")
            .ZmienSposobRys(PzG::SR_Ciagly)
            .ZmienSzerokosc(6);
    Lacze.DodajNazwePliku("../data/vertex.xy")
            .ZmienSposobRys(PzG::SR_Punktowy)
            .ZmienSzerokosc(2);
    Lacze.Inicjalizuj();  // Start gnuplot.
    Lacze.ZmienTrybRys(PzG::TR_2D);
    Lacze.UstawZakresY(-5,35);
    Lacze.UstawZakresX(-35,35);
    Lacze.Rysuj();

    cout << "Aby zakonczyc nacisnij ENTER ..." << flush;
    cin >> noskipws >> Opcja;
}