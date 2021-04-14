Stworzyć folder lib <br>
W lib sklonować:<br>
git clone https://github.com/google/googletest.git<br>
potem w głównym folderze<br>
mkdir build && cd build<br>
cmake .. (tworzą się dwa makefile w folderze /build jest program i w folderze /build/tst jest program testujący)<br> 
W celu uruchomienia programu należy użyć komendy wewnątrz folderu /build<br>
./Rotation_run<br>
A w celu wywołania testów:<br>
./Rotation_tst<br>
wewnątrz folderu /build/tst
