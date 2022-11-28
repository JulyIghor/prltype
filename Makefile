LDFLAGS=-L/Library/Frameworks/ParallelsVirtualizationSDK.framework/Libraries -lprl_sdk
PREFIX=.
CXX=clang++

CXXFLAGS=-O3 -g -I./src -I/Library/Frameworks/ParallelsVirtualizationSDK.framework/Headers -std=c++14

main: main.o prltype.o
	rm -f $(PREFIX)/bin/prltype
	$(CXX) $(LDFLAGS) -o $(PREFIX)/bin/prltype_arm64 out/main_arm64.o out/prltype_arm64.o -target arm64-apple-macos11
	$(CXX) $(LDFLAGS) -o $(PREFIX)/bin/prltype_x86 out/main_x86.o out/prltype_x86.o -target x86_64-apple-macos10.12
	lipo -create -output $(PREFIX)/bin/prltype $(PREFIX)/bin/prltype_x86 $(PREFIX)/bin/prltype_arm64
	install_name_tool -change $(shell find /Library/Frameworks/ParallelsVirtualizationSDK.framework/Versions -type d -maxdepth 1 -mindepth 1)/ParallelsVirtualizationSDK /Library/Frameworks/ParallelsVirtualizationSDK.framework/Versions/Current/ParallelsVirtualizationSDK $(PREFIX)/bin/prltype
	strip $(PREFIX)/bin/prltype
	chmod 555 $(PREFIX)/bin/prltype
	rm -rf out $(PREFIX)/bin/prltype_x86 $(PREFIX)/bin/prltype_arm64

main.o: setup
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o out/main_arm64.o -target arm64-apple-macos11
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o out/main_x86.o -target x86_64-apple-macos10.12

prltype.o: setup
	$(CXX) $(CXXFLAGS) -c src/prltype.cpp -o out/prltype_arm64.o -target arm64-apple-macos11
	$(CXX) $(CXXFLAGS) -c src/prltype.cpp -o out/prltype_x86.o -target x86_64-apple-macos10.12

setup:
	mkdir -p $(PREFIX)/bin
	mkdir -p out

clean:
	rm -f $(PREFIX)/bin/prltype
