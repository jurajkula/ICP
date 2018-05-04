 #
 # Projekt ICP
 # Subor: Makefile
 # Autori: 
 #		Kula Juraj <xkulaj02>
 #		Michal Vaško <xvasko14>
 #
 NAME=xkulaj02-xvasko14

all: qmake_run

qmake_run:
	cd ./build && qmake ../ProjektICP.pro
	cd ./build && make -j8

clean:
	rm -rf ./bin/*
	rm -rf ./build/*
	rm -rf ./doc/*

pack: clean
	zip -r ${NAME}.zip ./*

run: qmake_run
	cd ./bin && ./ProjektICP

doxygen:
	doxygen doxconf