OTT=ott
OTT_FLAGS=-show_sort false -showraw false -show_defns false -tex_show_meta false -tex_wrap false -signal_parse_errors true

OTT_FILE=calc.ott
OTT_INCLUDED_FILE=calc_included.tex
OTT_OVERRIDE_FILE=calc_override.tex

FORMAL=formal.tex

all:
	$(OTT) $(OTT_FLAGS) -merge true $(OTT_FILE) -o $(OTT_INCLUDED_FILE) -tex_filter formal.mng formal.tex
	#hack: can't figure out why it doesn't work for me without this
	perl -pe 's|(\\mathit\{.*?\})|\\ensuremath{\1}|g' $(OTT_INCLUDED_FILE) &> __tmp.tex
	cp __tmp.tex $(OTT_INCLUDED_FILE)
	#$(OTT) $(OTT_FLAGS)  empty.ott
	pdflatex -interaction=nonstopmode $(FORMAL)

clean:
	rm -f *.aux *.log __tmp.tex $(OTT_INCLUDED_FILE) $(OTT_OVERRIDE_FILE)
