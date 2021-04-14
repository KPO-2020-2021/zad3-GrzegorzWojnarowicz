Stworzyć folder lib
W lib sklonować:
git clone https://github.com/google/googletest.git
potem w głównym folderze
mkdir build && cd build
cmake .. (tworzą się dwa makefile w folderze /build to jest program i w folderze /build/tst jest program testujący) w celu uruchomienia programu należy użyć komendy
./Rotation_run easy lub ./complex_run hard
w zależności od pożądanego poziomu trudności testu w celu uruchomienia testów należy użyć komendy
./Rotation_tst
wewnątrz folderu /build/tst
