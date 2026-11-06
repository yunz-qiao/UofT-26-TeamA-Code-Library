LATEXCMD = pdflatex -shell-escape -output-directory build/
FLAGFILE = build/.flag
export TEXINPUTS=.:content/tex/:
export max_print_line = 1048576
# hash.sh needs GNU cpp (Apple's cpp is clang). On macOS, shim cpp -> Homebrew cpp-NN
export PATH := $(CURDIR)/build/bin:$(PATH)

help:
	@echo "This makefile builds KACTL (KTH Algorithm Competition Template Library)"
	@echo ""
	@echo "Available commands are:"
	@echo "	make fast		- to build KACTL, quickly (only runs LaTeX once)"
	@echo "	make kactl		- to build KACTL"
	@echo "	make clean		- to clean up the build process"
	@echo "	make veryclean		- to clean up and remove kactl.pdf"
	@echo "	make test		- to run all the stress tests in stress-tests/"
	@echo "	make test-compiles	- to test compiling all headers"
	@echo "	make help		- to show this information"
	@echo "	make showexcluded	- to show files that are not included in the doc"
	@echo ""
	@echo "For more information see the file 'doc/README'"

fast: | build gnucpp $(FLAGFILE)
	$(LATEXCMD) content/kactl.tex </dev/null
	cp build/kactl.pdf kactl.pdf

kactl: test-session.pdf | build gnucpp $(FLAGFILE)
	$(LATEXCMD) content/kactl.tex && $(LATEXCMD) content/kactl.tex
	cp build/kactl.pdf kactl.pdf

clean:
	cd build && rm -f kactl.aux kactl.log kactl.tmp kactl.toc kactl.pdf kactl.ptc

veryclean: clean
	rm -f kactl.pdf test-session.pdf

.PHONY: help fast kactl clean veryclean gnucpp

gnucpp: | build
	@mkdir -p build/bin
	@if cpp --version 2>/dev/null | grep -qi clang; then \
	  for c in cpp-15 cpp-14 cpp-13 cpp-12 cpp-11; do \
	    if command -v $$c >/dev/null; then ln -sf "$$(command -v $$c)" build/bin/cpp; break; fi; \
	  done; \
	fi

$(FLAGFILE): build
	rm -f build/kactl.* build/test-session.* && touch $(FLAGFILE)

build:
	mkdir -p build/

test:
	./doc/scripts/run-all.sh .

test-compiles:
	./doc/scripts/compile-all.sh .

test-session.pdf: content/test-session/test-session.tex content/test-session/chapter.tex | build $(FLAGFILE)
	$(LATEXCMD) content/test-session/test-session.tex
	cp build/test-session.pdf test-session.pdf

showexcluded: build
	grep -RoPh '^\s*\\kactlimport{\K.*' content/ | sed 's/.$$//' > build/headers_included
	find ./content -name "*.h" -o -name "*.py" -o -name "*.java" | grep -vFf build/headers_included
