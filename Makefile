all: os00/os00.pdf os01/os01.pdf os02/os02.pdf os03/os03.pdf os04/os04.pdf os05/os05.pdf os06/os06.pdf os07/os07.pdf os08/os08.pdf os06-new/os06-new.pdf

%.pdf: %.tex
	if [ -n "$(dir $<)" ]; then echo $(dir $<); cd $(dir $<); fi; pdflatex $(notdir $<); cd -

clean:
	for dir in os0[0-8]/; do echo $$dir; cd $$dir; rm -fv *.log *.aux *.pdf *.nav *.out *.snm *.toc; cd -; done;
