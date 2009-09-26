SRCS = $(wildcard *.tex) $(wildcard algoritmos/*.cpp) $(wildcard misc/*)

all: pdf

pdf: notes.tex algoritmos/pontoart.cpp
	pdflatex notes.tex
	pdflatex notes.tex
	pdflatex notes.tex

clean:
	rm *.{aux,log,pdf,toc,out}
