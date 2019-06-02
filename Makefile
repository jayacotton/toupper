toupper: main.c
	zcc +cpm -O3 -vn -s -m --list -c main.c
	zcc +cpm -create-app -otoupper main.o

clean:
	rm *.o *.err *.lis *.def *.sym *.exe *.COM macro

install:
	sudo cp ./*.COM /var/www/html/.

