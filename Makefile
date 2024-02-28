findPath := C:/msys64/usr/bin/find
testFiles := $(shell $(findPath) test/ -name '*.cpp')
engineFiles := $(shell $(findPath) src/ -name '*.cpp') $(shell $(findPath) src/ -name '*.c')
engineHeaders := $(shell $(findPath) src/ -name '*.hpp')
flags := -Iinclude -Llib -Wall
testFlags := 
objectFlags := -lGL -lX11 -lpthread -lXrandr -lXi -ldl
dllFlags := -lglfw3dll
testOutput = main.exe
buildOutput = factory-engine.dll

# compile and run test only
.SILENT:
test: $(testFiles) $(engineFiles)
	rm -f $(testOutput)
	g++ $(testFiles) $(buildOutput) $(flags) $(testFlags) -o $(testOutput)
	make run -s

# re-run precompiled test
.SILENT:
run: $(testOutput)
	./$(testOutput)

# compile dll only
.SILENT:
build: $(engineFiles)
	mkdir -p temp
	rm -f temp/*
	rm -f $(buildOutput)
	g++ -c $(engineFiles) $(flags) $(objectFlags) -DBUILD_LIB
	mv *.o temp
	g++ -shared -o $(buildOutput) temp/*.o $(flags) $(dllFlags)
	rm -rf temp

# compile and run dll and test
.SILENT:
full:
	make build -s
	make test -s

# move files to release folder
.SILENT:
release: 
	make build -s
	rm -rf release
	mkdir -p release/bin
	cp factory-engine.dll release/bin/factory-engine.dll
	cp glfw3.dll release/bin/glfw3.dll
	cp -r include release/include
	$(findPath) src/ -type f -name "*.hpp" -exec cp --parents {} release/include \;
	mv release/include/src release/include/factoryengine
	7z a factory-engine.zip ./release/*
	rm -rf release