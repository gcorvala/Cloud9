set (INCS
	bits.h
	common.h
	decode.h
	dwg.h
	dwg.spec
	encode.h
	logging.h
	print.h
	)

set (SRCS
	bits.c
	common.c
	decode.c
	decode_r2007.c
	dwg.c
	encode.c
	print.c
	)

include_directories (.)

add_library (libredwg SHARED ${INCS} ${SRCS})