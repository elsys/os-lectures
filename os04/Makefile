CODE:=$(wildcard code/*.cpp) $(wildcard code/*.hpp) $(wildcard code/*.cc) \
	$(wildcard examples/*.cpp) $(wildcard examples/*.hpp) \
	$(wildcard examples-03/*.cpp) $(wildcard examples-03/*.hpp) \
	$(wildcard examples-04/*.cpp) $(wildcard examples-04/*.hpp) \
	$(wildcard additionals-06/*) $(wildcard additionals-07/*) $(wildcard additionals-08/*)

FIGS:=$(wildcard figs/*.eps)
BIBS:=$(wildcard *.bib) $(wildcard *.bbl)

.PHONY: all clean

%.tex: %.w
	cweave $<

%.ps: %.dvi
	dvips -o $@ $< 


%.beamer.dvi: %.beamer.tex %.tex $(CODE) $(FIGS) $(BIBS) notes.tex
	./tex-it latex $<
%.simple.dvi: %.simple.tex %.tex $(CODE) $(FIGS) $(BIBS) notes.tex
	./tex-it latex $<
%.handout.dvi: %.handout.tex %.tex $(CODE) $(FIGS) $(BIBS) notes.tex
	./tex-it latex $<


%.dvi: %.tex $(CODE) $(FIGS) $(BIBS) notes.tex
	./tex-it latex $<

#%.x2.ps: %.ps Makefile
#	pstops "2:0R@.9(-2.5cm,30.5cm)+1R@.9(-2.5cm,16.5cm)" $< $@
#%.x2.print.ps: %.ps Makefile
#	pstops -pa4 "4:0L@0.88(1.04w,-0.02h)+1L@0.88(1.04w,0.42h),2R@0.88(-0.07w,1.07h)+3R@0.88(-0.07w,0.6h)" $< $@

%.x2.ps: %.ps
	pstops "2:0R@.7(0cm,29.7cm)+1R@.7(0cm,16cm)" $< $@

%.x4.ps: %.ps Makefile
	pstops "4:0@.450(.5cm,5cm)+1@.450(6.5cm,5cm)+2@.450(.5cm,.5cm)+3@.450(6.5cm,.5cm)" $< $@

%.pdf: %.ps
	ps2pdf $<






all: #inheritance.ps virtual.ps exceptions.ps templates.ps streams.ps


lecture07-example01.ps: lecture07-example01.dvi
	dvips  lecture07-example01.dvi

lecture07-example01.dvi: lecture07-example01.tex booknotes.tex $(CODE) $(FIGS)
	latex lecture07-example01.tex
	latex lecture07-example01.tex



lecture01-01.ps: lecture01-01.dvi

lecture01-01-x2.ps: lecture01-01.ps Makefile
	pstops "2:0R@.7(0cm,29.7cm)+1R@.7(0cm,16cm)" lecture01-01.ps lecture01-01-x2.ps
lecture01-01-x4.ps: lecture01-01.ps Makefile
	pstops "4:0@.50(0cm,-1cm)+1@.50(9cm,-1cm)+2@.50(0cm,13cm)+3@.50(9cm,13cm)" lecture01-01.ps lecture01-01-x4.ps

lecture01-01.dvi: lecture01-01.tex notes.tex $(CODE) $(FIGS)
	latex lecture01-01.tex
	latex lecture01-01.tex




lecture01.ps: lecture01.dvi
	dvips -t landscape lecture01.dvi


lecture01-x2.ps: lecture01.ps Makefile
	pstops "2:0R@.7(0cm,29.7cm)+1R@.7(0cm,16cm)" lecture01.ps lecture01-x2.ps
lecture01-x4.ps: lecture01.ps Makefile
	pstops "4:0@.50(0cm,-1cm)+1@.50(9cm,-1cm)+2@.50(0cm,13cm)+3@.50(9cm,13cm)" lecture01.ps lecture01-x4.ps


lecture01.dvi: lecture01.tex notes.tex $(CODE) $(FIGS)
	latex lecture01.tex
	latex lecture01.tex




lecture02.ps: lecture02.dvi
	dvips -t landscape lecture02.dvi

lecture02.dvi: lecture02.tex notes.tex $(CODE) $(FIGS)
	latex lecture02.tex
	latex lecture02.tex


classes-01.ps: classes-01.dvi
	dvips classes-01.dvi

classes-01.dvi: classes-01.tex booknotes.tex $(CODE) $(FIGS)
	latex classes-01.tex


inheritance.ps: inheritance.dvi
	dvips -t landscape inheritance.dvi

inheritance.dvi: inheritance.tex notes.tex $(CODE) $(FIGS)
	latex inheritance.tex



virtual.ps: virtual.dvi
	dvips -t landscape virtual.dvi

virtual.dvi: virtual.tex $(CODE) $(FIGS)
	latex virtual.tex
	latex virtual.tex

virtual.pdf: virtual.ps
	ps2pdf virtual.ps



exceptions.ps: exceptions.dvi
	dvips -t landscape exceptions.dvi

exceptions.dvi: exceptions.tex $(CODE) $(FIGS)
	latex exceptions.tex
	latex exceptions.tex

exceptions.pdf: exceptions.ps
	ps2pdf exceptions.ps



templates.ps: templates.dvi
	dvips -t landscape templates.dvi

templates.dvi: templates.tex $(CODE) $(FIGS)
	latex templates.tex
	latex templates.tex

templates.pdf: templates.ps
	ps2pdf templates.ps


streams.ps: streams.dvi
	dvips -t landscape streams.dvi

streams.dvi: streams.tex $(CODE) $(FIGS)
	latex streams.tex
	latex streams.tex

streams.pdf: streams.ps
	ps2pdf streams.ps



streams2.ps: streams2.dvi
	dvips -t landscape streams2.dvi

streams2.dvi: streams2.tex $(CODE) $(FIGS)
	latex streams2.tex
	latex streams2.tex

streams2.pdf: streams2.ps
	ps2pdf streams2.ps



clean:
	rm -rf *~ *.aux *.log *.bak
	rm -rf code/*~ figs/*~
	rm -rf *.pdf *.ps *.dvi *.ps.gz
	rm -rf a.out code/a.out *.o code/*.o 
	rm -rf semantic.cache *.nav *.out *.snm *.toc
	rm -f code/semantic.cache