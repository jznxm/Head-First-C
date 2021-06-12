elliptical.o: elliptical.c
	gcc -c  elliptical.c -I/mnt/f/OneDrive/Code/Head-First-C/chapter_8/hfgym/includes -o elliptical.o

hfcal_uk.o: hfcal_UK.c
	gcc -c -fPIC hfcal_UK.c -I/mnt/f/OneDrive/Code/Head-First-C/chapter_8/hfgym/includes -o hfcal_uk.o

hfcal.o: hfcal.c
	gcc -c -fPIC hfcal.c -I/mnt/f/OneDrive/Code/Head-First-C/chapter_8/hfgym/includes -o hfcal.o

libhfcal.so: hfcal_uk.o
	gcc -shared hfcal_uk.o -o /usr/lib/libhfcal.so 

elliptical: libhfcal.so elliptical.o
	gcc -o elliptical.out elliptical.o -L/usr/lib -lhfcal
