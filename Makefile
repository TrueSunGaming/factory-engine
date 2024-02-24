findPath := C:/msys64/usr/bin/find
testFiles := $(shell $(findPath) test/ -name '*.cpp')
engineFiles := $(shell $(findPath) src/ -name '*.cpp') $(shell $(findPath) src/ -name '*.c')
flags := -Iinclude -Llib -lglfw3 -Wall
testOutput = main.exe
buildOutput = factory-engine.dll

test: $(testFiles) $(engineFiles)
	make build
	rm -f $(testOutput)
	g++ $(testFiles) $(buildOutput) $(flags) -o $(testOutput)
	make run -s

run: $(testOutput)
	./$(testOutput)

build: $(engineFiles)
	mkdir -p temp
	rm -f temp/*
	rm -f $(buildOutput)
	g++ -c $(engineFiles) $(flags) -DBUILD_LIB
	mv *.o temp
	g++ -shared -o $(buildOutput) temp/*.o
	rm -rf temp

