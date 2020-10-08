
run: build
	cd build;\
	./notabandoned


build:
	[ ! -d "build" ] && cmake -B build .;\
	make -C build
	
