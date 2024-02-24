findPath := C:/msys64/usr/bin/find
testFiles := $(shell $(findPath) test/ -name '*.cpp')
engineFiles := $(shell $(findPath) src/ -name '*.cpp')
flags := -Iinclude -Llib -lglfw3 -Wall
testOutput = main.exe
buildIntermediateOutput = factory-engine.o
buildOutput = factory-engine.dll

test: $(testFiles) $(engineFiles)
	make build
	rm -f $(testOutput)
	g++ $(testFiles) $(buildOutput) $(flags) -o $(testOutput)
	make run -s

run: $(testOutput)
	./$(testOutput)

build: $(engineFiles)
	rm -f $(buildIntermediateOutput)
	rm -f $(buildOutput)
	g++ -c $(engineFiles) $(flags) -o $(buildIntermediateOutput) -DBUILD_LIB
	g++ -shared -o $(buildOutput) $(buildIntermediateOutput)

