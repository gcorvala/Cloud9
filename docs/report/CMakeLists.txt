include (../../cmake/UseLATEX.cmake)

set (FRONT_MATTER_INCS
	frontmatter/dedication.tex
	frontmatter/quotation.tex
	frontmatter/thanks.tex
	)

set (BACKGROUND_INCS
	chapters/background/main.tex
	chapters/background/sampling.tex
	)

set (CHAPTERS_INCS
	${BACKGROUND_INCS}
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

set (FIGURES
	figures/hierarchical_clustering.png
	figures/incremental_clustering.png
	)

add_latex_document (
	report.tex 
	INPUTS ${INCS}
	IMAGES ${FIGURES}
	DEFAULT_SAFEPDF
#	DEFAULT_PDF
	USE_INDEX
	BIBFILES bibliography.bib
	)