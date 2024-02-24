testFiles := test/*.cpp
engineFiles := src/*.cpp
flags := -Iinclude -Llib -lglfw3
testOutput = main.exe
buildOutput = factory-engine.dll

test: $(testFiles) $(engineFiles)
	make build
	rm -f $(testOutput)
	g++ $(testFiles) $(flags) factory-engine.dll -o $(testOutput)
	./$(testOutput)

run: $(testOutput)
	./$(testOutput)

build: $(engineFiles)
	rm -f temp/*
	@mkdir temp
	g++ -c $(engineFiles) $(flags) -o temp/out.o
	g++ -shared -o $(buildOutput) temp/out.o
	rm -f temp/*
	rmdir temp