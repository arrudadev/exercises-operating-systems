## EP 2

Dado um arquivo com 512 bytes, caso este represente uma MBR, seu programa deverá gerar uma saída equivalente àquela do comando fdisk.

### Comandos Linux úteis:

Lista os dispositivos de bloco:

```
lsblk
``` 

Gera o arquivo mbr.bin copiando os primeiros 512 bytes do dispositivo de bloco:

```
sudo dd if=/dev/sda of=mbr.bin bs=512 count=1
``` 

Lista a configuração das partições (este é o comando a ser usado como modelo):

```
sudo fdisk -l /dev/sda
```

lista, em hexadecimal, o conteúdo do arquivo mbr.bin:

```
hexdump mbr.bin
``` 