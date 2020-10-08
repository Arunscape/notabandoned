.PHONY: run build clean

run: build
	cd build;\
	./notabandoned


build:
	[ ! -d "build" ] && cmake -B build .;\
	make -C build
	
clean:
	rm -rf build
