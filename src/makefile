
slm: main.o LanguageModel.o TextGenerator.o
	g++ main.o LanguageModel.o TextGenerator.o -o slm

main.o: main.cpp
	g++ -c main.cpp -o main.o

LanguageModel.o: LanguageModel.cpp LanguageModel.h
	g++ -c LanguageModel.cpp -o LanguageModel.o

TextGenerator.o: TextGenerator.cpp TextGenerator.h
	g++ -c TextGenerator.cpp -o TextGenerator.o

clean:
	rm *.o slm