 #
 # Projekt ICP
 # Subor: Makefile
 # Autori: 
 #		Kula Juraj <xkulaj02>
 #		Michal Vaško <xvaskoXX>
 #
 NAME=xkulaj02-xvaskoXX

qmake_run:
	cd ./build && qmake ../ProjektICP.pro
	cd ./build && make -j15

clean:
	rm -rf ./bin/
	rm -rf ./build/
	rm -rf ./doc/
	mkdir bin
	mkdir build
	mkdir doc

pack: clean
	zip -r ${NAME}.zip ./*

run: qmake_run
	./bin/ProjektICP

doxygen:
	doxygen doxconf