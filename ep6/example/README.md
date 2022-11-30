- Para criar biblioteca
  gcc -fPIC -shared triplo.c -o libtriplo.c

- Para publicar a biblioteca
  sudo cp libtriplo.c /usr/local/lib

- Para informar o sistema sobre a localização da biblioteca
  sudo nano /etc/ld.so.conf.d/libtriplo.conf
  (coloque dentro deste arquivo apenas /usr/local/lib)

- Execute o ldconfig
  sudo ldconfig

- Para testar
  python main.py
