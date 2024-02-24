testFiles := test/*.cpp
engineFiles := src/math/*.cpp
flags := -Iinclude -Llib -lglfw3 -Wall
testOutput = main.exe
buildOutput = factory-engine.dll

test: $(testFiles) $(engineFiles)
	make build -s
	rm -f $(testOutput)
	g++ $(testFiles) $(flags) factory-engine.dll -o $(testOutput)
	./$(testOutput)

run: $(testOutput)
	./$(testOutput)

build: $(engineFiles)
	rm -f temp/*
	-rmdir temp
	-mkdir temp
	g++ -c $(engineFiles) $(flags) -o temp/out.o -DBUILD_LIB
	g++ -shared -o $(buildOutput) temp/out.o
	rm -f temp/*
	rmdir temp