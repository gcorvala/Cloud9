include (../../cmake/UseLATEX.cmake)

set (FRONT_MATTER_INCS
	frontmatter/dedication.tex
	frontmatter/quotation.tex
	frontmatter/thanks.tex
	)

set (CHAPTERS_INCS
	chapters/background.tex
	chapters/conception.tex
	chapters/conclusion.tex
	chapters/introduction.tex
	chapters/methodology.tex
	chapters/stateoftheart.tex
	)

set (INCS
	titlepage.tex
	${FRONT_MATTER_INCS}
	${CHAPTERS_INCS}
	)

add_latex_document (
	report.tex 
	INPUTS ${INCS}
	DEFAULT_PDF
	USE_INDEX
	BIBFILES bibliography.bib
	)