#include <Rectangle.h>
#include <Matrix2x2.h>
#include <chrono>
#include <thread>
#include "lacze_do_gnuplota.hh"

Rectangle argErrorHandling(int argc, char **argv);

int main(int argc, char** argv)
{

    
    int num_of_rotations, actual_num_of_rotatations;
    actual_num_of_rotatations = 0;
    Rectangle rec1 = argErrorHandling(argc, argv);
    std::cout << "Podaj ilość obrotów prostokąta" << std::endl;
    if(std::cin >> num_of_rotations){
        double sinn, coss;
        int angle;
        std::cout << "Podaj kąt obrotu" << std::endl;
        if(std::cin >> angle){
            sinn = sin((angle%360)*M_PI/180);
            coss = cos((angle%360)*M_PI/180);
            PzG::LaczeDoGNUPlota  Lacze;
            Lacze.DodajNazwePliku("../data/vertex.xy")
                    .ZmienSposobRys(PzG::SR_Ciagly)
                    .ZmienSzerokosc(6);
            Lacze.DodajNazwePliku("../data/vertex.xy")
                    .ZmienSposobRys(PzG::SR_Punktowy)
                    .ZmienSzerokosc(2);
            if (argv[1]>argv[3]){
                Lacze.UstawZakresY((-2)*abs(atof(argv[1])),2*abs(atof(argv[1])));
            }else{
                Lacze.UstawZakresY((-2)*abs(atof(argv[3])),2*abs(atof(argv[3])));
            }
            if (argv[0]>argv[2]){
                Lacze.UstawZakresX((-2)*abs(atof(argv[0])),2*abs(atof(argv[0])));
            }else{
                Lacze.UstawZakresX((-2)*abs(atof(argv[2])),2*abs(atof(argv[2])));
            }

            Lacze.Inicjalizuj();  // Start gnuplot.
            
            Lacze.ZmienTrybRys(PzG::TR_2D);
            Matrix2x2 m1(Vector2D(coss,-sinn), Vector2D(sinn,coss));
            std::ofstream data;
            while(std::cin.get() != '\n') continue;
        
        do{
            
            data.open("../data/vertex.xy", std::ios::trunc); // overwrite mode

                if (data.is_open()){
                    if(actual_num_of_rotatations!=0){
                        rec1 = rec1.Rotate(m1);
                    } 
                    data << rec1;
                }
                Lacze.Rysuj();
                data.close();
            
            
            std::this_thread::sleep_for(std::chrono::seconds(2));
            actual_num_of_rotatations++;
        }while (actual_num_of_rotatations < num_of_rotations);
        
        }else{
        while(std::cin.get() != '\n') continue;
        throw std::invalid_argument("Wrong data type (angle)");
        return 0;
        }
        
        
    }else{
        while(std::cin.get() != '\n') continue;
        throw std::invalid_argument("Wrong data type (number of rotations)");
        return 0;
    }
    
}

Rectangle argErrorHandling(int argc, char **argv){
    if(argc < 4){
        throw std::invalid_argument("Additional argument required");
    } 
    double x1, x2, y1, y2;
    x1 = atof(argv[0]);
    y1 = atof(argv[1]);
    x2 = atof(argv[2]);
    y2 = atof(argv[3]);
    Vector2D vec1 = Vector2D(x1, y1);
    Vector2D vec2 = Vector2D(x2, y2);
    Rectangle rec1 = Rectangle(vec1, vec2);

    return rec1;
}